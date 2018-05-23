// See LICENSE.Berkeley for license details.
// See LICENSE.SiFive for license details.

package freechips.rocketchip.tile

import Chisel._

import freechips.rocketchip.config._
import freechips.rocketchip.coreplex._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.rocket._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.util.InOrderArbiter

case object RoccNPTWPorts extends Field[Int]
case object BuildRoCC extends Field[Seq[RoCCParams]]

case class RoCCParams(
  opcodes: OpcodeSet,
  generator: Parameters => LazyRoCC,
  nPTWPorts : Int = 0,
  useFPU: Boolean = false)

// Contains the RoCC instruction as a 32 bit word
// rs1, rs2 and rd refer to the register numbers
// included in the instruction word, NOT to the data
// that the corresponding registers carry.
class RoCCInstruction extends Bundle
{
  val funct = Bits(width = 7)
  val rs2 = Bits(width = 5)
  val rs1 = Bits(width = 5)
  val xd = Bool()
  val xs1 = Bool()
  val xs2 = Bool()
  val rd = Bits(width = 5)
  val opcode = Bits(width = 7)
}

// One can access the 'rs1' and 'rs2' fields of this class
// to obtain the data in the registers passed to the RoCC
// instruction.
class RoCCCommand(implicit p: Parameters) extends CoreBundle()(p) {
  val inst = new RoCCInstruction
  val rs1 = Bits(width = xLen)
  val rs2 = Bits(width = xLen)
  val status = new MStatus
}

// RoCC accelerators may write result data back to registers.
// The 'data' field of this class should receive the data to
// be written to the register indexed by 'rd'.
class RoCCResponse(implicit p: Parameters) extends CoreBundle()(p) {
  val rd = Bits(width = 5)
  val data = Bits(width = xLen)
}

// Class that defines the major IO capabilities of RoCC acc'rs
// cmd: RoCCComand field related to the request
// resp: RoCCResponse for sending data back to the register file
// mem: HellaCacheIO field for accessing main memory
// busy: Bool(OUTPUT) that tells the core that the accelerator is busy and thus
// not ready to receive more requests
// interrupt: Bool(OUTPUT) that makes the accelerator generate interrupts
// exception: Bool(INPUT) that makes the accelerator generate interrupts
class RoCCCoreIO(implicit p: Parameters) extends CoreBundle()(p) {
  // The flip method makes cmd be a MALE signal, it seems
  val cmd = Decoupled(new RoCCCommand).flip
  val resp = Decoupled(new RoCCResponse)
  val mem = new HellaCacheIO
  val busy = Bool(OUTPUT)
  val interrupt = Bool(OUTPUT)
  val exception = Bool(INPUT)

  //TODO: MAKE IT CLEANER AND BETTER FITTING
  //      TO THE REST OF THE PARAMETRIZABLE
  //      IO INFRASTRUCTURE
  //TODO: REFACTOR!
  val subQInterface = Decoupled(UInt(64.W))
  val readyQInterface = Flipped(Decoupled(UInt(64.W)))

  override def cloneType = new RoCCCoreIO()(p).asInstanceOf[this.type]
}

/** Base classes for Diplomatic TL2 RoCC units **/
abstract class LazyRoCC(implicit p: Parameters) extends LazyModule {
  val module: LazyRoCCModule
  var talksToPicos: Boolean = false

  val atlNode: TLMixedNode = TLOutputNode()
  val tlNode: TLMixedNode = TLOutputNode()
}

class RoCCIO(outer: LazyRoCC)(implicit p: Parameters) extends RoCCCoreIO()(p) {
  val atl = outer.atlNode.bundleOut
  val tl = outer.tlNode.bundleOut
  // Should be handled differently, eventually
  val ptw = Vec(p(RoccNPTWPorts), new TLBPTWIO)
  val fpu_req = Decoupled(new FPInput)
  val fpu_resp = Decoupled(new FPResult).flip
}

class LazyRoCCModule(outer: LazyRoCC) extends LazyModuleImp(outer) {
  val io = new RoCCIO(outer)
}

/** Mixins for including RoCC **/

trait HasLazyRoCC extends CanHaveSharedFPU with CanHavePTW with HasTileLinkMasterPort {
  implicit val p: Parameters
  val module: HasLazyRoCCModule

  val roccs = p(BuildRoCC).zipWithIndex.map { case (accelParams, i) =>
    accelParams.generator(p.alterPartial({
      case RoccNPTWPorts => accelParams.nPTWPorts
  }))}

