/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : wd.inc
;- Object               : Assembler Watch Dog Definition File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------

;-----------------------------------------------
; Watch Dog User Interface Structure Definition
;-----------------------------------------------*/
/*                    ^       0
WD_OMR              #       4           ;- Overflow Mode Register
WD_CMR              #       4           ;- Counter Mode Register
WD_CR               #       4           ;- Control Register
WD_SR               #       4           ;- Status Register
                    #       4           ;- Reserved
WD_TLR              #       4           ;- Test Load Register : test purpose only*/

/*;-----------------------------------------------------------
;- WD_OMR: Watch Dog Overflow Mode Register Bits Definition
;-----------------------------------------------------------*/

#define WD_WDEN             EQU     0x01        /*;- Watch Dog Enable*/
#define WD_RSTEN            EQU     0x02        /*;- Internal Reset Enable*/
#define WD_IRQEN            EQU     0x04        /*;- Interrupt Enable*/
#define WD_EXTEN            EQU     0x08        /*;- External Signal Enable*/
#define WD_OKEY             EQU     0x2340      /*;- Overflow Mode Register Access Key*/

/*;---------------------------------------------------
;- WD_CMR: Watch Dog Clock Register Bits Definition
;---------------------------------------------------*/

#define WD_WDCLKS           EQU     0x03        /*;- Clock Selection*/
#define WD_WDCLKS_MCK8      EQU     0x0
#define WD_WDCLKS_MCK32     EQU     0x1
#define WD_WDCLKS_MCK128    EQU     0x2
#define WD_WDCLKS_MCK1024   EQU     0x3

#define WD_HPCV             EQU     (0x0F<<2)    /*;- High Preload Counter Value*/

#define WD_CKEY             EQU     (0x06E<<7)   /*;- Clock Register Access Key*/

/*;----------------------------------------------------
;- WD_CR: Watch Dog Control Register Bits Definition
;----------------------------------------------------*/

#define WD_RSTKEY           EQU     0xC071      /*;- Watch Dog Restart Key*/

/*;---------------------------------------------------
;- WD_SR: Watch Dog Status Register Bits Definition
;---------------------------------------------------*/

#define WD_WDOVF            EQU     0x1         /*;- WatchDog Overflow Status*/


/*;----------------------------------------------------
;-  WD_TLR: Test Load Register for test purpose only
;----------------------------------------------------*/

#define WD_TMRKEY           EQU     0xD64A0000  /*;- Access Key*/
#define WD_TESTEN           EQU     0x2         /*;- Test Mode Enable*/


           /*     END*/
