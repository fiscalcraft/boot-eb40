//*-----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*-----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*-----------------------------------------------------------------------------
//* File Name           : bo_flash.c
//* Object              : AT91EB40 Flash Test
//* Translator          : ARM Software Development Toolkit V2.50
//* Exported resources  : BootFlash
//* Imported resources  : timer_init - delay_one_tick - blink_led
//
//* 1.0 13/01/99 JLV    : Creation
//* 2.0 10/04/00 JCZ    : Clean Up
//*-----------------------------------------------------------------------------

/*----- Called Macro instructions definition -----*/
/* None */

/*----- Files to be included Definition -----*/

#include "periph\stdc\std_c.h"
#include "periph\usart\usart.h"
#include "periph\pio\pio.h"
#include "parts\r40807\r40807.h"

#include "at91eb40.h"       /* AT91EB40 description */

/*----- Types and Constants Definition -----*/
#define FLASH_SIZE  0x00020000

/*----- Imported Resources Definition -----*/

u_int VerifyFlash (u_int ram, u_int sram, u_int flash, u_int size);

/*---- Internal Resources Definition -----*/
/* None */

/*---- External Resources Definition -----*/

extern void delay_one_tick ( void ) ;
extern void blink_led( int led, int nb ) ;
extern void timer_init ( void ) ;


//*----------------------------------------------------------------------------
//* Function Name           : BootFlash
//* Object                  : expect an user action, and start the test
//* Input Parameters        : None
//* Output Parameters       : None
//* Functions called        : timer_init, delay_one_tick, blink_led
//*----------------------------------------------------------------------------
void BootFlash ( void )
//* Begin
{
    u_int *ptr;
    u_int *pt0;
    u_int *pt1;
    u_int flash_base = (EBI_BASE->EBI_CSR[0] & 0xFFFF0000);
    u_int sram_base  = (EBI_BASE->EBI_CSR[1] & 0xFFFF0000);

    //* -- Set up Timers
    timer_init();

    //* Repeat for ever
    for (;;)
    {
        //* Ligth on LED amber
        PIO_BASE->PIO_SODR = LED2;
        //* Execute the flash test
        for (pt0 = (u_int *)flash_base, pt1 = (u_int *)sram_base;
                pt0 < (u_int *)(flash_base + FLASH_SIZE);
                pt0++, pt1++)
        {
            *((u_int *)pt1) = *((u_int *)pt0);
        }
        ptr = (u_int *)VerifyFlash (0x0100, sram_base, flash_base, FLASH_SIZE);
        //* Ligth off LED amber
        PIO_BASE->PIO_CODR = LED2;
        //* IF (error)
        if (ptr != (u_int *)0)
        {
            //* Ligth on LED red
            PIO_BASE->PIO_SODR = LED1;
            //* Read addr while button not pressed
            do
            {
                u_int   dummy;
                dummy = *ptr;
            }
            while (!(PIO_BASE->PIO_PDSR & SW4));
            while (PIO_BASE->PIO_PDSR & SW4);
            //* Ligth off 'led' and wait DELAY
            PIO_BASE->PIO_CODR = LED1;
        //* ELSE
        }
        else
        {
            //* Blink LED3 to inform the user
            blink_led (LED3, 1);
        //* ENDIF
        }
    //* EndRepeat
    }

//* End
}
