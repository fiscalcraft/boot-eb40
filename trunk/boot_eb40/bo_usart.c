//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : bo_usart.c
//* Object              : USART management for Boot AT91EB40
//*
//* 1.0 06/04/00 JPP    : Creation
//*----------------------------------------------------------------------------

#include "std_c.h"
#include "usart.h"
#include "r40807.h"

#include "at91eb40.h"       /* AT91EB40 description */

//*----------------------------------------------------------------------------
//* Function Name       : init_usart
//* Object              : Initialize an USART.
//* Input Parameters    : <usart_id> = the USART to initialize
//*                     : <mode> = the Mode Register to be programmed
//*                     : <speed> = the BRDR to be programmed
//*                     : <timeguard> = the TTGR to be programmed
//* Output Parameters   : TRUE if USART number is correct, else, FALSE
//* Functions called    : None
//*----------------------------------------------------------------------------
u_int init_usart ( u_int usart_id, u_int mode, u_int speed, u_int timeguard )
//* Begin
{
    StructUSART *ad_usart;

    ad_usart = (usart_id == 0 ? USART0_BASE : USART1_BASE);

    //* Reset receiver and transmitter
    ad_usart->US_CR = US_RSTRX | US_RSTTX | US_RXDIS | US_TXDIS ;

    //* Clear Transmit and Receive Counters
    ad_usart->US_RCR = 0 ;
    ad_usart->US_TCR = 0 ;

    //* Define the baud rate divisor register
    ad_usart->US_BRGR = speed ;

    //* Define the USART mode
    ad_usart->US_MR = mode  ;

    //* Write the Timeguard Register
    ad_usart->US_TTGR = timeguard ;

    //* Enable receiver and transmitter
    ad_usart->US_CR = US_RXEN | US_TXEN ;

    //* Return true
    return ( TRUE ) ;
}
//* End

//*----------------------------------------------------------------------------
//* Function Name       : disable_usart
//* Object              : Disable an USART.
//* Input Parameters    : <usart_id> = the USART to disable
//* Output Parameters   : True if <usart_id> is correct
//* Functions called    : None
//*----------------------------------------------------------------------------
u_int disable_usart ( u_int usart_id )
//* Begin
{
    StructUSART *ad_usart;

    ad_usart = (usart_id == 0 ? USART0_BASE : USART1_BASE);

    //* Disable all interrupts
    ad_usart->US_IDR = 0xFFFFFFFF ;

    //* Abort the Peripheral Data Transfers
    ad_usart->US_RCR = 0 ;
    ad_usart->US_TCR = 0 ;

    //* Disable receiver and transmitter and stop any activity immediately
    ad_usart->US_CR = US_TXDIS | US_RXDIS | US_RSTTX | US_RSTRX ;

    //* Return true
    return ( TRUE ) ;
}
//* End

//*----------------------------------------------------------------------------
//* Function Name       : receive_frame
//* Object              : Receive a complete frame.
//* Input Parameters    : <usart_id> = the USART where receive the byte
//*                     : <pt_buffer> = the address of the receive buffer
//*                     : <max_size> = the maximum number of bytes to be
//*                     : received
//*                     : <timeout> = the inter-character time delay in
//*                     : number of byte
//* Output Parameters   : True if <usart_id> is correct
//* Functions called    : none
//*----------------------------------------------------------------------------
u_int receive_frame ( u_int usart_id, char *pt_buffer, u_int max_size, u_int timeout )
//* Begin
{
    StructUSART *ad_usart;

    ad_usart = (usart_id == 0 ? USART0_BASE : USART1_BASE);

    //* Store the timeout value
    ad_usart->US_RTOR = (timeout * 10 / 4) ;
    //* Restart the timeout logic
    ad_usart->US_CR = US_STTTO ;
    //* Store the address of the buffer
    ad_usart->US_RPR = 0x02000000;	//(u_int) pt_buffer ;
    //* Store the number of bytes to transmit
    ad_usart->US_RCR = 0xFFFF;	//max_size ;
    //* Return true
    return ( TRUE ) ;
}

u_int next_frame0 (void)
{
//	ad_usart = USART0_BASE;
	((StructUSART*)USART0_BASE)->US_CR = US_STTTO;
	((StructUSART*)USART0_BASE)->US_RCR = 0xFFFF;
	if (((StructUSART*)USART0_BASE)->US_RPR & 1) return (TRUE);
	else return (FALSE);
}
#define END_RX	1
#define RX_TMO	2
u_int is_receive0_done (void)
{
//	StructUSART *ad_usart = USART0_BASE;
	if (((StructUSART*)USART0_BASE)->US_CSR & 0x8) return (END_RX);
	if (((StructUSART*)USART0_BASE)->US_CSR & 0x100) return (RX_TMO);
	return (0);
}
//* End
