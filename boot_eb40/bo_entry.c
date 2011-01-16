//*-----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*-----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*-----------------------------------------------------------------------------
//* File Name           : bo_entry.c
//* Object              : Main loop of AT91EB40 test
//*
//* 1.0 04/09/98 JLV    : Creation
//* 2.0 21/10/98 JCZ    : Clean up.
//*-----------------------------------------------------------------------------

#include "std_c.h"
#include "usart.h"
#include "pio.h"
#include "r40807.h"

#include "at91eb40.h"       /* AT91EB40 description */

#define asmlinkage
//#define ADDR_ANGEL      0x01002000

extern void BootLoad ( void ) ;
extern void BootFts (void ) ;
extern int BootFlash ( void ) ;

extern void sram_addr(void);
extern void addr_angel(void);

//*----------------------------------------------------------------------------
//* Function Name           : BootEntry
//* Object                  : Entry point of boot
//* Input Parameters        : None
//* Output Parameters       : None
//* Functions called        :
//*----------------------------------------------------------------------------
u_int bo_start(void)
//* Begin
{
    //* -- Set up PIO
    PIO_BASE->PIO_PDR  = PERIPHERAL;
    PIO_BASE->PIO_OER  = PIO_OUT;
    PIO_BASE->PIO_CODR = PIO_OUT;           /* Turn LEDs off */
    PIO_BASE->PIO_IDR  = 0xFFFFFFFF;        /* Disable PIO interrupts */

    //* Repeat for ever
    for (;;)
    {
        //* If SW4 button pressed, Load in SRAM
        if (PIO_BASE->PIO_PDSR & SW4)
        {
            //* Expect SW3 un-pressed
            PIO_BASE->PIO_SODR = LED1;
            BootLoad();
	    PIO_BASE->PIO_SODR = LED3;
	    sram_addr();
        }//* EndIf

        //* If SW3 button pressed, Functional Test Software
        if (PIO_BASE->PIO_PDSR & SW3)
        {
            //* Expect SW4 un-pressed
            PIO_BASE->PIO_SODR = LED1_2_3;
            while (PIO_BASE->PIO_PDSR & SW3);
            PIO_BASE->PIO_CODR = LED1_2_3;
            BootFts();
        }//* EndIf
		
/*
		// If SW5 button pressed, Flash Test
		if (PIO_BASE->PIO_PDSR & SW5)
		{
		    // Expect SW5 un-pressed
		    PIO_BASE->PIO_SODR = LED1_3;
		    while (PIO_BASE->PIO_PDSR & SW5);
		    PIO_BASE->PIO_CODR = LED1_3;
		    BootFlash();
		}// EndIf
*/
        //* If no button pressed, Angel
        PIO_BASE->PIO_SODR = LED2;
        addr_angel();	//((void(*)())ADDR_ANGEL)();

    }//* EndRepeat

//* End
}
