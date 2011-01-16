//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : bo_load.c
//* Object              : Load program in RAM
//*
//* Imported resources  : 
//*     init_usart
//*     disable_usart
//*     receive_frame
//*     define_as_pio
//*     define_as_input
//*     read_pio_pin
//* Exported resources  : BootLoad
//*
//* 1.0 06/04/00 JPP    : Creation
//*----------------------------------------------------------------------------

#include "std_c.h"
#include "pio.h"
#include "usart.h"
#include "r40807.h"

#include "at91eb40.h"       /* AT91EB40 description */

/* Hardware description */
#define NB_USART            2
#define PIO_IRQ0    (9)
#define BUFFER_SIZE (0xFFFF)

extern u_int init_usart ( u_int usart_id, u_int mode, u_int speed, u_int timeguard ) ;
extern u_int disable_usart ( u_int usart_id ) ;
extern u_int receive_frame ( u_int usart_id, void *pt_buffer, u_int max_size, u_int timeout ) ;
extern u_int is_receive0_done (void); extern void next_frame0 (void);

extern char sram_addr[];
//*----------------------------------------------------------------------------
//* Function Name       : BootLoad
//* Object              : Main function of the bootloader
//* Input Parameters    : none
//* Output Parameters   : none
//* Functions called    : init_usart, disable_usart, receive_frame
//*----------------------------------------------------------------------------
void BootLoad ( void )
//* Begin
{
        //* Initialize USART
        init_usart (0, US_ASYNC_MODE, 18, 0);
        //* Initialize PDC Reception
        receive_frame (0, sram_addr, BUFFER_SIZE, 100 );

	while (1)
	{
		
		switch (is_receive0_done())
		{
			case 1: next_frame0(); continue;

			case 2:	PIO_BASE->PIO_CODR = LED1; goto wait_user;
		}
	}
wait_user:
	//* Wait for IRQ0 pin asserted
	while (!(PIO_BASE->PIO_PDSR & SW5));

	//* Disable USART
	disable_usart (0/*usart_id*/);
//* End
}
