/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : tc.inc
;- Object               : Assembler Timer Counter Definition File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;----------------------------------------------------
; Timer Counter  User Interface Structure Definition
;----------------------------------------------------*/
/*                ^       0
TC_CCR          #       4           ;- Channel Control Register
TC_CMR          #       4           ;- Channel Mode Register
                #       4           ;- Reserved 0
                #       4           ;- Reserved 1
TC_CV           #       4           ;- Counter Value
TC_RA           #       4           ;- Register A
TC_RB           #       4           ;- Register B
TC_RC           #       4           ;- Register C
TC_SR           #       4           ;- Status Register
TC_IER          #       4           ;- Interrupt Enable Register
TC_IDR          #       4           ;- Interrupt Disable Register
TC_IMR          #       4           ;- Interrupt Mask Register
                #       4           ;- Reserved 2
                #       4           ;- Reserved 3
                #       4           ;- Reserved 4
                #       4           ;- Reserved 5
TC_SIZE         #       0*/

/*;------------------------------
; Timer Counter Block Structure
;------------------------------*/
#define NB_TC_CHANNEL	3

/*                ^       0
TC0             #       TC_SIZE
TC1             #       TC_SIZE
TC2             #       TC_SIZE
TC_BCR          #       4
TC_BMR          #       4*/

/*;---------------------------------------------------------
;- TC_CCR: Timer Counter Control Register Bits Definition
;---------------------------------------------------------*/

#define TC_CLKEN	0x1             /*;- Counter Clock Enable*/
#define TC_CLKDIS	0x2             /*;- Counter Clock Disable*/
#define TC_SWTRG	0x4             /*;- Software Trigger*/

/*;------------------------------------------------------
;- TC_CMR: Timer Counter Mode Register Bits Definition
;------------------------------------------------------*/

#define TC_TCCLKS	0x00000007      /*;- Clock Selection*/
#define TC_CLKI		0x00000008      /*;- Clock Inversion*/
#define TC_BURST	0x00000030      /*;- Burst Signal Selection*/

#define TC_LDBSTOP	0x00000040      /*;- Capture Mode : Counter Clock Stopped with RB Loading*/
#define TC_CPCSTOP	0x00000040      /*;- Waveform Mode : Counter Clock Stopped with RC Compare*/

#define TC_LDBDIS	0x00000080      /*;- Capture Mode : Counter Clock Disabled with RB Loading*/
#define TC_CPCDIS	0x00000080      /*;- Waveform Mode : Counter Clock Disabled with RC Compare*/

#define TC_ETRGEDG	0x00000300      /*;- Capture Mode : External Trigger Edge Selection*/
#define TC_EEVTEDG	0x00000300      /*;- Waveform Mode : External Event Edge Selection*/

#define TC_ABETRG	0x00000400      /*;- Capture Mode : TIOA or TIOB External Trigger Selection*/

#define TC_EEVT		0x00000C00      /*;- Waveform Mode : External Event Selection*/
#define TC_ENETRG	0x00001000      /*;- Waveform Mode : Enable Trigger on External Event*/
#define TC_CPCTRG	0x00004000      /*;- RC Compare Enable Trigger Enable*/
#define TC_WAVE		0x00008000      /*;- Mode Selection*/
#define TC_LDRA		0x00030000      /*;- Capture Mode : RA Loading Selection*/
#define TC_ACPA		0x00030000      /*;- Waveform Mode : RA Compare Effect on TIOA*/
#define TC_LDRB		0x000C0000      /*;- Capture Mode : RB Loading Selection*/
#define TC_ACPC		0x000C0000      /*;- Waveform Mode : RC Compare Effect on TIOA*/
#define TC_AEEVT	0x00300000      /*;- Waveform Mode : External Event Effect on TIOA*/
#define TC_ASWTRG	0x00C00000      /*;- Waveform Mode : Software Trigger Effect on TIOA*/
#define TC_BCPB		0x03000000      /*;- Waveform Mode : RB Compare Effect on TIOB*/
#define TC_BCPC		0x0C000000      /*;- Waveform Mode : RC Compare Effect on TIOB*/
#define TC_BEEVT	0x30000000      /*;- Waveform Mode : External Event Effect on TIOB*/
#define TC_BSWTRG	0xC0000000      /*;- Waveform Mode : Software Trigger Effect on TIOB*/

/*;------------------------------------------------
;- TC_SR: Timer Counter Status Register Bits Definition
;------------------------------------------------*/

#define TC_COVFS	0x01        /*;- Counter Overflow Status*/
#define TC_LOVRS	0x02        /*;- Load Overrun Status*/
#define TC_CPAS		0x04        /*;- RA Compare Status*/
#define TC_CPBS		0x08        /*;- RB Compare Status*/
#define TC_CPCS		0x10        /*;- RC Compare Status*/
#define TC_LDRAS	0x20        /*;- RA Loading Status*/
#define TC_LDRBS	0x40        /*;- RB Loading Status*/
#define TC_ETRGS	0x80        /*;- External Trigger Status*/
#define TC_CLKSTA	0x10000     /*;- Clock Status*/
#define TC_MTIOA	0x20000     /*;- TIOA Mirror*/
#define TC_MTIOB	0x40000     /*;- TIOB Status*/

/*;----------------------------------------------------------------
;- TC_BCR: Timer Counter Block Control Register Bits Definition
;----------------------------------------------------------------*/

#define TC_SYNC		0x1         /*;- Synchronisation Trigger*/

/*;------------------------------------------------------------
;- TC_BMR: Timer Counter Block Mode Register Bits Definition
;------------------------------------------------------------*/

#define TC_TC0XC0S	(0x3<<0)     /*;- External Clock Signal 0 Selection*/
#define TC_TC1XC1S	(0x3<<2)     /*;- External Clock Signal 1 Selection*/
#define TC_TC2XC2S	(0x3<<4)     /*;- External Clock Signal 2 Selection*/

/*;- Timer Counter Channel Descriptor Structure
                        ^       0
TCDesc_TCBase           #       4       ;- Peripheral base address
TCDesc_PioCtrl          #       4       ;- IO controller descriptor
TCDesc_AsmTCHandler     #       4       ;- Assembly interrupt handler
TCDesc_TCHandler        #       4
TCDesc_PeriphId         #       1       ;- Peripheral Identifier
TCDesc_PioTioa          #       1       ;- TIOA pin number in the PIO
TCDesc_PioTiob          #       1       ;- TIOB pin number in the PIO
TCDesc_PioTclk          #       1       ;- TCLK pin number in the PIO

            END*/
