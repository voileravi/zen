/*
 *  Copyright (C) 2001, Spectrum Digital, Inc.  All Rights Reserved.
 */


// 5509 Test Enable Flags
#define TEST_SDRAM          0x0001
#define TEST_FLASH          0x0002
#define TEST_SROM           0x0004
#define TEST_SWITCHES       0x0008
#define TEST_DISPLAY        0x0010
#define TEST_TIMER          0x0020
#define TEST_RTC            0x0040
#define TEST_AIC23          0x0080
#define TEST_HPI            0x0100
#define TEST_MMC            0x0200
#define TEST_MS             0x0400
#define TEST_SFLASH         0x0800
#define TEST_NAND           0x1000
#define TEST_USB            0x2000
#define TEST_SPIROM         0x4000
#define TEST_IFLASH         0x8000

// External Bus Selection Register Values
#define EXBUSSEL_CLKOUTDIS  0x8000
#define EXBUSSEL_OSCDIS     0x4000
#define EXBUSSEL_EMIFX2     0x0100
#define EXBUSSEL_SP2MODE    0x0030
#define EXBUSSEL_SP1MODE    0x000c
#define EXBUSSEL_PPMODE     0x0003

#define EXBUSSEL_SPMODE_MCBSP  0x0
#define EXBUSSEL_SPMODE_MMC    0x1
#define EXBUSSEL_SPMODE_MS     0x3

#define EXBUSSEL_PPMODE_DATA   0x0
#define EXBUSSEL_PPMODE_FULL   0x1
#define EXBUSSEL_PPMODE_NONMUX 0x2
#define EXBUSSEL_PPMODE_MUX    0x3

// EMIF Registers
#define EMIF_EGCR           0x0800
#define EMIF_EMI_RST        0x0801
#define EMIF_EMI_BE         0x0802
#define EMIF_CE0_1          0x0803
#define EMIF_CE0_2          0x0804
#define EMIF_CE0_3          0x0805
#define EMIF_CE1_1          0x0806
#define EMIF_CE1_2          0x0807
#define EMIF_CE1_3          0x0808
#define EMIF_CE2_1          0x0809
#define EMIF_CE2_2          0x080A
#define EMIF_CE2_3          0x080B
#define EMIF_CE3_1          0x080C
#define EMIF_CE3_2          0x080D
#define EMIF_CE3_3          0x080E
#define EMIF_SDC1           0x080F
#define EMIF_SDPER          0x0810
#define EMIF_SDCNT          0x0811
#define EMIF_INIT           0x0812
#define EMIF_SDC2           0x0813

// EMIF Configuration Register Values
#define EGCR_MEMFREQ_MASK   0x0600
#define EGCR_WPE            0x0080
#define EGCR_MEMCEN         0x0020
#define EGCR_ARDY           0x0008
#define EGCR_HOLD           0x0004
#define EGCR_HOLDA          0x0002
#define EGCR_NOHOLD         0x0001

#define EGCR_MEMFREQ_0      0x0000
#define EGCR_MEMFREQ_1      0x0200

// Chip Enable Values for EMIF_CE*_*
#define CE1_MTYPE_MASK       0x7000
#define CE1_RDSETUP_MASK     0x0f00
#define CE1_RDSTROBE_MASK    0x00fc
#define CE1_RDHOLD_MASK      0x0003

#define CE1_MTYPE_ASYNC8     0x0000
#define CE1_MTYPE_ASYNC16    0x1000
#define CE1_MTYPE_ASYNC32    0x2000
#define CE1_MTYPE_SDRAM      0x3000
#define CE1_MTYPE_SBSRAM     0x4000
#define CE1_RDSETUP_2        0x0200
#define CE1_RDSTROBE_10      0x0028
#define CE1_RDHOLD_2         0x0002

#define CE2_RDXHOLD_MASK     0xc000
#define CE2_WRXHOLD_MASK     0x3000
#define CE2_WRSETUP_MASK     0x0f00
#define CE2_WRSTROBE_MASK    0x00fc
#define CE2_WRHOLD_MASK      0x0003

#define CE2_RDXHOLD_1        0x4000
#define CE2_WRXHOLD_1        0x1000
#define CE2_WRSETUP_2        0x0200
#define CE2_WRSTROBE_10      0x0028
#define CE2_WRHOLD_2         0x0002


