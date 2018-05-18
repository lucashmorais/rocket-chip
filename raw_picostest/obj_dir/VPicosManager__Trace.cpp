// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VPicosManager__Syms.h"


//======================

void VPicosManager::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VPicosManager* t=(VPicosManager*)userthis;
    VPicosManager__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void VPicosManager::traceChgThis(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 1U)) | (vlTOPp->__Vm_traceActivity 
					      >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VPicosManager::traceChgThis__2(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,((1U & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24)))));
	vcdp->chgBit  (c+2,((1U & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23)))));
	vcdp->chgBus  (c+3,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram___05FT_43_data),32);
	vcdp->chgBit  (c+4,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
			     & (0U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)))));
	vcdp->chgBit  (c+5,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
			     & (1U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)))));
	vcdp->chgBit  (c+6,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
			     & (2U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)))));
	vcdp->chgBit  (c+7,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_252) 
			     & (3U == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data)))));
	vcdp->chgBit  (c+8,((1U & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24)))));
	vcdp->chgBit  (c+9,((1U & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23)))));
	vcdp->chgBus  (c+10,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram___05FT_43_data),4);
	vcdp->chgBit  (c+11,(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248));
    }
}

void VPicosManager::traceChgThis__3(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+12,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45) 
			      & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_24)))));
	vcdp->chgBit  (c+13,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44) 
			      & (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_23)))));
	vcdp->chgBit  (c+14,(((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_220)) 
			      & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248))));
	vcdp->chgBit  (c+15,((((1U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant)) 
			       | (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_233))) 
			      & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248))));
	vcdp->chgBit  (c+16,(((((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1)) 
				& (2U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))) 
			       | (~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234))) 
			      & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248))));
	vcdp->chgBit  (c+17,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45) 
			      & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_24)))));
	vcdp->chgBit  (c+18,(((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___GEN_44) 
			      & (~ (IData)(vlTOPp->PicosManager__DOT__subQueue__DOT___T_23)))));
    }
}

void VPicosManager::traceChgThis__4(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+19,(vlTOPp->PicosManager__DOT__subQueue__DOT___T_25));
	vcdp->chgBus  (c+20,(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77),4);
	vcdp->chgBit  (c+21,(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_45));
	vcdp->chgBit  (c+22,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT___T_25));
	vcdp->chgBit  (c+23,(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_1));
	vcdp->chgBit  (c+24,(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_2));
	vcdp->chgBit  (c+25,(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__validMask_3));
    }
}

