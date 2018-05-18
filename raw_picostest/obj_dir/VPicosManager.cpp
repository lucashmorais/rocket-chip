// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VPicosManager.h for the primary calling header

#include "VPicosManager.h"     // For This
#include "VPicosManager__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VPicosManager) {
    VPicosManager__Syms* __restrict vlSymsp = __VlSymsp = new VPicosManager__Syms(this, name());
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VPicosManager::__Vconfigure(VPicosManager__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VPicosManager::~VPicosManager() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VPicosManager::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VPicosManager::eval\n"); );
    VPicosManager__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VPicosManager::_eval_initial_loop(VPicosManager__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VPicosManager::_sequent__TOP__1(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_sequent__TOP__1\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__PicosManager__DOT__subQueue__DOT__ram__v0,3,0);
    VL_SIG8(__Vdlyvset__PicosManager__DOT__subQueue__DOT__ram__v0,0,0);
    VL_SIG8(__Vdlyvdim0__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0,0,0);
    VL_SIG8(__Vdlyvval__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0,3,0);
    VL_SIG8(__Vdlyvset__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0,0,0);
    VL_SIG(__Vdlyvval__PicosManager__DOT__subQueue__DOT__ram__v0,31,0);
    // Body
    __Vdlyvset__PicosManager__DOT__subQueue__DOT__ram__v0 = 0U;
    __Vdlyvset__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0 = 0U;
    // ALWAYS at PicosManager.v:105
    if (vlTOPp->reset) {
	vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full = 0U;
    } else {
	if (vlTOPp->PicosManager__DOT__subQueue__DOT___T_38) {
	    vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full 
		= vlTOPp->PicosManager__DOT__subQueue__DOT___T_25;
	}
    }
    // ALWAYS at PicosManager.v:222
    if (vlTOPp->reset) {
	vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full = 0U;
    } else {
	if (vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_38) {
	    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full 
		= vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25;
	}
    }
    // ALWAYS at PicosManager.v:105
    if (vlTOPp->reset) {
	vlTOPp->PicosManager__DOT__subQueue__DOT__value_1 = 0U;
    } else {
	if (vlTOPp->PicosManager__DOT__subQueue__DOT___T_27) {
	    vlTOPp->PicosManager__DOT__subQueue__DOT__value_1 
		= vlTOPp->PicosManager__DOT__subQueue__DOT___T_37;
	}
    }
    // ALWAYS at PicosManager.v:105
    if (vlTOPp->PicosManager__DOT__subQueue__DOT___T_25) {
	__Vdlyvval__PicosManager__DOT__subQueue__DOT__ram__v0 
	    = ((0xfU == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
	        ? 0U : ((0xeU == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
			 ? 0U : ((0xdU == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
				  ? 0U : ((0xcU == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
					   ? 0U : (
						   (0xbU 
						    == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						    ? 0U
						    : 
						   ((0xaU 
						     == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						     ? 0U
						     : 
						    ((9U 
						      == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						      ? 0U
						      : 
						     ((8U 
						       == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						       ? 0U
						       : 
						      ((7U 
							== (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						        ? 0U
						        : 
						       ((6U 
							 == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
							 ? 0U
							 : 
							((5U 
							  == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
							  ? 0U
							  : 
							 ((4U 
							   == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
							   ? 0U
							   : 
							  ((3U 
							    == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
							    ? vlTOPp->io_subQInterface_3_bits
							    : 
							   ((2U 
							     == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
							     ? vlTOPp->io_subQInterface_2_bits
							     : 
							    ((1U 
							      == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
							      ? vlTOPp->io_subQInterface_1_bits
							      : vlTOPp->io_subQInterface_0_bits)))))))))))))));
	__Vdlyvset__PicosManager__DOT__subQueue__DOT__ram__v0 = 1U;
	__Vdlyvdim0__PicosManager__DOT__subQueue__DOT__ram__v0 
	    = vlTOPp->PicosManager__DOT__subQueue__DOT__value;
    }
    // ALWAYS at PicosManager.v:222
    if (vlTOPp->reset) {
	vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1 = 0U;
    } else {
	if (vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27) {
	    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1 
		= vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_37;
	}
    }
    // ALWAYS at PicosManager.v:222
    if (vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25) {
	__Vdlyvval__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0 
	    = vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77;
	__Vdlyvset__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0 = 1U;
	__Vdlyvdim0__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0 
	    = vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value;
    }
    // ALWAYS at PicosManager.v:560
    if (vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_200) {
	vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant 
	    = vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77;
    }
    // ALWAYSPOST at PicosManager.v:106
    if (__Vdlyvset__PicosManager__DOT__subQueue__DOT__ram__v0) {
	vlTOPp->PicosManager__DOT__subQueue__DOT__ram[__Vdlyvdim0__PicosManager__DOT__subQueue__DOT__ram__v0] 
	    = __Vdlyvval__PicosManager__DOT__subQueue__DOT__ram__v0;
    }
    // ALWAYSPOST at PicosManager.v:223
    if (__Vdlyvset__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0) {
	vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram[__Vdlyvdim0__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0] 
	    = __Vdlyvval__PicosManager__DOT__arbiter__DOT__Queue__DOT__ram__v0;
    }
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_37 
	= (0xfU & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value_1)));
    vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data 
	= vlTOPp->PicosManager__DOT__subQueue__DOT__ram
	[vlTOPp->PicosManager__DOT__subQueue__DOT__value_1];
    // ALWAYS at PicosManager.v:105
    if (vlTOPp->reset) {
	vlTOPp->PicosManager__DOT__subQueue__DOT__value = 0U;
    } else {
	if (vlTOPp->PicosManager__DOT__subQueue__DOT___T_25) {
	    vlTOPp->PicosManager__DOT__subQueue__DOT__value 
		= vlTOPp->PicosManager__DOT__subQueue__DOT___T_33;
	}
    }
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_37 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data 
	= vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram
	[vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1];
    // ALWAYS at PicosManager.v:222
    if (vlTOPp->reset) {
	vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value = 0U;
    } else {
	if (vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25) {
	    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value 
		= vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_33;
	}
    }
    vlTOPp->io_readyQInterface_0_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->io_readyQInterface_1_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->io_readyQInterface_2_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->io_readyQInterface_3_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_33 
	= (0xfU & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value)));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_20 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value) 
	   == (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value_1));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_33 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value) 
	   == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_23 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_20) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full)));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_24 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_20) 
	   & (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20) 
	   & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full));
    vlTOPp->PicosManager__DOT__arbiter__DOT___T_252 
	= (1U & ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23)) 
		 & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23))));
    vlTOPp->PicosManager__DOT__arbiter__DOT___T_248 
	= (1U & ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24)) 
		 & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24))));
    vlTOPp->io_readyQInterface_0_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (0U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_readyQInterface_1_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (1U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_readyQInterface_2_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (2U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_readyQInterface_3_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (3U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
}

void VPicosManager::_settle__TOP__2(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_settle__TOP__2\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_37 
	= (0xfU & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value_1)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_37 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1)));
    vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data 
	= vlTOPp->PicosManager__DOT__subQueue__DOT__ram
	[vlTOPp->PicosManager__DOT__subQueue__DOT__value_1];
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data 
	= vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram
	[vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1];
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3 
	= ((IData)(vlTOPp->io_subQInterface_3_valid) 
	   & (3U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2 
	= ((IData)(vlTOPp->io_subQInterface_2_valid) 
	   & (2U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1 
	= ((IData)(vlTOPp->io_subQInterface_1_valid) 
	   & (1U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_33 
	= (0xfU & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_33 
	= (1U & ((IData)(1U) + (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value)));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_20 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value) 
	   == (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__value_1));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value) 
	   == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1));
    vlTOPp->io_readyQInterface_0_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->io_readyQInterface_1_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->io_readyQInterface_2_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->io_readyQInterface_3_bits = vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data;
    vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44 
	= ((0xfU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
	   & ((0xeU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
	      & ((0xdU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
		 & ((0xcU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
		    & ((0xbU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
		       & ((0xaU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
			  & ((9U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
			     & ((8U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
				& ((7U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
				   & ((6U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
				      & ((5U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
					 & ((4U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
					    & ((3U 
						== (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data))
					        ? (IData)(vlTOPp->io_readyQInterface_3_ready)
					        : (
						   (2U 
						    == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data))
						    ? (IData)(vlTOPp->io_readyQInterface_2_ready)
						    : 
						   ((1U 
						     == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data))
						     ? (IData)(vlTOPp->io_readyQInterface_1_ready)
						     : (IData)(vlTOPp->io_readyQInterface_0_ready))))))))))))))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1)
	    ? 1U : ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2)
		     ? 2U : ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3)
			      ? 3U : ((IData)(vlTOPp->io_subQInterface_0_valid)
				       ? 0U : ((IData)(vlTOPp->io_subQInterface_1_valid)
					        ? 1U
					        : ((IData)(vlTOPp->io_subQInterface_2_valid)
						    ? 2U
						    : 
						   ((IData)(vlTOPp->io_subQInterface_3_valid)
						     ? 3U
						     : 0xfU)))))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1) 
	   | (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_23 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_20) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full)));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_24 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_20) 
	   & (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20) 
	   & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45 
	= ((0xfU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
	   & ((0xeU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
	      & ((0xdU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
		 & ((0xcU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
		    & ((0xbU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
		       & ((0xaU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
			  & ((9U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
			     & ((8U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
				& ((7U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
				   & ((6U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
				      & ((5U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
					 & ((4U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
					    & ((3U 
						== (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
					        ? (IData)(vlTOPp->io_subQInterface_3_valid)
					        : (
						   (2U 
						    == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						    ? (IData)(vlTOPp->io_subQInterface_2_valid)
						    : 
						   ((1U 
						     == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						     ? (IData)(vlTOPp->io_subQInterface_1_valid)
						     : (IData)(vlTOPp->io_subQInterface_0_valid))))))))))))))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219) 
	   | (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_27 
	= (((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44) 
	    & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23))) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27 
	= (((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44) 
	    & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23))) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23)));
    vlTOPp->PicosManager__DOT__arbiter__DOT___T_252 
	= (1U & ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23)) 
		 & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23))));
    vlTOPp->PicosManager__DOT__arbiter__DOT___T_248 
	= (1U & ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24)) 
		 & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24))));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_25 
	= ((~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24)) 
	   & ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45) 
	      & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25 
	= ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24)) 
	   & ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45) 
	      & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220) 
	   | (IData)(vlTOPp->io_subQInterface_0_valid));
    vlTOPp->io_readyQInterface_0_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (0U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_readyQInterface_1_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (1U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_readyQInterface_2_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (2U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_readyQInterface_3_valid = ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
					  & (3U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)));
    vlTOPp->io_subQInterface_0_ready = ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220)) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_200 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248) 
	   & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_38 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_25) 
	   != (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_27));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_38 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25) 
	   != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233) 
	   | (IData)(vlTOPp->io_subQInterface_1_valid));
    vlTOPp->io_subQInterface_1_ready = (((1U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)) 
					 | (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233))) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    vlTOPp->io_subQInterface_2_ready = ((((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1)) 
					  & (2U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))) 
					 | (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234))) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    vlTOPp->io_subQInterface_3_ready = ((((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219)) 
					  & (3U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))) 
					 | (~ ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234) 
					       | (IData)(vlTOPp->io_subQInterface_2_valid)))) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
}

