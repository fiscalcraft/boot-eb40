/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : sf.inc
;- Object               : Assembler Special Function Definition File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;---------------------------------------------------------
; Chip Identification User Interface Structure Definition
;---------------------------------------------------------*/
/*                ^       0
SF_CIDR         #       4       ;- Chip ID Register
SF_EXID         #       4       ;- Chip ID Extension Register
SF_RSR          #       4       ;- Reset Status Register
                #       4       ;- Reserved 0
                #       4       ;- Reserved 1
                #       4       ;- Reserved 2
SF_PMR          #       4       ;- Protect Mode Register*/

/*;--------------------------------------------------------
;- SF_CIDR: Chip Identification Register Bits Definition
;--------------------------------------------------------*/

#define SF_VERSION	0x0000001F      /*;- Version Number*/
#define SF_NVPSIZ	0x00000F00      /*;- Non Volatile Program Memory Size*/
#define SF_NVDSIZ	0x0000F000      /*;- Non Volatile Data Memory Size*/
#define SF_VDSIZ	0x000F0000      /*;- Volatile Data Memory Size*/
#define SF_ARCH		0x0FF00000      /*;- Architecture Code*/
#define SF_NVPTYP	0x70000000      /*;- Non Volatile Program Memory Type*/
#define SF_EXT		0x10000000      /*;- Extension Flag*/

/*;---------------------------------------
;- SF_RSR: Reset Status Flag Definition
;---------------------------------------*/

#define SF_EXT_RESET	0x6C            /*;- External pin Cause Reset*/
#define SF_WD_RESET	0x53            /*;- Internal WatchDog Cause Reset*/

/*;--------------------------------
;- SF_PMR: Protect Mode Register
;--------------------------------*/

#define SF_AIC		0x20            /*;- Protect Mode Enable*/

/*;-------------------------------
;- Special Function Base Address 
;-------------------------------*/

#define SF_BASE		0xFFF00000

   /*     END*/
