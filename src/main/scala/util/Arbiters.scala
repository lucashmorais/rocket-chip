// See LICENSE.Berkeley for license details.

package freechips.rocketchip.util

import Chisel._
import freechips.rocketchip.config.Parameters

/** A generalized locking RR arbiter that addresses the limitations of the
 *  version in the Chisel standard library */
abstract class HellaLockingArbiter[T <: Data](typ: T, arbN: Int, rr: Boolean = false)
    extends Module {

  val io = new Bundle {
    val in = Vec(arbN, Decoupled(typ.cloneType)).flip
    val out = Decoupled(typ.cloneType)
  }

  def rotateLeft[T <: Data](norm: Vec[T], rot: UInt): Vec[T] = {
    val n = norm.size
    Vec.tabulate(n) { i =>
      Mux(rot < UInt(n - i), norm(UInt(i) + rot), norm(rot - UInt(n - i)))
    }
  }

  val lockIdx = Reg(init = UInt(0, log2Up(arbN)))
  val locked = Reg(init = Bool(false))

  val choice = if (rr) {
    PriorityMux(
      rotateLeft(Vec(io.in.map(_.valid)), lockIdx + UInt(1)),
      rotateLeft(Vec((0 until arbN).map(UInt(_))), lockIdx + UInt(1)))
  } else {
    PriorityEncoder(io.in.map(_.valid))
  }

  val chosen = Mux(locked, lockIdx, choice)

  for (i <- 0 until arbN) {
    io.in(i).ready := io.out.ready && chosen === UInt(i)
  }

  io.out.valid := io.in(chosen).valid
  io.out.bits := io.in(chosen).bits
}

/** This locking arbiter determines when it is safe to unlock
 *  by peeking at the data */
class HellaPeekingArbiter[T <: Data](
      typ: T, arbN: Int,
      canUnlock: T => Bool,
      needsLock: Option[T => Bool] = None,
      rr: Boolean = false)
    extends HellaLockingArbiter(typ, arbN, rr) {

  def realNeedsLock(data: T): Bool =
    needsLock.map(_(data)).getOrElse(Bool(true))

  when (io.out.fire()) {
    when (!locked && realNeedsLock(io.out.bits)) {
      lockIdx := choice
      locked := Bool(true)
    }
    // the unlock statement takes precedent
    when (canUnlock(io.out.bits)) {
      locked := Bool(false)
    }
  }
}

/** This arbiter determines when it is safe to unlock by counting transactions */
class HellaCountingArbiter[T <: Data](
      typ: T, arbN: Int, count: Int,
      val needsLock: Option[T => Bool] = None,
      rr: Boolean = false)
    extends HellaLockingArbiter(typ, arbN, rr) {

  def realNeedsLock(data: T): Bool =
    needsLock.map(_(data)).getOrElse(Bool(true))

  // if count is 1, you should use a non-locking arbiter
  require(count > 1, "CountingArbiter cannot have count <= 1")

  val lock_ctr = Counter(count)

  when (io.out.fire()) {
    when (!locked && realNeedsLock(io.out.bits)) {
      lockIdx := choice
      locked := Bool(true)
      lock_ctr.inc()
    }

    when (locked) {
      when (lock_ctr.inc()) { locked := Bool(false) }
    }
  }
}

