/*;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;------------------------------------------------------------------------------
;- File Name            : usart.inc
;- Object               : Assembler USART Definition File.
;-
;- 1.0 01/04/00 JCZ     : Creation
;------------------------------------------------------------------------------*/

/*;-------------------------------------------
; USART User Interface Structure Definition
;-------------------------------------------*/
/*                ^       0
US_CR           #       4       ;- Control Register
US_MR           #       4       ;- Mode Register
US_IER          #       4       ;- Interrupt Enable Register
US_IDR          #       4       ;- Interrupt Disable Register
US_IMR          #       4       ;- Interrupt Mask Register
US_CSR          #       4       ;- Channel Status Register
US_RHR          #       4       ;- Receive Holding Register
US_THR          #       4       ;- Transmit Holding Register
US_BRGR         #       4       ;- Baud Rate Generator Register
US_RTOR         #       4       ;- Receiver Timeout Register
US_TTGR         #       4       ;- Transmitter Time-guard Register
                #       4       ;- Reserved
US_RPR          #       4       ;- Receiver Pointer Register
US_RCR          #       4       ;- Receiver Counter Register
US_TPR          #       4       ;- Transmitter Pointer Register
US_TCR          #       4       ;- Transmitter Counter Register*/

/*;---------------------------
;- US_CR : Control Register
;---------------------------*/
#define US_RSTRX	0x0004      /*;- Reset Receiver*/
#define US_RSTTX	0x0008      /*;- Reset Transmitter*/
#define US_RXEN 	0x0010      /*;- Receiver Enable*/
#define US_RXDIS	0x0020      /*;- Receiver Disable*/
#define US_TXEN		0x0040      /*;- Transmitter Enable*/
#define US_TXDIS	0x0080      /*;- Transmitter Disable*/
#define US_RSTSTA	0x0100      /*;- Reset Status Bits*/
#define US_STTBRK	0x0200      /*;- Start Break*/
#define US_STPBRK	0x0400      /*;- Stop Break*/
#define US_STTTO	0x0800      /*;- Start Time-out*/
#define US_SENDA	0x1000      /*;- Send Address*/

/*;------------------------
;- US_MR : Mode Register
;------------------------*/

#define US_CLKS		0x0030      /*;- Clock Selection*/
#define US_CLKS_MCKI	0x00        /*;- Master Clock*/
#define US_CLKS_MCKI8	0x10        /*;- Master Clock divided by 8*/
#define US_CLKS_SCK	0x20        /*;- External Clock*/
#define US_CLKS_SLCK	0x30        /*;- Slow Clock*/

#define US_CHRL		0x00C0      /*;- Byte Length*/
#define US_CHRL_5	0x00        /*;- 5 bits*/
#define US_CHRL_6	0x40        /*;- 6 bits*/
#define US_CHRL_7	0x80        /*;- 7 bits*/
#define US_CHRL_8	0xC0        /*;- 8 bits*/

#define US_SYNC		0x0100      /*;- Synchronous Mode Enable*/

#define US_PAR		0x0E00      /*;- Parity Mode*/
#define US_PAR_EVEN	0x00        /*;- Even Parity*/
#define US_PAR_ODD	0x20        /*;- Odd Parity*/
#define US_PAR_SPACE	0x40        /*;- Space Parity to 0*/
#define US_PAR_MARK	0x60        /*;- Marked Parity to 1*/
#define US_PAR_NO	0x80        /*;- No Parity*/
#define US_PAR_MULTIDROP	0xA0        /*;- Multi-drop Mode*/

#define US_NBSTOP	0x3000      /*;- Stop Bit Number*/
#define US_NBSTOP_1	0x0000      /*;- 1 Stop Bit*/
#define US_NBSTOP_1_5	0x1000      /*;- 1.5 Stop Bits*/
#define US_NBSTOP_2	0x2000      /*;- 2 Stop Bits*/

#define US_CHMODE			0xC000  /*;- Channel Mode*/
#define US_CHMODE_NORMAL		0x0000  /*;- Normal Mode*/
#define US_CHMODE_AUTOMATIC_ECHO	0x4000  /*;- Automatic Echo*/
#define US_CHMODE_LOCAL_LOOPBACK	0x8000  /*;- Local Loopback*/
#define US_CHMODE_REMOTE_LOOPBACK	0xC000  /*;- Remote Loopback*/

#define US_MODE9	0x20000     /*;- 9 Bit Mode*/

#define US_CLKO		0x40000     /*;- Baud Rate Output Enable*/

/*;------------------------------------------------------------------
;-  US_IER, US_IDR, US_IMR, US_IMR: Status and Interrupt Registers
;------------------------------------------------------------------*/

#define US_RXRDY	0x001       /*;- Receiver Ready*/
#define US_TXRDY	0x002       /*;- Transmitter Ready*/
#define US_RXBRK	0x004       /*;- Receiver Break*/
#define US_ENDRX	0x008       /*;- End of Receiver PDC Transfer*/
#define US_ENDTX	0x010       /*;- End of Transmitter PDC Transfer*/
#define US_OVRE		0x020       /*;- Overrun Error*/
#define US_FRAME	0x040       /*;- Framing Error*/
#define US_PARE		0x080       /*;- Parity Error*/
#define US_TIMEOUT	0x100       /*;- Receiver Timeout*/
#define US_TXEMPTY	0x200       /*;- Transmitter Empty*/

/*;------------------------------
;- USART Descriptor Structure
;------------------------------
                            ^       0
UsartDesc_UsartBase         #       4       ;- Peripheral base address
UsartDesc_PioCtrl           #       4       ;- IO controller descriptor
UsartDesc_PinRXD            #       1       ;- RXD pin number in the PIO
UsartDesc_PinTXD            #       1       ;- TXD pin number in the PIO
UsartDesc_PinSCK            #       1       ;- SCK pin number in the PIO
UsartDesc_PeriphId          #       1       ;- USART Peripheral Identifier

                END*/
