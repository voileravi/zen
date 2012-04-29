/*
 *  Copyright (C) 2001, Spectrum Digital, Inc.  All Rights Reserved.
 */

#define DSP_CLKIN        12
#define NULLLOOP_CLK     12

/*---- Clock Mode ----------------------------------------------------------*/
typedef struct c55xx_cmod
{
    unsigned short clkmd;       /* Clock-mode register                      */

}C55XX_CMOD;

typedef ioport volatile  C55XX_CMOD * PC55XX_CMOD;

#define C55XX_CLKMD_ADDR        0x1C00

typedef struct {
    int freq;        // DSP operating clock
    int clkin;       // DSP input clock
    int pllmult;     // PLL multiplier
    int plldiv;      // PLL divisor
    int clksperusec; // DSP clocks per usec
    int nullloopclk; // DSP clocks per null loop
} DSPCLK;

extern DSPCLK dspclk;

//  Read and write from an address
#define Read(addr) addr
#define Write(addr,data) addr = data

//  Set or clear all bits in the mask
#define ClearMask(addr,mask) addr = (addr & ~(mask))
#define SetMask(addr,mask) addr = (addr | (mask))

//  Read and write data at addr, only bits in mask are affected
#define ReadMask(addr,mask) (addr & (mask))
#define WriteMask(addr,data,mask) addr = (addr & ~(mask)) | (data)