VL_INLINE_OPT void VPicosManager::_combo__TOP__3(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_combo__TOP__3\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3 
	= ((IData)(vlTOPp->io_subQInterface_3_valid) 
	   & (3U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2 
	= ((IData)(vlTOPp->io_subQInterface_2_valid) 
	   & (2U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1 
	= ((IData)(vlTOPp->io_subQInterface_1_valid) 
	   & (1U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)));
    vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44 
	= ((0xfU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
	   & ((0xeU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
	      & ((0xdU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
		 & ((0xcU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
		    & ((0xbU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
		       & ((0xaU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
			  & ((9U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
			     & ((8U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
				& ((7U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
				   & ((6U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
				      & ((5U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
					 & ((4U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)) 
					    & ((3U 
						== (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data))
					        ? (IData)(vlTOPp->io_readyQInterface_3_ready)
					        : (
						   (2U 
						    == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data))
						    ? (IData)(vlTOPp->io_readyQInterface_2_ready)
						    : 
						   ((1U 
						     == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data))
						     ? (IData)(vlTOPp->io_readyQInterface_1_ready)
						     : (IData)(vlTOPp->io_readyQInterface_0_ready))))))))))))))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1)
	    ? 1U : ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2)
		     ? 2U : ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3)
			      ? 3U : ((IData)(vlTOPp->io_subQInterface_0_valid)
				       ? 0U : ((IData)(vlTOPp->io_subQInterface_1_valid)
					        ? 1U
					        : ((IData)(vlTOPp->io_subQInterface_2_valid)
						    ? 2U
						    : 
						   ((IData)(vlTOPp->io_subQInterface_3_valid)
						     ? 3U
						     : 0xfU)))))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1) 
	   | (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_27 
	= (((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44) 
	    & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23))) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27 
	= (((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44) 
	    & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23))) 
	   & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23)));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45 
	= ((0xfU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
	   & ((0xeU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
	      & ((0xdU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
		 & ((0xcU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
		    & ((0xbU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
		       & ((0xaU != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
			  & ((9U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
			     & ((8U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
				& ((7U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
				   & ((6U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
				      & ((5U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
					 & ((4U != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77)) 
					    & ((3U 
						== (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
					        ? (IData)(vlTOPp->io_subQInterface_3_valid)
					        : (
						   (2U 
						    == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						    ? (IData)(vlTOPp->io_subQInterface_2_valid)
						    : 
						   ((1U 
						     == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						     ? (IData)(vlTOPp->io_subQInterface_1_valid)
						     : (IData)(vlTOPp->io_subQInterface_0_valid))))))))))))))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219) 
	   | (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_25 
	= ((~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24)) 
	   & ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45) 
	      & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25 
	= ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24)) 
	   & ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45) 
	      & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24))));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_200 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248) 
	   & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220) 
	   | (IData)(vlTOPp->io_subQInterface_0_valid));
    vlTOPp->io_subQInterface_0_ready = ((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220)) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    vlTOPp->PicosManager__DOT__subQueue__DOT___T_38 
	= ((IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_25) 
	   != (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_27));
    vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_38 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25) 
	   != (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27));
    vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234 
	= ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233) 
	   | (IData)(vlTOPp->io_subQInterface_1_valid));
    vlTOPp->io_subQInterface_1_ready = (((1U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)) 
					 | (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233))) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    vlTOPp->io_subQInterface_2_ready = ((((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1)) 
					  & (2U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))) 
					 | (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234))) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    vlTOPp->io_subQInterface_3_ready = ((((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219)) 
					  & (3U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))) 
					 | (~ ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234) 
					       | (IData)(vlTOPp->io_subQInterface_2_valid)))) 
					& (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
}

