// See LICENSE.SiFive for license details.

package freechips.rocketchip.coreplex

import Chisel._

import freechips.rocketchip.config.Parameters

class RocketPlex(implicit p: Parameters) extends BaseCoreplex
    with CoreplexRISCVPlatform
    with HasRocketTiles {
  override lazy val module = new RocketPlexModule(this, () => new RocketPlexBundle(this))
}

class RocketPlexBundle[+L <: RocketPlex](_outer: L) extends BaseCoreplexBundle(_outer)
    with CoreplexRISCVPlatformBundle
    with HasRocketTilesBundle

/*
 * _io is a lambda that generates a HasRocketTilesBundle
 * RocketPlexModule extends BaseCoreplexModule, which extends BareCoreplexModule, which calls `val io = _io ()`,
 * so this class has a RocketPlexBundle io val.
 */
class RocketPlexModule[+L <: RocketPlex, +B <: RocketPlexBundle[L]](_outer: L, _io: () => B) extends BaseCoreplexModule(_outer, _io)
    with CoreplexRISCVPlatformModule
    with HasRocketTilesModule