  roccs.map(_.atlNode).foreach { atl => tileBus.node :=* atl }
  roccs.map(_.tlNode).foreach { tl => masterNode :=* tl }

  nPTWPorts += p(BuildRoCC).map(_.nPTWPorts).foldLeft(0)(_ + _)
  nDCachePorts += roccs.size
}

trait HasLazyRoCCModule extends CanHaveSharedFPUModule
  with CanHavePTWModule
  with HasCoreParameters
  with HasTileLinkMasterPortModule {
  val outer: HasLazyRoCC

  //This is the interface between the whole set of RoCC
  //accelerators and the core that holds them
  val roccCore = Wire(new RoCCCoreIO()(outer.p))

  val buildRocc = outer.p(BuildRoCC)
  val usingRocc = !buildRocc.isEmpty
  val nRocc = buildRocc.size
  val nFPUPorts = buildRocc.filter(_.useFPU).size
  val roccOpcodes = buildRocc.map(_.opcodes)

  if(usingRocc) {

    // Instantiate a round-robing arbiter for receiving
    // the output values from RoCC accelerators
    val respArb = Module(new RRArbiter(new RoCCResponse()(outer.p), nRocc))

    // This makes the core holding the RoCC accelerators
    // receive the response from the RRArbiter
    roccCore.resp <> respArb.io.out

    val cmdRouter = Module(new RoccCommandRouter(roccOpcodes)(outer.p))
    // This lets commands coming from the core holding the RoCC accelerator
    // go to the RoCCCommandRouter
    cmdRouter.io.in <> roccCore.cmd

    outer.roccs.zipWithIndex.foreach { case (rocc, i) =>
      ptwPorts ++= rocc.module.io.ptw

      // This connects the RoCCCommandRouter to each
      // of the available RoCC modules
      rocc.module.io.cmd <> cmdRouter.io.out(i)

      // This lets the RoCC modules receive exception
      // signals from the core
      rocc.module.io.exception := roccCore.exception

      // This lets RoCC modules access memory and cache
      val dcIF = Module(new SimpleHellaCacheIF()(outer.p))
      dcIF.io.requestor <> rocc.module.io.mem
      dcachePorts += dcIF.io.cache

      // This lets the current RoCC accelerator
      // connect to the arbiter at input port #i
      respArb.io.in(i) <> Queue(rocc.module.io.resp)
    }

    // If the RoCCCommandRouter or any of the modules are busy, then the RoCC core is busy
    roccCore.busy := cmdRouter.io.busy || outer.roccs.map(_.module.io.busy).reduce(_ || _)

    // If any of the RoCC modules generate an interrupt, the RoCC core gets an interrupt
    roccCore.interrupt := outer.roccs.map(_.module.io.interrupt).reduce(_ || _)

    fpuOpt foreach { fpu =>
      if (usingFPU && nFPUPorts > 0) {
        val fpArb = Module(new InOrderArbiter(new FPInput()(outer.p), new FPResult()(outer.p), nFPUPorts))
        val fp_rocc_ios = outer.roccs.zip(buildRocc)
          .filter { case (_, params) => params.useFPU }
          .map { case (rocc, _) => rocc.module.io }
        fpArb.io.in_req <> fp_rocc_ios.map(_.fpu_req)
        fp_rocc_ios.zip(fpArb.io.in_resp).foreach {
          case (rocc, arb) => rocc.fpu_resp <> arb
        }
        fpu.io.cp_req <> fpArb.io.out_req
        fpArb.io.out_resp <> fpu.io.cp_resp
      } else {
        fpu.io.cp_req.valid := Bool(false)
        fpu.io.cp_resp.ready := Bool(false)
      }
    }
  }
}

class  AccumulatorExample(implicit p: Parameters) extends LazyRoCC {
  override lazy val module = new AccumulatorExampleModule(this)
}