// SDRAM Control Registers
#define SDRAM_TRC_MASK      0xf800
#define SDRAM_SDSIZE        0x0400
#define SDRAM_SDWID         0x0200
#define SDRAM_RFEN          0x0100
#define SDRAM_TRCD_MASK     0x00f0
#define SDRAM_TRP_MASK      0x000f
#define SDRAM_SDACC         0x0400
#define SDRAM_TMRD_MASK     0x0300
#define SDRAM_TRAS_MASK     0x00f0
#define SDRAM_TACTV_MASK    0x000f

#define SDRAM_TRC_8         0x4000
#define SDRAM_TRC_A         0x5800
#define SDRAM_TRCD_5        0x0050
#define SDRAM_TRP_2         0x0002
#define SDRAM_TRP_8         0x0008
#define SDRAM_TRAS_8        0x0080

// GPIO Pins
#define GPIO_0              0x0001
#define GPIO_1              0x0002
#define GPIO_2              0x0004
#define GPIO_3              0x0008
#define GPIO_4              0x0010
#define GPIO_5              0x0020
#define GPIO_6              0x0040
#define GPIO_7              0x0080

// CLKMD Values
#define CLKMD_IAI            0x4000
#define CLKMD_IOB            0x2000
#define CLKMD_TEST           0x1000
#define CLKMD_PLLMULT_MASK   0x0f80
#define CLKMD_PLLDIV_MASK    0x0060
#define CLKMD_PLLENABLE      0x0010
#define CLKMD_BYPASSDIV_MASK 0x000c
#define CLKMD_BREAKLN        0x0002
#define CLKMD_LOCK           0x0001

#define CLKMD_PLLMULT_2      0x0100
#define CLKMD_PLLMULT_4      0x0200
#define CLKMD_PLLMULT_8      0x0400
#define CLKMD_PLLMULT_10     0x0500
#define CLKMD_PLLDIV_1       0x0000
#define CLKMD_PLLDIV_2       0x0020
#define CLKMD_PLLDIV_3       0x0040
#define CLKMD_PLLDIV_4       0x0060
#define CLKMD_BYPASSDIV_1    0x0000
#define CLKMD_BYPASSDIV_2    0x0004
#define CLKMD_BYPASSDIV_4    0x000c

// I2C Values
#define ICOAR_MASK_7         0x007F
#define ICOAR_MASK_10        0x03FF
#define ICSAR_MASK_7         0x007F
#define ICSAR_MASK_10        0x03FF
#define ICOAR_OADDR          0x007f
#define ICSAR_SADDR          0x0050

#define I2C_SROM             0x0050
#define I2C_AIC23            0x001A
#define I2C_ADS7823          0x0048

#define ICSTR_BB             0x1000
#define ICSTR_RSFULL         0x0800
#define ICSTR_XSMT           0x0400
#define ICSTR_AAS            0x0200
#define ICSTR_AD0            0x0100
#define ICSTR_ICXRDY         0x0010
#define ICSTR_ICRRDY         0x0008
#define ICSTR_ARDY           0x0004
#define ICSTR_NACK           0x0002
#define ICSTR_AL             0x0001

#define ICMDR_FREE           0x4000
#define ICMDR_STT            0x2000
#define ICMDR_IDLEEN         0x1000
#define ICMDR_STP            0x0800
#define ICMDR_MST            0x0400
#define ICMDR_TRX            0x0200
#define ICMDR_XA             0x0100
#define ICMDR_RM             0x0080
#define ICMDR_DLB            0x0040
#define ICMDR_IRS            0x0020
#define ICMDR_STB            0x0010
#define ICMDR_FDF            0x0008
#define ICMDR_BC_MASK        0x0007

// ADC Values
#define ADCR_ADCSTART        0x8000
#define ADCR_CHSELECT_MASK   0x7000
#define ADCR_CHSELECT_0      0x0000

#define ADDR_ADCBUSY         0x8000
#define ADDR_CHSELECT_MASK   0x7000
#define ADDR_ADCDATA_MASK    0x03FF

#define ADDR_CHSELECT_0      0x0000
#define ADDR_CHSELECT_1      0x1000
#define ADDR_CHSELECT_2      0x2000
#define ADDR_CHSELECT_3      0x3000

#define ADCDR_SAMPDIV_MASK   0xFF00
#define ADCDR_CONVDIV_MASK   0x000F
#define ADCDR_SAMPDIV_80     0x5000
#define ADCDR_SAMPDIV_255    0xff00
#define ADCDR_CONVDIV_2      0x0000
#define ADCDR_CONVDIV_4      0x0001
#define ADCDR_CONVDIV_6      0x0002
#define ADCDR_CONVDIV_8      0x0003

#define ADCCR_IDLEEN         0x0100
#define ADCCR_SYSDIV_MASK    0x00FF
#define ADCCR_SYSDIV_3       0x0002