void VPicosManager::_eval(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_eval\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VPicosManager::_eval_initial(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_eval_initial\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VPicosManager::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::final\n"); );
    // Variables
    VPicosManager__Syms* __restrict vlSymsp = this->__VlSymsp;
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VPicosManager::_eval_settle(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_eval_settle\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VPicosManager::_change_request(VPicosManager__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_change_request\n"); );
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VPicosManager::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_subQInterface_0_valid & 0xfeU))) {
	Verilated::overWidthError("io_subQInterface_0_valid");}
    if (VL_UNLIKELY((io_subQInterface_1_valid & 0xfeU))) {
	Verilated::overWidthError("io_subQInterface_1_valid");}
    if (VL_UNLIKELY((io_subQInterface_2_valid & 0xfeU))) {
	Verilated::overWidthError("io_subQInterface_2_valid");}
    if (VL_UNLIKELY((io_subQInterface_3_valid & 0xfeU))) {
	Verilated::overWidthError("io_subQInterface_3_valid");}
    if (VL_UNLIKELY((io_readyQInterface_0_ready & 0xfeU))) {
	Verilated::overWidthError("io_readyQInterface_0_ready");}
    if (VL_UNLIKELY((io_readyQInterface_1_ready & 0xfeU))) {
	Verilated::overWidthError("io_readyQInterface_1_ready");}
    if (VL_UNLIKELY((io_readyQInterface_2_ready & 0xfeU))) {
	Verilated::overWidthError("io_readyQInterface_2_ready");}
    if (VL_UNLIKELY((io_readyQInterface_3_ready & 0xfeU))) {
	Verilated::overWidthError("io_readyQInterface_3_ready");}
}
#endif // VL_DEBUG