class AccumulatorExampleModule(outer: AccumulatorExample, n: Int = 4)(implicit p: Parameters) extends LazyRoCCModule(outer)
  with HasCoreParameters {
  val regfile = Mem(n, UInt(width = xLen))
  val busy = Reg(init = Vec.fill(n){Bool(false)})

  val cmd = Queue(io.cmd)
  val funct = cmd.bits.inst.funct
  val addr = cmd.bits.rs2(log2Up(n)-1,0)
  val doWrite = funct === UInt(0)
  val doRead = funct === UInt(1)
  val doLoad = funct === UInt(2)
  val doAccum = funct === UInt(3)
  val memRespTag = io.mem.resp.bits.tag(log2Up(n)-1,0)

  // datapath
  val addend = cmd.bits.rs1
  val accum = regfile(addr)
  val wdata = Mux(doWrite, addend, accum + addend)

  when (cmd.fire() && (doWrite || doAccum)) {
    regfile(addr) := wdata
  }

  when (io.mem.resp.valid) {
    regfile(memRespTag) := io.mem.resp.bits.data
    busy(memRespTag) := Bool(false)
  }

  // control
  when (io.mem.req.fire()) {
    busy(addr) := Bool(true)
  }

  val doResp = cmd.bits.inst.xd
  val stallReg = busy(addr)
  val stallLoad = doLoad && !io.mem.req.ready
  val stallResp = doResp && !io.resp.ready

  cmd.ready := !stallReg && !stallLoad && !stallResp
    // command resolved if no stalls AND not issuing a load that will need a request

  // PROC RESPONSE INTERFACE
  io.resp.valid := cmd.valid && doResp && !stallReg && !stallLoad
    // valid response if valid command, need a response, and no stalls
  io.resp.bits.rd := cmd.bits.inst.rd
    // Must respond with the appropriate tag or undefined behavior
  io.resp.bits.data := accum
    // Semantics is to always send out prior accumulator register value

  io.busy := cmd.valid || busy.reduce(_||_)
    // Be busy when have pending memory requests or committed possibility of pending requests
  io.interrupt := Bool(false)
    // Set this true to trigger an interrupt on the processor (please refer to supervisor documentation)

  // MEMORY REQUEST INTERFACE
  io.mem.req.valid := cmd.valid && doLoad && !stallReg && !stallResp
  io.mem.req.bits.addr := addend
  io.mem.req.bits.tag := addr
  io.mem.req.bits.cmd := M_XRD // perform a load (M_XWR for stores)
  io.mem.req.bits.typ := MT_D // D = 8 bytes, W = 4, H = 2, B = 1
  io.mem.req.bits.data := Bits(0) // we're not performing any stores...
  io.mem.req.bits.phys := Bool(false)
  io.mem.invalidate_lr := Bool(false)
}

class bogus(implicit p: Parameters) extends LazyRoCC {
  talksToPicos = true
  override lazy val module = new bogusModule(this)
}

class bogusModule(outer: bogus, n: Int = 4)(implicit p: Parameters) extends LazyRoCCModule(outer)
  with HasCoreParameters {

    // This register captures the index of the target
    // result register
    val req_rd = Reg(io.resp.bits.rd)

    val s_idle :: s_fetch_work :: s_submitting :: Nil = Enum(Bits(), 3)
    val state = Reg(init = s_idle)

    // Do not generate interrupts
    io.interrupt := Bool(false)

    // This holds the value of the funct field
    // from incoming RoCCInstruction's
    val funct = Reg(UInt(width = 7), init = UInt(0))

    // Let the registers reset to 0
    val x = Reg(UInt(width = xLen), init = UInt(0))
    val y = Reg(UInt(width = xLen), init = UInt(0))

    // The module is always ready to receive data
    io.cmd.ready  := (state === s_idle)
    
    // Tautology that says that we are 
    // busy whenever we are not idle
    io.busy       := (state =/= s_idle)

    // Get input when the command is fired
    when (io.cmd.fire()) {
      req_rd            := io.cmd.bits.inst.rd
      funct             := io.cmd.bits.inst.funct
      
      // The following lines obtain the values of
      // the registers indexed by io.cmd.bits.inst.rs1
      // and io.cmd.bits.inst.rs2
      x                 := io.cmd.bits.rs1
      y                 := io.cmd.bits.rs2

      when (funct === UInt(1)) {
        state := s_submitting
      } .elsewhen(funct === UInt(2)) {
        state := s_fetch_work
      }
    }

    // Implements submission to SubQ
    io.subQInterface.bits  := x
    io.subQInterface.valid := (state === s_submitting)
    when (io.subQInterface.fire()) { state := s_idle }

    // The response is valid whenever we have reached
    // the response state
    io.resp.valid     := (state === s_fetch_work && io.readyQInterface.valid)

    // We are only ready to receive data from the readyQ
    // when on s_fetch_work state
    io.readyQInterface.ready := (state === s_fetch_work && io.resp.ready)

    // Select the register to send the response to
    io.resp.bits.rd   := req_rd

    // Write data to the response register
    io.resp.bits.data := io.readyQInterface.bits
    
    // When the response gets sent, move
    // back to idle state
    when (io.resp.fire()) { state := s_idle }

    // We never issue memory requests
    io.mem.req.valid  := Bool(false)
}

