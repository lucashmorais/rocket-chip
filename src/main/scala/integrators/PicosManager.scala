package freechips.rocketchip.integrators
//package freechips.rocketchip.util.ShiftQueue

import Chisel._
import freechips.rocketchip.chip.QuadCoreConfig
import freechips.rocketchip.config.Parameters
import freechips.rocketchip.util.InOrderArbiter

class SynthesisContext(val queueWidth: Int = 32, val n: Int = 16, val nCores: Int = 4) {
}

class ManagerIO(implicit p: SynthesisContext) extends Bundle {
  val subQInterface       = Flipped(Vec(p.nCores, Decoupled(UInt(p.queueWidth.W))))
  val readyQInterface     = Vec(p.nCores, Decoupled(UInt(p.queueWidth.W)))
}

abstract class PicosManagerInterface(implicit p: SynthesisContext) extends Module {
  val io = new ManagerIO
}

abstract class PassthroughCore(implicit p: SynthesisContext) extends PicosManagerInterface {
  val subQueues = Vec(Seq.fill(p.nCores){ Module(new Queue(Bits(width = p.queueWidth), p.n)).io })
  val readyQueues = Vec(Seq.fill(p.nCores){ Module(new Queue(Bits(width = p.queueWidth), p.n)).io })

  for (i <- 0 until p.nCores) {
    subQueues(i).enq <> io.subQInterface(i)

    /*
    readyQueues(i).enq.valid := subQueues(i).deq.valid
    readyQueues(i).enq.bits := subQueues(i).deq.bits
    subQueues(i).deq.ready := readyQueues(i).enq.ready
    */

    readyQueues(i).enq <> subQueues(i).deq

    io.readyQInterface(i) <> readyQueues(i).deq
  }
}

abstract class SingleQueuePassthroughCore(implicit p: SynthesisContext) extends PicosManagerInterface {
  val subQueue = Module( new Queue(Bits(width = p.queueWidth), p.n) )

  //TODO Refactor
  implicit val config = new QuadCoreConfig
  val arbiter = Module(new InOrderArbiter(UInt(p.queueWidth.W), UInt(p.queueWidth.W), p.n))

  // Apply the following pattern:
  // [FEMALE] <> [MALE]

  arbiter.io.in_req <> io.subQInterface
  io.readyQInterface <> arbiter.io.in_resp
  subQueue.io.enq <> arbiter.io.out_req
  arbiter.io.out_resp <> subQueue.io.deq
}

class PicosManager(implicit p: SynthesisContext) extends {
} with SingleQueuePassthroughCore

import freechips.rocketchip.unittest._
class PicosManagerTest(txns: Int = 128, timeout: Int = 500000)(implicit p: Parameters) extends UnitTest(timeout) {
  implicit val sc = new SynthesisContext
  val dut = Module(new PicosManager)
  println("derp")
}

object PicosManagerDriver extends App {
  implicit val p = new SynthesisContext
  Driver.execute(args, () => new PicosManager)
}
