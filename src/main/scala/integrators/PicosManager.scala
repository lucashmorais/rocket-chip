package freechips.rocketchip.integrators
//package freechips.rocketchip.util.ShiftQueue

import Chisel._
import freechips.rocketchip.chip.QuadCoreConfig
import freechips.rocketchip.config.Parameters
import freechips.rocketchip.util.InOrderArbiter
import freechips.rocketchip.diplomacy._

class ManagerIO(nCores: Int)(implicit p: Parameters) extends Bundle {
  val subQInterface       = Flipped(Vec(nCores, Decoupled(UInt(64.W))))
  val readyQInterface     = Vec(nCores, Decoupled(UInt(64.W)))
}

//TODO: Let it take several differents traits, following
//      RC conventions!
class PicosManager(nCores: Int, qDepth: Int = 16)(implicit p: Parameters) extends LazyModule {
  lazy val module = new LazyModuleImp(this) {
    val io = new ManagerIO(nCores)

    /*
    val subQueues = Vec(Seq.fill(nCores){ Module(new Queue(Bits(width = 64), qDepth)).io })
    val readyQueues = Vec(Seq.fill(nCores){ Module(new Queue(Bits(width = 64), qDepth)).io })

    for (i <- 0 until nCores) {
      subQueues(i).enq <> io.subQInterface(i)
      readyQueues(i).enq <> subQueues(i).deq
      io.readyQInterface(i) <> readyQueues(i).deq
    }
    */

    val subQueue = Module( new Queue(Bits(width = 64), nCores) )
    val arbiter = Module(new InOrderArbiter(UInt(64.W), UInt(64.W), nCores))

    arbiter.io.in_req <> io.subQInterface
    io.readyQInterface <> arbiter.io.in_resp
    subQueue.io.enq <> arbiter.io.out_req
    arbiter.io.out_resp <> subQueue.io.deq
  }
}

/*
abstract class PassthroughCore(implicit p: SynthesisContext) extends PicosManagerInterface {
  val subQueues = Vec(Seq.fill(p.nCores){ Module(new Queue(Bits(width = p.queueWidth), p.n)).io })
  val readyQueues = Vec(Seq.fill(p.nCores){ Module(new Queue(Bits(width = p.queueWidth), p.n)).io })

  for (i <- 0 until p.nCores) {
    subQueues(i).enq <> io.subQInterface(i)

    readyQueues(i).enq <> subQueues(i).deq

    io.readyQInterface(i) <> readyQueues(i).deq
  }
}

abstract class SingleQueuePassthroughCore(implicit p: SynthesisContext) extends PicosManagerInterface {
  val subQueue = Module( new Queue(Bits(width = p.queueWidth), p.n) )

  //TODO Refactor
  implicit val config = new QuadCoreConfig
  val arbiter = Module(new InOrderArbiter(UInt(p.queueWidth.W), UInt(p.queueWidth.W), p.n))

  arbiter.io.in_req <> io.subQInterface
  io.readyQInterface <> arbiter.io.in_resp
  subQueue.io.enq <> arbiter.io.out_req
  arbiter.io.out_resp <> subQueue.io.deq
}
*/

object PicosManagerDriver extends App {
}