class uselessAcc(implicit p: Parameters) extends LazyRoCC {
  override lazy val module = new uselessAccModule(this)
}

class uselessAccModule(outer: uselessAcc, n: Int = 4)(implicit p: Parameters) extends LazyRoCCModule(outer)
  with HasCoreParameters {

    //TODO: REMOVE!
    io.subQInterface.valid := Bool(true)
    io.readyQInterface.ready := Bool(true)

    // This register captures the index of the target
    // result register
    val req_rd = Reg(io.resp.bits.rd)

    val s_idle :: s_resp :: Nil = Enum(Bits(), 2)
    val state = Reg(init = s_idle)

    // Do not generate interrupts
    io.interrupt := Bool(false)

    // Let the registers reset to 0
    val x = Reg(UInt(width = xLen), init = UInt(0))
    val y = Reg(UInt(width = xLen), init = UInt(0))

    // The module is always ready to receive data
    io.cmd.ready  := (state === s_idle)
    
    // Tautology that says that we are 
    // busy whenever we are not idle
    io.busy       := (state =/= s_idle)

    // Get input when the command is fired
    when (io.cmd.fire()) {
      req_rd            := io.cmd.bits.inst.rd
      x                 := io.cmd.bits.rs1
      y                 := io.cmd.bits.rs2
      state             := s_resp
    }

    // When the response gets sent, move
    // back to idle state
    when (io.resp.fire()) { state := s_idle }

    // The response is valid whenever we have reached
    // the response state
    io.resp.valid     := (state === s_resp)

    // Select the register to send the response to
    io.resp.bits.rd   := req_rd

    // Write data to the response register
    io.resp.bits.data := (x + y + UInt(2)) * UInt(7)

    // We never issue memory requests
    io.mem.req.valid  := Bool(false)
}

class  TranslatorExample(implicit p: Parameters) extends LazyRoCC {
  override lazy val module = new TranslatorExampleModule(this)
}

class TranslatorExampleModule(outer: TranslatorExample)(implicit p: Parameters) extends LazyRoCCModule(outer)
  with HasCoreParameters {
  val req_addr = Reg(UInt(width = coreMaxAddrBits))
  val req_rd = Reg(io.resp.bits.rd)
  val req_offset = req_addr(pgIdxBits - 1, 0)
  val req_vpn = req_addr(coreMaxAddrBits - 1, pgIdxBits)
  val pte = Reg(new PTE)

  val s_idle :: s_ptw_req :: s_ptw_resp :: s_resp :: Nil = Enum(Bits(), 4)
  val state = Reg(init = s_idle)

  io.cmd.ready := (state === s_idle)

  when (io.cmd.fire()) {
    req_rd := io.cmd.bits.inst.rd
    req_addr := io.cmd.bits.rs1
    state := s_ptw_req
  }

  private val ptw = io.ptw(0)

  when (ptw.req.fire()) { state := s_ptw_resp }

  when (state === s_ptw_resp && ptw.resp.valid) {
    pte := ptw.resp.bits.pte
    state := s_resp
  }

  when (io.resp.fire()) { state := s_idle }

  ptw.req.valid := (state === s_ptw_req)
  ptw.req.bits.addr := req_vpn

  io.resp.valid := (state === s_resp)
  io.resp.bits.rd := req_rd
  io.resp.bits.data := Mux(pte.leaf(), Cat(pte.ppn, req_offset), SInt(-1, xLen).asUInt)

  io.busy := (state =/= s_idle)
  io.interrupt := Bool(false)
  io.mem.req.valid := Bool(false)
}

class  CharacterCountExample(implicit p: Parameters) extends LazyRoCC {
  override lazy val module = new CharacterCountExampleModule(this)
  override val atlNode = TLClientNode(TLClientParameters("CharacterCountRoCC"))
}