//  RTC Values

#define RTCINTR_UIP          0x0080
#define RTCINTR_RS           0x001f

#define RTCINTEN_SET         0x0080
#define RTCINTEN_PIE         0x0040
#define RTCINTEN_AIE         0x0020
#define RTCINTEN_UIE         0x0010
#define RTCINTEN_TM          0x0002

#define RTCINTFL_IRQF        0x0080
#define RTCINTFL_PF          0x0040
#define RTCINTFL_AF          0x0020
#define RTCINTFL_UF          0x0010

#define RTCSEC_SEC           0x007f
#define RTCMIN_MIN           0x007f
#define RTCHOUR_AMPM         0x0080
#define RTCHOUR_HR           0x003f
#define RTCDAYW_DAR          0x00f0
#define RTCDAYW_DAEN         0x0008
#define RTCDAYW_DAY          0x0007
#define RTCDAYM_DATE         0x003f
#define RTCMONTH_MONTH       0x001f
#define RTCYEAR_YEAR         0x00ff

// Timer Values
#define PRSC_PSC             0x3c00
#define PRSC_TDDR            0x000f

#define TCR_IDLE_EN          0x8000
#define TCR_INTEXT           0x4000
#define TCR_ERR_TIM          0x2000
#define TCR_FUNC             0x1800
#define TCR_TLB              0x0400
#define TCR_SOFT             0x0200
#define TCR_FREE             0x0100
#define TCR_PWID             0x00C0
#define TCR_ARB              0x0020
#define TCR_TSS              0x0010
#define TCR_CP               0x0008
#define TCR_POLAR            0x0004
#define TCR_DATOUT           0x0002

#define TCR_FUNC_OFF         0x0000
#define TCR_FUNC_TOUT        0x0800
#define TCR_FUNC_GPIO        0x1000
#define TCR_FUNC_EXTCLK      0x1800

#define TCR_PWID_1           0x0000
#define TCR_PWID_2           0x0040
#define TCR_PWID_4           0x0080
#define TCR_PWID_8           0x00C0

#define TCR_CP_PULSE         0x0000
#define TCR_CP_TOGGLE        0x0008

#define TCR_DATOUT_0         0x0000
#define TCR_DATOUT_1         0x0002

// MMC Values
#define CCTL_DMAEN         0x0100
#define CCTL_DATEG         0x00C0
#define CCTL_SPIEN         0x0020
#define CCTL_WIDTH         0x0004
#define CCTL_CMDRST        0x0002
#define CCTL_DATRST        0x0001

#define FCKCTL_IDLEEN      0x0100
#define FCKCTL_FDIV        0x000f
#define CLK_CLKEN          0x0100
#define CLK_CDIV           0x00ff

// MCBSP Values
#define SPCR1_DLB          0x8000
#define SPCR1_RJUST        0x6000
#define SPCR1_CLKSTP       0x1800
#define SPCR1_DXENA        0x0080
#define SPCR1_ABIS         0x0040
#define SPCR1_RINTM        0x0030
#define SPCR1_RSYNCERR     0x0008
#define SPCR1_RFULL        0x0004
#define SPCR1_RRDY         0x0002
#define SPCR1_RRST         0x0001

#define CLKSTP_DIS         0x0000
#define CLKSTP_NODELAY     0x1000
#define CLKSTP_DELAY       0x1800

#define SPCR2_FREE         0x0200
#define SPCR2_SOFT         0x0100
#define SPCR2_FRST         0x0080
#define SPCR2_GRST         0x0040
#define SPCR2_XINTM        0x0030
#define SPCR2_XSYNCERR     000008
#define SPCR2_XEMPTY       0x0004
#define SPCR2_XRDY         0x0002
#define SPCR2_XRST         0x0001

#define PCR_IDLE_EN        0x4000
#define PCR_XIOEN          0x2000
#define PCR_RIOEN          0x1000
#define PCR_FSXM           0x0800
#define PCR_FSRM           0x0400
#define PCR_CLKXM          0x0200
#define PCR_CLKRM          0x0100
#define PCR_SCLKME         0x0080
#define PCR_CLKS_STAT      0x0040
#define PCR_DX_STAT        0x0020
#define PCR_DR_STAT        0x0010
#define PCR_FSXP           0x0008
#define PCR_FSRP           0x0004
#define PCR_CLKXP          0x0002
#define PCR_CLKRP          0x0001

#define RCR1_RFRLEN1       0x7f00
#define RCR1_RWDLEN1       0x00e0

