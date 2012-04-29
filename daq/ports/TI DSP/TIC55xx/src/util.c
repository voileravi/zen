/*
 *  Copyright (C) 2001, Spectrum Digital, Inc.  All Rights Reserved.
 */

//#include "c55xxdefs.h"
#include "5509.h"
#include "util.h"

DSPCLK dspclk;

void pll_init(unsigned long freq)
{
    PC55XX_CMOD pCMOD = (PC55XX_CMOD)C55XX_CLKMD_ADDR;

    // Calculate PLL multiplier values (only integral multiples now)
    dspclk.clkin = DSP_CLKIN;
    dspclk.pllmult = (int)freq / dspclk.clkin;
    dspclk.freq = dspclk.pllmult * dspclk.clkin;
    dspclk.plldiv = 0;
    dspclk.nullloopclk = NULLLOOP_CLK;

    // Turn the PLL off
    ClearMask(pCMOD -> clkmd, CLKMD_PLLENABLE);
    while(ReadMask(pCMOD -> clkmd, CLKMD_LOCK))
    {
        ;   // empty loop
    }

    // Initialize PLL flags
    ClearMask(pCMOD -> clkmd, CLKMD_IAI);
    SetMask(pCMOD -> clkmd, CLKMD_IOB | CLKMD_BREAKLN);

    // Set the multiplier/divisor
    WriteMask(pCMOD -> clkmd, CLKMD_PLLDIV_1 | CLKMD_BYPASSDIV_1, CLKMD_PLLDIV_MASK | CLKMD_BYPASSDIV_MASK);

    pCMOD->clkmd = ((pCMOD->clkmd & ~(CLKMD_PLLMULT_MASK)) | ((unsigned int)dspclk.pllmult <<  7));


    // Enable the PLL and wait for lock
    SetMask(pCMOD -> clkmd, CLKMD_PLLENABLE);
//    while(!ReadMask(pCMOD -> clkmd, CLKMD_LOCK));
}
