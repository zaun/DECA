// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vblinky_H_
#define _Vblinky_H_

#include "verilated.h"
class Vblinky__Syms;

//----------

VL_MODULE(Vblinky) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_clk,0,0);
    VL_OUT8(o_led,0,0);
    //char	__VpadToAlign2[2];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG(blinky__DOT__counter,25,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__i_clk,0,0);
    //char	__VpadToAlign17[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vblinky__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vblinky& operator= (const Vblinky&);	///< Copying not allowed
    Vblinky(const Vblinky&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vblinky(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vblinky();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vblinky__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vblinky__Syms* symsp, bool first);
  private:
    static QData	_change_request(Vblinky__Syms* __restrict vlSymsp);
    void	_configure_coverage(Vblinky__Syms* __restrict vlSymsp, bool first);
    void	_ctor_var_reset();
  public:
    static void	_eval(Vblinky__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vblinky__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vblinky__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vblinky__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(Vblinky__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
