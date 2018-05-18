// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VPicosManager__Syms_H_
#define _VPicosManager__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VPicosManager.h"

// SYMS CLASS
class VPicosManager__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VPicosManager*                 TOPp;
    
    // CREATORS
    VPicosManager__Syms(VPicosManager* topp, const char* namep);
    ~VPicosManager__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
