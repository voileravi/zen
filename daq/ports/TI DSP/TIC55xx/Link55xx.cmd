/* This is a control file to the linker for the Texas Instruments 55xx series DSP.
 * This particular configuration is for the Spectrum Digital 5510 target board.
 */
 
-c
-heap  0x1000
-stack 0x1000
-sysstack 0x1000
-u __vectors
-u _auto_init



MEMORY                   /* MEMORY directive      */
{
    /* Addresses 0 to 0xBF are for Memory Mapped Registers.  Don't use them here. */

    /* Place vectors at "page 1": each page containing 256 bytes. */ 
    VECTORS:  origin = 00100h length = 00100h
   
    /* Map "ROM" to the target's "Internal Memory". */
    ROM:  origin = 00200h    length = 27E00h 
    
    /* This starting point is arbitrary, the board has "SDRAM" to 0x200000.
    /* Jim believes that memory at high addresses is unstable (bits change
     * mysteriously particularly when the CPU is halted by the debugger. 
     */
    RAM:  origin = 28000h    length = 100000h
}

SECTIONS                 /* SECTIONS directive    */
{
	vectors  >   VECTORS
	
    .text:    >   ROM
    .cinit    >   ROM
	.const	  >   ROM  
	
    .bss:     >   RAM
    .data:    >   RAM
    .stack    >   RAM
    .sysstack >   RAM
}