void VPicosManager::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VPicosManager::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_subQInterface_0_ready = VL_RAND_RESET_I(1);
    io_subQInterface_0_valid = VL_RAND_RESET_I(1);
    io_subQInterface_0_bits = VL_RAND_RESET_I(32);
    io_subQInterface_1_ready = VL_RAND_RESET_I(1);
    io_subQInterface_1_valid = VL_RAND_RESET_I(1);
    io_subQInterface_1_bits = VL_RAND_RESET_I(32);
    io_subQInterface_2_ready = VL_RAND_RESET_I(1);
    io_subQInterface_2_valid = VL_RAND_RESET_I(1);
    io_subQInterface_2_bits = VL_RAND_RESET_I(32);
    io_subQInterface_3_ready = VL_RAND_RESET_I(1);
    io_subQInterface_3_valid = VL_RAND_RESET_I(1);
    io_subQInterface_3_bits = VL_RAND_RESET_I(32);
    io_readyQInterface_0_ready = VL_RAND_RESET_I(1);
    io_readyQInterface_0_valid = VL_RAND_RESET_I(1);
    io_readyQInterface_0_bits = VL_RAND_RESET_I(32);
    io_readyQInterface_1_ready = VL_RAND_RESET_I(1);
    io_readyQInterface_1_valid = VL_RAND_RESET_I(1);
    io_readyQInterface_1_bits = VL_RAND_RESET_I(32);
    io_readyQInterface_2_ready = VL_RAND_RESET_I(1);
    io_readyQInterface_2_valid = VL_RAND_RESET_I(1);
    io_readyQInterface_2_bits = VL_RAND_RESET_I(32);
    io_readyQInterface_3_ready = VL_RAND_RESET_I(1);
    io_readyQInterface_3_valid = VL_RAND_RESET_I(1);
    io_readyQInterface_3_bits = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    PicosManager__DOT__subQueue__DOT__ram[__Vi0] = VL_RAND_RESET_I(32);
    }}
    PicosManager__DOT__subQueue__DOT__ram___05FT_43_data = VL_RAND_RESET_I(32);
    PicosManager__DOT__subQueue__DOT__value = VL_RAND_RESET_I(4);
    PicosManager__DOT__subQueue__DOT__value_1 = VL_RAND_RESET_I(4);
    PicosManager__DOT__subQueue__DOT__maybe_full = VL_RAND_RESET_I(1);
    PicosManager__DOT__subQueue__DOT___T_20 = VL_RAND_RESET_I(1);
    PicosManager__DOT__subQueue__DOT___T_23 = VL_RAND_RESET_I(1);
    PicosManager__DOT__subQueue__DOT___T_24 = VL_RAND_RESET_I(1);
    PicosManager__DOT__subQueue__DOT___T_25 = VL_RAND_RESET_I(1);
    PicosManager__DOT__subQueue__DOT___T_27 = VL_RAND_RESET_I(1);
    PicosManager__DOT__subQueue__DOT___T_33 = VL_RAND_RESET_I(4);
    PicosManager__DOT__subQueue__DOT___T_37 = VL_RAND_RESET_I(4);
    PicosManager__DOT__subQueue__DOT___T_38 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT___T_248 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT___T_252 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT___GEN_44 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
	    PicosManager__DOT__arbiter__DOT__Queue__DOT__ram[__Vi0] = VL_RAND_RESET_I(4);
    }}
    PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data = VL_RAND_RESET_I(4);
    PicosManager__DOT__arbiter__DOT__Queue__DOT__value = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_20 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_27 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_33 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_37 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__Queue__DOT___T_38 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_200 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant = VL_RAND_RESET_I(4);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234 = VL_RAND_RESET_I(1);
    PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77 = VL_RAND_RESET_I(4);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
