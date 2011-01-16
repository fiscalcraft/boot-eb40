/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : aic.inc
;- Object               : Assembler Advanced Interrupt Controller Definition File.
;-
;- 1.0 01/04/00 JCZ     :Creation
;------------------------------------------------------------------------------

;------------------------------------------
;- AIC User Interface Structure Definition
;------------------------------------------*/
/*                    ^       0
AIC_SMR             #       32*4        ;- Source Mode Register
AIC_SVR             #       32*4        ;- Source Vector Register
AIC_IVR             #       4           ;- IRQ Vector Register
AIC_FVR             #       4           ;- FIQ Vector Register
AIC_ISR             #       4           ;- Interrupt Status Register
AIC_IPR             #       4           ;- Interrupt Pending Register
AIC_IMR             #       4           ;- Interrupt Mask Register
AIC_CISR            #       4           ;- Core Interrupt Status Register
                    #       4           ;- Reserved 0
                    #       4           ;- Reserved 1
AIC_IECR            #       4           ;- Interrupt Enable Command Register
AIC_IDCR            #       4           ;- Interrupt Disable Command Register
AIC_ICCR            #       4           ;- Interrupt Clear Command Register
AIC_ISCR            #       4           ;- Interrupt Set Command Register
AIC_EOICR           #       4           ;- End of Interrupt Command Register
AIC_SPU             #       4           ;- Spurious Vector Register
*/
/*;---------------------------------------------
;- AIC_SMR[]: Interrupt Source Mode Registers
;---------------------------------------------*/

#define AIC_PRIOR			0x07    /*;- Priority*/

#define AIC_SRCTYPE			0x60    /*;- Source Type Definition*/
#define AIC_SRCTYPE_INT_LEVEL_SENSITIVE	0x00    /*;- Level Sensitive*/
#define AIC_SRCTYPE_INT_EDGE_TRIGGERED	0x40    /*;- Edge Triggered*/
#define AIC_SRCTYPE_EXT_LOW_LEVEL	0x00    /*;- Low Level*/
#define AIC_SRCTYPE_EXT_NEGATIVE_EDGE	0x40    /*;- Negative Edge*/
#define AIC_SRCTYPE_EXT_HIGH_LEVEL	0x80    /*;- High Level*/
#define AIC_SRCTYPE_EXT_POSITIVE_EDGE	0x60    /*;- Positive Edge*/

/*;--------------------------------------
;-  AIC_ISR: Interrupt Status Register
;--------------------------------------*/

#define AIC_IRQID			0x1F            /*;- Current source interrupt*/

/*;-------------------------------------------
;- AIC_CISR: Interrupt Core Status Register
;-------------------------------------------*/

#define AIC_NFIQ 			0x01            /*;- Core FIQ Status*/
#define AIC_NIRQ			0x02            /*;- Core IRQ Status*/

/*;--------------------------------------------
;- Advanced Interrupt COntroller BAse Address
;--------------------------------------------*/

#define AIC_BASE			0xFFFFF000


  /*          END*/