class CharacterCountExampleModule(outer: CharacterCountExample)(implicit p: Parameters) extends LazyRoCCModule(outer)
  with HasCoreParameters
  with HasL1CacheParameters {
  val cacheParams = tileParams.icache.get

  private val blockOffset = blockOffBits 
  private val beatOffset = log2Up(cacheDataBits/8)

  val needle = Reg(UInt(width = 8))
  val addr = Reg(UInt(width = coreMaxAddrBits))
  val count = Reg(UInt(width = xLen))
  val resp_rd = Reg(io.resp.bits.rd)

  val addr_block = addr(coreMaxAddrBits - 1, blockOffset)
  val offset = addr(blockOffset - 1, 0)
  val next_addr = (addr_block + UInt(1)) << UInt(blockOffset)

  val s_idle :: s_acq :: s_gnt :: s_check :: s_resp :: Nil = Enum(Bits(), 5)
  val state = Reg(init = s_idle)

  val tl_out = io.atl.head
  val gnt = tl_out.d.bits
  val recv_data = Reg(UInt(width = cacheDataBits))
  val recv_beat = Reg(UInt(width = log2Up(cacheDataBeats+1)), init = UInt(0))

  val data_bytes = Vec.tabulate(cacheDataBits/8) { i => recv_data(8 * (i + 1) - 1, 8 * i) }
  val zero_match = data_bytes.map(_ === UInt(0))
  val needle_match = data_bytes.map(_ === needle)
  val first_zero = PriorityEncoder(zero_match)

  val chars_found = PopCount(needle_match.zipWithIndex.map {
    case (matches, i) =>
      val idx = Cat(recv_beat - UInt(1), UInt(i, beatOffset))
      matches && idx >= offset && UInt(i) <= first_zero
  })
  val zero_found = zero_match.reduce(_ || _)
  val finished = Reg(Bool())

  io.cmd.ready := (state === s_idle)
  io.resp.valid := (state === s_resp)
  io.resp.bits.rd := resp_rd
  io.resp.bits.data := count
  tl_out.a.valid := (state === s_acq)
  tl_out.a.bits := outer.atlNode.edgesOut(0).Get(
                       fromSource = UInt(0),
                       toAddress = addr_block << blockOffset,
                       lgSize = UInt(lgCacheBlockBytes))._2
  tl_out.d.ready := (state === s_gnt)

  when (io.cmd.fire()) {
    addr := io.cmd.bits.rs1
    needle := io.cmd.bits.rs2
    resp_rd := io.cmd.bits.inst.rd
    count := UInt(0)
    finished := Bool(false)
    state := s_acq
  }

  when (tl_out.a.fire()) { state := s_gnt }

  when (tl_out.d.fire()) {
    recv_beat := recv_beat + UInt(1)
    recv_data := gnt.data
    state := s_check
  }

  when (state === s_check) {
    when (!finished) {
      count := count + chars_found
    }
    when (zero_found) { finished := Bool(true) }
    when (recv_beat === UInt(cacheDataBeats)) {
      addr := next_addr
      state := Mux(zero_found || finished, s_resp, s_acq)
    } .otherwise {
      state := s_gnt
    }
  }

  when (io.resp.fire()) { state := s_idle }

  io.busy := (state =/= s_idle)
  io.interrupt := Bool(false)
  io.mem.req.valid := Bool(false)
  // Tie off unused channels
  tl_out.b.ready := Bool(true)
  tl_out.c.valid := Bool(false)
  tl_out.e.valid := Bool(false)
}

class OpcodeSet(val opcodes: Seq[UInt]) {
  def |(set: OpcodeSet) =
    new OpcodeSet(this.opcodes ++ set.opcodes)

  def matches(oc: UInt) = opcodes.map(_ === oc).reduce(_ || _)
}

object OpcodeSet {
  def custom0 = new OpcodeSet(Seq(Bits("b0001011")))
  def custom1 = new OpcodeSet(Seq(Bits("b0101011")))
  def custom2 = new OpcodeSet(Seq(Bits("b1011011")))
  def custom3 = new OpcodeSet(Seq(Bits("b1111011")))
  def all = custom0 | custom1 | custom2 | custom3
}

class RoccCommandRouter(opcodes: Seq[OpcodeSet])(implicit p: Parameters)
    extends CoreModule()(p) {
  val io = new Bundle {
    // Commands coming in for the RoCC accelerators
    val in = Decoupled(new RoCCCommand).flip

    // Commands coming out for the RoCC accelerators matching the custom opcode
    val out = Vec(opcodes.size, Decoupled(new RoCCCommand))
    val busy = Bool(OUTPUT)
  }

  val cmd = Queue(io.in)
  val cmdReadys = io.out.zip(opcodes).map { case (out, opcode) =>
    val me = opcode.matches(cmd.bits.inst.opcode)
    out.valid := cmd.valid && me
    out.bits := cmd.bits
    out.ready && me
  }
  cmd.ready := cmdReadys.reduce(_ || _)
  io.busy := cmd.valid

  assert(PopCount(cmdReadys) <= UInt(1),
    "Custom opcode matched for more than one accelerator")
}