/** This arbiter preserves the order of responses */
// If "T" complies with "T <: Data", then "T" is a subtype of "Data".
// In fact, "T" could be "Data" itself.
class InOrderArbiter[T <: Data, U <: Data](reqTyp: T, respTyp: U, n: Int)
    (implicit p: Parameters) extends Module {
  // The bundle is created without an IO wrapper here
  val io = new Bundle {
    /*
     * In the following four statements, the apply method of the Decoupled
     * object is used for generating a DecoupledIO chisel type from chisel
     * types reqTyp and respTyp.
     *
     * The flipped signals are "OUT->IN".
     */

    // Decoupled interface for receiving from the producers data requests
    // that should be forwarded to the consumer
    // (producers) OUT->IN
    val in_req = Vec(n, Decoupled(reqTyp)).flip

    // Decoupled interface that forwards to the producers data request 
    // answers coming from the consumer
    // IN->OUT (producers)
    val in_resp = Vec(n, Decoupled(respTyp))

    // Decoupled interface that forwards to the consumer data requests
    // coming from the producers
    // IN->OUT (consumer)
    val out_req = Decoupled(reqTyp)

    // Decoupled interface for receiving from the consumer data request
    // answers that should be forwarded to the producers
    // (consumer) OUT->IN
    val out_resp = Decoupled(respTyp).flip
  }

  // If there is more than one producer, we should arbitrate communication
  // between the consumer and them.
  if (n > 1) {
    // Queue that keeps the sequence of indexes of producers allowed
    // to access the shared bus.
    val route_q = Module(new Queue(UInt(width = log2Up(n)), 2))

    // Instantiates a simple round-robin arbiter for 'n' producers
    val req_arb = Module(new RRArbiter(reqTyp, n))

    // This makes io.in_req a passthrough to req_arb.io.in
    req_arb.io.in <> io.in_req

    // Prepares an AND-reduce helper involving three signals
    val req_helper = DecoupledHelper(
      req_arb.io.out.valid,       // Is the data coming from the inner arbiter valid?
      route_q.io.enq.ready,       // Is the routing queue ready to receive data?
      io.out_req.ready)           // Is the guy getting data from outside ready
                                  // to receive more data requests?

    /*
     * The io.out_req (IN->OUT) DecoupledIO vec is merely a passthrough that lets the
     * RRArbiter to send data requests to the outside.
     */

    // Let io.out_req.bits mirror req_arb.io.out.bits
    io.out_req.bits := req_arb.io.out.bits

    // Data describing data requests being forward to the shared bus is only valid when
    // req_arb.io.out.valid && route_q.io.enq.ready, that is, when the data coming from
    // the inner RRArbiter is valid and the routing queue is ready to receive data.
    io.out_req.valid := req_helper.fire(io.out_req.ready)

    // This enqueues the index of the chosen agent into the routing queue 
    route_q.io.enq.bits := req_arb.io.chosen

    // Data being written to the routing queue is only valid if req_arb.io.out.valid &&
    // io.out_req.ready, that is, if the inner RRArbiter has valid data to be read from
    // it and if the outside agent is ready to receive that data.
    route_q.io.enq.valid := req_helper.fire(route_q.io.enq.ready)

    // We are ready to receive data from the inner RRArbiter if route_q.io.enq.ready &&
    // io.out_req.ready, that is, if the routing queue is ready to receive data about
    // the agent allowed to access the bus and the outside agent connected to the shared
    // bus is able to receive a packet describing a data request.
    req_arb.io.out.ready := req_helper.fire(req_arb.io.out.valid)

    // Get the index of the producer that should be the next to receive an answer to its
    // data request from the consumer.
    val resp_sel = route_q.io.deq.bits

    // This tells whether the next producer to receive a data request answer from the
    // consumer is ready for it.
    val resp_ready = io.in_resp(resp_sel).ready

    // Prepares an AND-reduce helper involving three signals
    val resp_helper = DecoupledHelper(
      resp_ready,             // Is the producer ready to receive a data request answer from consumer?
      route_q.io.deq.valid,   // Is the index of the next producer to have a data request answered valid?
      io.out_resp.valid)      // Is the data request answer coming from the consumer valid?

    // The data request answer coming from the producer is valid if
    // route_q.io.deq.valid && io.out_resp.valid, that is, if (1) the
    // next producer to receive a data request answer was selected
    // with the help of a valid producer index and (2) the data request
    // answer coming from the consumer is valid.
    val resp_valid = resp_helper.fire(resp_ready)

    for (i <- 0 until n) {
      // This lets the i-th producer receive data request answers from the consumer
      io.in_resp(i).bits := io.out_resp.bits

      // The data request answer is only valid for the i-th producer iff (1) it is
      // valid in absolute terms and (2) it is the i-th's producer turn to receive
      // a data request answer right now.
      io.in_resp(i).valid := resp_valid && resp_sel === UInt(i)
    }

    // The index for the next producer to receive a data request answer should only
    // be dequeued after that producer has successfully received such answer. That
    // being the case, it should only be dequeued iff resp_ready && io.out_resp.valid,
    // that is, (1) if the data request answer coming from the consumer was valid and
    // (2) the producer that had to receive that answer was ready for so.
    route_q.io.deq.ready := resp_helper.fire(route_q.io.deq.valid)

    // Data request answers coming from the consumer should only be allowed to pass
    // through the arbiter iff resp_ready && route_q.io.deq.valid, that is, (1) if
    // the answer coming from the consumer is valid and (2) the system was able to
    // retrieve from the routing queue a valid index for the next producer to receive
    // that answer.
    io.out_resp.ready := resp_helper.fire(io.out_resp.valid)
  }

  // Otherwise, the single producer and the single consumer can talk directly to
  // each other.
  else {
    io.out_req <> io.in_req.head
    io.in_resp.head <> io.out_resp
  }
}
