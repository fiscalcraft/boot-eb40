/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : ebi.inc
;- Object               : Assembler External Bus Interface Definition File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;--------------------------------------------------------
;- Memory Controller User Interface Structure Definition
;--------------------------------------------------------*/
/*                    ^       0
EBI_CSR             #       4*8         ; Chip Select Register
EBI_RCR             #       4           ; Remap Command Register
EBI_MCR             #       4           ; Memory Control Register*/

/*;---------------------------------
;- EBI_CSR: Chip Select Registers
;---------------------------------*/

#define EBI_DBW		0x03        /*;- Data Bus Width*/
#define EBI_NWS		0x1C        /*;- Number of Wait States*/
#define EBI_WSE		0x20        /*;- Wait State Enable*/
#define EBI_PAGES	0x180       /*;- Page size*/
#define EBI_TDF		0xE00       /*;- Number of Data Float Output Time Clock Cycle*/
#define EBI_BAT		0x1000      /*;- Byte Access Type*/
#define EBI_CSE		0x2000      /*;- Chip Select Enable*/
#define EBI_BA		0xFFF00000  /*;- Base Address*/

/*;----------------------------------
;- EBI_RCR: Remap Control Register
;----------------------------------*/

#define EBI_RCB		0x01    /*; Remap Command Bit*/

/*;-----------------------------------
;- EBI_MCR: Memory Control Register
;-----------------------------------*/

#define EBI_ALE		0x07    /*;- Address Line Enable*/
#define EBI_DRP		0x10    /*;- Data Read Protocol*/

/*;------------------
;- EBI Base Address
;------------------*/
#define EBI_BASE	0xFFE00000      /*;- External Bus Interface*/

/*                END*/
