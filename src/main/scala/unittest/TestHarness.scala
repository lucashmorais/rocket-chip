// See LICENSE.SiFive for license details.

package freechips.rocketchip.unittest

import Chisel._
import freechips.rocketchip.config.Parameters

// Top-level class for unit tests
class TestHarness(implicit val p: Parameters) extends Module {
  val io = new Bundle { val success = Bool(OUTPUT) }

  // Tests are successful if the UnitTestSuite was able to finish
  io.success := Module(new UnitTestSuite).io.finished
}
