// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VPicosManager_H_
#define _VPicosManager_H_

#include "verilated.h"

class VPicosManager__Syms;
class VerilatedVcd;

//----------

VL_MODULE(VPicosManager) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_subQInterface_0_ready,0,0);
    VL_IN8(io_subQInterface_0_valid,0,0);
    VL_OUT8(io_subQInterface_1_ready,0,0);
    VL_IN8(io_subQInterface_1_valid,0,0);
    VL_OUT8(io_subQInterface_2_ready,0,0);
    VL_IN8(io_subQInterface_2_valid,0,0);
    VL_OUT8(io_subQInterface_3_ready,0,0);
    VL_IN8(io_subQInterface_3_valid,0,0);
    VL_IN8(io_readyQInterface_0_ready,0,0);
    VL_OUT8(io_readyQInterface_0_valid,0,0);
    VL_IN8(io_readyQInterface_1_ready,0,0);
    VL_OUT8(io_readyQInterface_1_valid,0,0);
    VL_IN8(io_readyQInterface_2_ready,0,0);
    VL_OUT8(io_readyQInterface_2_valid,0,0);
    VL_IN8(io_readyQInterface_3_ready,0,0);
    VL_OUT8(io_readyQInterface_3_valid,0,0);
    VL_IN(io_subQInterface_0_bits,31,0);
    VL_IN(io_subQInterface_1_bits,31,0);
    VL_IN(io_subQInterface_2_bits,31,0);
    VL_IN(io_subQInterface_3_bits,31,0);
    VL_OUT(io_readyQInterface_0_bits,31,0);
    VL_OUT(io_readyQInterface_1_bits,31,0);
    VL_OUT(io_readyQInterface_2_bits,31,0);
    VL_OUT(io_readyQInterface_3_bits,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(PicosManager__DOT__subQueue__DOT__value,3,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT__value_1,3,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT__maybe_full,0,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_20,0,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_23,0,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_24,0,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_25,0,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_27,0,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_33,3,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_37,3,0);
    VL_SIG8(PicosManager__DOT__subQueue__DOT___T_38,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT___T_248,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT___T_252,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT___GEN_44,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data,3,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT__value,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_33,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_37,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT___T_38,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_200,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant,3,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234,0,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77,3,0);
    VL_SIG(PicosManager__DOT__subQueue__DOT__ram___05FT_43_data,31,0);
    VL_SIG(PicosManager__DOT__subQueue__DOT__ram[16],31,0);
    VL_SIG8(PicosManager__DOT__arbiter__DOT__Queue__DOT__ram[2],3,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VPicosManager__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VPicosManager& operator= (const VPicosManager&);  ///< Copying not allowed
    VPicosManager(const VPicosManager&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VPicosManager(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VPicosManager();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VPicosManager__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VPicosManager__Syms* symsp, bool first);
  private:
    static QData _change_request(VPicosManager__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VPicosManager__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(VPicosManager__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VPicosManager__Syms* __restrict vlSymsp);
    static void _eval_settle(VPicosManager__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(VPicosManager__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VPicosManager__Syms* __restrict vlSymsp);
    static void traceChgThis(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