#define RCR2_RPHASE        0x8000
#define RCR2_RFRLEN2       0x7f00
#define RCR2_RWDLEN2       0x00e0
#define RCR2_RCOMPAND      0x0018
#define RCR2_RFIG          0x0004
#define RCR2_RDATDLY       0x0003

#define XCR1_XFRLEN1       0x7f00
#define XCR1_XWDLEN1       0x00e0

#define XCR2_XPHASE        0x8000
#define XCR2_XFRLEN2       0x7f00
#define XCR2_XWDLEN2       0x00e0
#define XCR2_XCOMPAND      0x0018
#define XCR2_XFIG          0x0004
#define XCR2_XDATDLY       0x0003

#define RDATDLY_0          0x0000
#define RDATDLY_1          0x0001
#define RDATDLY_2          0x0002

#define RFRLEN1_1          0x0000

#define RWDLEN1_8          0x0000
#define RWDLEN1_12         0x0020
#define RWDLEN1_16         0x0040
#define RWDLEN1_20         0x0060
#define RWDLEN1_24         0x0080
#define RWDLEN1_32         0x00a0

#define RPHASE_SINGLE      0x0000
#define RPHASE_DUAL        0x8000

#define XDATDLY_0          0x0000
#define XDATDLY_1          0x0001
#define XDATDLY_2          0x0002

#define XFRLEN1_1          0x0000

#define XWDLEN1_8          0x0000
#define XWDLEN1_12         0x0020
#define XWDLEN1_16         0x0040
#define XWDLEN1_20         0x0060
#define XWDLEN1_24         0x0080
#define XWDLEN1_32         0x00a0

#define XPHASE_SINGLE      0x0000
#define XPHASE_DUAL        0x8000

#define SRGR1_FWID         0xff00
#define SRGR1_CLKGDV       0x00ff
#define SRGR2_GSYNC        0x8000
#define SRGR2_CLKSP        0x4000
#define SRGR2_CLKSM        0x2000
#define SRGR2_FSGM         0x1000
#define SRGR2_FPER         0x0fff

// Error Codes
#define ERR_FLASH_MFGID      0x0001
#define ERR_FLASH_ERASE      0x0002
#define ERR_FLASH_PROGRAM    0x0004
#define ERR_FLASH_READ       0x0008
#define ERR_FLASH_VERIFY     0x0010
#define ERR_FLASH_BADBLK     0x0020
#define ERR_FLASH_MAXBAD     0x0040
#define ERR_SFLASH_SIZE      0x0001
#define ERR_SFLASH_ERASE     0x0002
#define ERR_SFLASH_PROGRAM   0x0004
#define ERR_SFLASH_READ      0x0008
#define ERR_SFLASH_VERIFY    0x0010

#define ERR_RTC_FAIL         0x1001

#define ERR_SROM_FAIL        0x2001

#define ERR_SPIROM_VERIFY    0x3001


// Flash Status Register Definitions
#define FSTATUS_FAIL         0x0001
#define FSTATUS_READY        0x0040
#define FSTATUS_NOWP         0x0080

// Memory mapped register definitions
#define ST0_55               ((unsigned short *)0x2)
#define ST1_55               ((unsigned short *)0x3)
#define ST2_55               ((unsigned short *)0x4b)
#define ST3_55               ((unsigned short *)0x4)
#define IER0                 ((unsigned short *)0x0)
#define IFR0                 ((unsigned short *)0x1)
#define IER1                 ((unsigned short *)0x45)
#define IFR1                 ((unsigned short *)0x46)
#define IVPD                 ((unsigned short *)0x49)
#define IVPH                 ((unsigned short *)0x4a)

// Reset vector table offsets
#define VEC_RESET            0
#define VEC_NMI              1
#define VEC_INT0             2
#define VEC_INT2             3
#define VEC_TINT0            4
#define VEC_RINT0            5
#define VEC_RINT1            6
#define VEC_XINT1            7
#define VEC_USB              8
#define VEC_DMAC1            9
#define VEC_DSPINT           10
#define VEC_INT3             11
#define VEC_RINT2            12
#define VEC_XINT2            13
#define VEC_DMAC4            14
#define VEC_DMAC5            15
#define VEC_INT1             16
#define VEC_XINT0            17
#define VEC_DMAC0            18
#define VEC_INT4             19
#define VEC_DMAC2            20
#define VEC_DMAC3            21
#define VEC_TINT1            22
#define VEC_I2C              23
#define VEC_BERR             24
#define VEC_DLOG             25
#define VEC_RTOS             26
#define VEC_SINT27           27
#define VEC_SINT28           28
#define VEC_SINT29           29
#define VEC_SINT30           30
