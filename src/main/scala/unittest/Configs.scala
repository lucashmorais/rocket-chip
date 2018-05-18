// See LICENSE.SiFive for license details.

package freechips.rocketchip.unittest

import Chisel._
import freechips.rocketchip.amba.ahb._
import freechips.rocketchip.amba.apb._
import freechips.rocketchip.amba.axi4._
import freechips.rocketchip.chip.{BaseConfig, BasePlatformConfig}
import freechips.rocketchip.config._
import freechips.rocketchip.devices.tilelink._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.integrators.PicosManagerTest

case object TestDurationMultiplier extends Field[Int]

// This Config class is useful for controlling the duration of tests.
// Several of the following Config classes depend on it.
class WithTestDuration(x: Int) extends Config((site, here, up) => {
  case TestDurationMultiplier => x
})

// Config-extending class that leverages Config's ability to generate
// object from (View, View, View) => PartialFunction[Any, Any] lambda.
class WithAMBAUnitTests extends Config((site, here, up) => {

  // The way how UnitTests should be run are specified below a UnitTests
  // case.
  case UnitTests =>

    // As one can see, the return value of the UnitTests case must be a
    // Parameters => Seq[Module] closure.
    (q: Parameters) => {
      implicit val p = q
      val txns = 100 * site(TestDurationMultiplier)
      val timeout = 50000 * site(TestDurationMultiplier)
      Seq(
        Module(new AHBBridgeTest(true, txns=8*txns, timeout=timeout)),
        Module(new AHBNativeTest(true, txns=6*txns, timeout=timeout)),
        Module(new AHBNativeTest(false,txns=6*txns, timeout=timeout)),
        Module(new APBBridgeTest(true, txns=6*txns, timeout=timeout)),
        Module(new APBBridgeTest(false,txns=6*txns, timeout=timeout)),
        Module(new AXI4LiteFuzzRAMTest(txns=6*txns, timeout=timeout)),
        Module(new AXI4FullFuzzRAMTest(txns=3*txns, timeout=timeout)),
        Module(new AXI4BridgeTest(     txns=3*txns, timeout=timeout)))
    }
})

// Config-extending class that leverages Config's ability to generate
// object from (View, View, View) => PartialFunction[Any, Any] lambda.
class WithPicosManagerTest extends Config((site, here, up) => {

  // The way how UnitTests should be run are specified below a UnitTests
  // case.
  case UnitTests =>

    // As one can see, the return value of the UnitTests case must be a
    // Parameters => Seq[Module] closure.
    (q: Parameters) => {
      implicit val p = q
      val txns = site(TestDurationMultiplier)
      val timeout = 10 * site(TestDurationMultiplier)
      Seq(Module(new PicosManagerTest(txns=8*txns, timeout=timeout)))
    }
})

class WithTLSimpleUnitTests extends Config((site, here, up) => {
  case UnitTests => (q: Parameters) => {
    implicit val p = q
    val txns = 100 * site(TestDurationMultiplier)
    val timeout = 50000 * site(TestDurationMultiplier)
    Seq(
      Module(new TLRAMSimpleTest(1,        txns=15*txns, timeout=timeout)),
      Module(new TLRAMSimpleTest(4,        txns=15*txns, timeout=timeout)),
      Module(new TLRAMSimpleTest(16,       txns=15*txns, timeout=timeout)),
      Module(new TLRAMZeroDelayTest(4,     txns=15*txns, timeout=timeout)),
      Module(new TLFuzzRAMTest(            txns= 3*txns, timeout=timeout)),
      Module(new TLRR0Test(                txns= 3*txns, timeout=timeout)),
      Module(new TLRR1Test(                txns= 3*txns, timeout=timeout)),
      Module(new TLRAMRationalCrossingTest(txns= 3*txns, timeout=timeout)),
      Module(new TLRAMAsyncCrossingTest(   txns= 5*txns, timeout=timeout)),
      Module(new TLRAMAtomicAutomataTest(  txns=10*txns, timeout=timeout)) ) }
})

class WithTLWidthUnitTests extends Config((site, here, up) => {
  case UnitTests => (q: Parameters) => {
    implicit val p = q
    val txns = 100 * site(TestDurationMultiplier)
    val timeout = 50000 * site(TestDurationMultiplier)
    Seq(
      Module(new TLRAMFragmenterTest( 4, 256, txns= 5*txns, timeout=timeout)),
      Module(new TLRAMFragmenterTest(16,  64, txns=15*txns, timeout=timeout)),
      Module(new TLRAMFragmenterTest( 4,  16, txns=15*txns, timeout=timeout)),
      Module(new TLRAMWidthWidgetTest( 1,  1, txns= 1*txns, timeout=timeout)),
      Module(new TLRAMWidthWidgetTest( 4, 64, txns= 4*txns, timeout=timeout)),
      Module(new TLRAMWidthWidgetTest(64,  4, txns= 5*txns, timeout=timeout)) ) }
})

class WithTLXbarUnitTests extends Config((site, here, up) => {
  case UnitTests => (q: Parameters) => {
    implicit val p = q
    val txns = 100 * site(TestDurationMultiplier)
    val timeout = 50000 * site(TestDurationMultiplier)
    Seq(
      Module(new TLRAMXbarTest(1,           txns=5*txns, timeout=timeout)),
      Module(new TLRAMXbarTest(2,           txns=5*txns, timeout=timeout)),
      Module(new TLRAMXbarTest(8,           txns=5*txns, timeout=timeout)),
      Module(new TLMulticlientXbarTest(4,4, txns=2*txns, timeout=timeout)) ) }
})

class AMBAUnitTestConfig extends Config(new WithAMBAUnitTests ++ new WithTestDuration(10) ++ new BasePlatformConfig)
class TLSimpleUnitTestConfig extends Config(new WithTLSimpleUnitTests ++ new WithTestDuration(10) ++ new BasePlatformConfig)
class TLWidthUnitTestConfig extends Config(new WithTLWidthUnitTests ++ new WithTestDuration(10) ++ new BasePlatformConfig)
class TLXbarUnitTestConfig extends Config(new WithTLXbarUnitTests ++ new WithTestDuration(10) ++ new BasePlatformConfig)
class PicosManagerUnitTestConfig extends Config(new WithPicosManagerTest ++ new WithTestDuration(1) ++ new BasePlatformConfig)