void VPicosManager::traceChgThis__5(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+26,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[0]),32);
	vcdp->chgBus  (c+27,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[1]),32);
	vcdp->chgBus  (c+28,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[2]),32);
	vcdp->chgBus  (c+29,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[3]),32);
	vcdp->chgBus  (c+30,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[4]),32);
	vcdp->chgBus  (c+31,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[5]),32);
	vcdp->chgBus  (c+32,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[6]),32);
	vcdp->chgBus  (c+33,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[7]),32);
	vcdp->chgBus  (c+34,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[8]),32);
	vcdp->chgBus  (c+35,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[9]),32);
	vcdp->chgBus  (c+36,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[10]),32);
	vcdp->chgBus  (c+37,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[11]),32);
	vcdp->chgBus  (c+38,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[12]),32);
	vcdp->chgBus  (c+39,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[13]),32);
	vcdp->chgBus  (c+40,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[14]),32);
	vcdp->chgBus  (c+41,(vlTOPp->PicosManager__DOT__subQueue__DOT__ram[15]),32);
	vcdp->chgBus  (c+42,(vlTOPp->PicosManager__DOT__subQueue__DOT__value_1),4);
	vcdp->chgBus  (c+43,(vlTOPp->PicosManager__DOT__subQueue__DOT__value),4);
	vcdp->chgBit  (c+44,(vlTOPp->PicosManager__DOT__subQueue__DOT__maybe_full));
	vcdp->chgBus  (c+45,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram[0]),4);
	vcdp->chgBus  (c+46,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__ram[1]),4);
	vcdp->chgBit  (c+47,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value_1));
	vcdp->chgBit  (c+48,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__value));
	vcdp->chgBit  (c+49,(vlTOPp->PicosManager__DOT__arbiter__DOT__Queue__DOT__maybe_full));
	vcdp->chgBus  (c+50,(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant),4);
	vcdp->chgBit  (c+51,((1U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+52,((2U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+53,((3U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+54,((4U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+55,((5U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+56,((6U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+57,((7U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+58,((8U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+59,((9U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+60,((0xaU > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+61,((0xbU > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+62,((0xcU > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+63,((0xdU > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+64,((0xeU > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
	vcdp->chgBit  (c+65,((0xfU > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))));
    }
}

void VPicosManager::traceChgThis__6(VPicosManager__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VPicosManager* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+66,(vlTOPp->clock));
	vcdp->chgBit  (c+67,(vlTOPp->reset));
	vcdp->chgBit  (c+68,(vlTOPp->io_subQInterface_0_ready));
	vcdp->chgBit  (c+69,(vlTOPp->io_subQInterface_0_valid));
	vcdp->chgBus  (c+70,(vlTOPp->io_subQInterface_0_bits),32);
	vcdp->chgBit  (c+71,(vlTOPp->io_subQInterface_1_ready));
	vcdp->chgBit  (c+72,(vlTOPp->io_subQInterface_1_valid));
	vcdp->chgBus  (c+73,(vlTOPp->io_subQInterface_1_bits),32);
	vcdp->chgBit  (c+74,(vlTOPp->io_subQInterface_2_ready));
	vcdp->chgBit  (c+75,(vlTOPp->io_subQInterface_2_valid));
	vcdp->chgBus  (c+76,(vlTOPp->io_subQInterface_2_bits),32);
	vcdp->chgBit  (c+77,(vlTOPp->io_subQInterface_3_ready));
	vcdp->chgBit  (c+78,(vlTOPp->io_subQInterface_3_valid));
	vcdp->chgBus  (c+79,(vlTOPp->io_subQInterface_3_bits),32);
	vcdp->chgBit  (c+80,(vlTOPp->io_readyQInterface_0_ready));
	vcdp->chgBit  (c+81,(vlTOPp->io_readyQInterface_0_valid));
	vcdp->chgBus  (c+82,(vlTOPp->io_readyQInterface_0_bits),32);
	vcdp->chgBit  (c+83,(vlTOPp->io_readyQInterface_1_ready));
	vcdp->chgBit  (c+84,(vlTOPp->io_readyQInterface_1_valid));
	vcdp->chgBus  (c+85,(vlTOPp->io_readyQInterface_1_bits),32);
	vcdp->chgBit  (c+86,(vlTOPp->io_readyQInterface_2_ready));
	vcdp->chgBit  (c+87,(vlTOPp->io_readyQInterface_2_valid));
	vcdp->chgBus  (c+88,(vlTOPp->io_readyQInterface_2_bits),32);
	vcdp->chgBit  (c+89,(vlTOPp->io_readyQInterface_3_ready));
	vcdp->chgBit  (c+90,(vlTOPp->io_readyQInterface_3_valid));
	vcdp->chgBus  (c+91,(vlTOPp->io_readyQInterface_3_bits),32);
	vcdp->chgBus  (c+92,(((0xfU == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
			       ? 0U : ((0xeU == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
				        ? 0U : ((0xdU 
						 == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						 ? 0U
						 : 
						((0xcU 
						  == (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___GEN_77))
						  ? 0U
						  : 
						 ((0xbU 
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
							     : vlTOPp->io_subQInterface_0_bits)))))))))))))))),32);
	vcdp->chgBit  (c+93,(((((~ (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_219)) 
				& (3U > (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT__lastGrant))) 
			       | (~ ((IData)(vlTOPp->PicosManager__DOT__arbiter__DOT__RRArbiter__DOT___T_234) 
				     | (IData)(vlTOPp->io_subQInterface_2_valid)))) 
			      & (IData)(vlTOPp->PicosManager__DOT__arbiter__DOT___T_248))));
    }
}
