//*----------------------------------------------------------------------------
//*      ATMEL Microcontroller Software Support  -  ROUSSET  -
//*----------------------------------------------------------------------------
//* The software is delivered "AS IS" without warranty or condition of any
//* kind, either express, implied or statutory. This includes without
//* limitation any warranty or condition with respect to merchantability or
//* fitness for any particular purpose, or against the infringements of
//* intellectual property rights of others.
//*----------------------------------------------------------------------------
//* File Name           : bo_fts.c
//* Object              : Functionnal Test Software of AT91EB40
//* Translator          : ARM Software Development Toolkit V2.50
//
//* Exported resources  : BootFts
//* Imported resources  : None
//
//* 1.0 06/04/00 JPP    : Creation
//*----------------------------------------------------------------------------

#include "std_c.h"
#include "pio.h"
#include "tc.h"
#include "ebi.h"
#include "usart.h"
#include "r40807.h"

#include "at91eb40.h"       /* AT91EB40 description */

#define DELAY           ((250 * 32768) / 1024)  /* 32.768MHz/1024 ==> 0.5sec */
#define BAUD_RATE       (32768000 / (16 * 115400))
#define TC0_MODE        (TC_WAVE | TC_EEVT_XC0 | TC_CPCDIS | TC_CPCSTOP | TC_CLKS_MCK1024)

#define USART_MODE      (US_CHMODE_NORMAL + US_NBSTOP_1 + US_PAR_NO + US_CHRL_8 + US_CLKS_MCK)


#define USART_RESET     (US_RSTSTA | US_RSTTX | US_RSTRX)
#define USART_ENABLE    (US_RXEN | US_TXEN)

//*----------------------------------------------------------------------------
//* Function Name       : delay_one_tick
//* Object              : Wait for a parameterd number of ticks
//* Input Parameters    : None
//* Output Parameters   : None
//* Functions called    : None
//*----------------------------------------------------------------------------
void delay_one_tick(void)
//* Begin
{
    /* This function sets up an approx. 1 second delay for flashing the LEDs */
    /* The value 'delay' is used to set the time delay */

    TC0_BASE->TC_RC  = DELAY;       /* Load value */
    TC0_BASE->TC_CCR = TC_CLKEN;    /* Enable clock */
    TC0_BASE->TC_CCR = TC_SWTRG;    /* Start counter */

    while (!(TC0_BASE->TC_SR & TC_CPCS))
    {
    } /*while*/
}
//* End

//*----------------------------------------------------------------------------
//* Function Name           : timer_init
//* Object                  : expect an user action, and start the test
//* Input Parameters        : None
//* Output Parameters       : None
//* Functions called        : None
//*----------------------------------------------------------------------------
void timer_init ( void )
//* Begin
{
    //* -- Set up Timers
    TCB0_BASE->TC[0].TC_IDR = 0xFF;         /* Disable interrupts channel 0 */
    TCB0_BASE->TC[0].TC_CMR = TC_CLKDIS;       /* Stop channel 0 */
    TCB0_BASE->TC[1].TC_IDR = 0xFF;         /* Disable interrupts channel 1 */
    TCB0_BASE->TC[1].TC_CCR = TC_CLKDIS;       /* Stop channel 1 */
    TCB0_BASE->TC[2].TC_IDR = 0xFF;         /* Disable interrupts channel 2 */
    TCB0_BASE->TC[2].TC_CCR = TC_CLKDIS;       /* Stop channel 2 */
    /* Set each counter to NOT use external clock */
    TCB0_BASE->TC_BMR = 0x15;
    TCB0_BASE->TC[0].TC_CMR = TC0_MODE;     /* Set up Wave Mode on channel 0 */

//* End
}


//*----------------------------------------------------------------------------
//* Function Name       : blink_led
//* Object              : Blink LEDs for a parameterd number of times
//* Input Parameters    :
//*     . led (int) - mask of LEDs to blink
//*     . nb   (int) - number of blinks
//* Output Parameters   : None
//* Functions called    : delay_one_tick
//*----------------------------------------------------------------------------
void blink_led(int led, int nb)
//* Begin
{
    //* While 'nb' blinks not ended
    for (; nb > 0 ; nb--)
    {
        //* Ligth on 'led' and wait DELAY
        PIO_BASE->PIO_SODR = led;
        delay_one_tick();
        //* Ligth off 'led' and wait DELAY
        PIO_BASE->PIO_CODR = led;
        delay_one_tick();
    //* EndWhile
    }
//* End
}/* blink_led*/

//*----------------------------------------------------------------------------
//* Function Name       : test_sram_size
//* Object              : Calculate and indicate size of the RAM
//* Input Parameters    : None
//* Output Parameters   : None
//* Functions called    : blink_led
//*----------------------------------------------------------------------------
void test_sram_size(void)
//* Begin
{
    int sram_base = (EBI_BASE->EBI_CSR[1] & 0xFFFF0000);
    int offset;

    //* -- Set up first integer in SRAM block
    *(volatile short *)(sram_base) = -1;
    for (offset = 0x0002 ;
            *(volatile short *)(sram_base) == -1 ;
            offset <<= 1)
    {
        *(volatile short *)(sram_base + (offset << 16)) = offset;
    }
    *(volatile short *)(sram_base) = -1;
    //* -- Check first integer in SRAM block
    for (offset = 0x0002 ;
            *(volatile short *)(sram_base + (offset << 16)) == offset ;
            offset <<= 1)
    {
        //* Use LED3 to inform the user whether memory is present
        blink_led (LED3, 1);
    }
//* End
}/*test_sram_size*/

//*----------------------------------------------------------------------------
//* Function Name       : test_sram_bus
//* Object              : Test address and data bus
//* Input Parameters    : None
//* Output Parameters   : None
//* Functions called    : blink_led
//*----------------------------------------------------------------------------
void test_sram_bus(void)
//* Begin
{
    volatile int *addr;
    int val;
    int size;

    //* -- Test of data bus
    addr = (volatile int *)(EBI_BASE->EBI_CSR[1] & 0xFFFF0000);
    addr += 0x0001 << 14;
    for (size = 0x0001 ; size != 0 ; size <<= 1)
    {
        *addr = size;
        //* If error
        if (size != *addr)
        {
            /* Use LED1 to inform the user the data bus default */
            blink_led (LED1, 1);
        }
        *addr = ~size;
        //* If error
        if (~size != *addr)
        {
            /* Use LED1 to inform the user the data bus default */
            blink_led (LED1, 1);
        }
    }
    /* Use LED3 to inform the user the end of the test */
    blink_led (LED3, 1);

    //* -- Set up SRAM block
    val = 0x12345678;
    for (size = (0x0001 << 14) ; size > 0 ; size--, addr++)
    {
        *addr = (val += 0x01010101);
    }
    //* -- Check SRAM block
    addr = (volatile int *)(EBI_BASE->EBI_CSR[1] & 0xFFFF0000);
    addr += 0x0001 << 14;
    val = 0x12345678;
    for (size = (0x0001 << 14) ; size > 0 ; size--, addr++)
    {
        //* If error
        if (*addr != (val += 0x01010101))
        {
            /* Use LED2 to inform the user the address bus default */
            blink_led (LED2, 1);
        }
    }
    /* Use LED3 to inform the user the end of the test */
    blink_led (LED3, 1);
//* End
}/*test_sram_bus*/

//*----------------------------------------------------------------------------
//* Function Name       : usart_test
//* Object              : Test USART Transmission
//* Input Parameters    :
//*     . src (StructUSART *) - USART source address
//*     . dst (StructUSART *) - USART destination address
//*     . val (int) - value of the byte transmitted
//* Output Parameters   : None
//* Functions called    : blink_led
//*----------------------------------------------------------------------------
void usart_test(StructUSART * src, StructUSART * dst, int val)
//* Begin
{
    int count;

    //* -- send val from source to destination (loopback)
    src->US_THR = val;
    count = 0;
    while (((dst->US_CSR & 0x1)!=0x1) & (count != 2000))
    {
        //* -- Wait the RXRDY flag high
        count++;
    }/*while*/
    /* Flash Green/Red LED once */
    blink_led ((dst->US_RHR == val) ? LED3 : LED1, 1);
//* End
}/*usart_test*/

//*----------------------------------------------------------------------------
//* Function Name       : test_usart
//* Object              : Test USART with loopback and external cable
//* Input Parameters    : None
//* Output Parameters   : None
//* Functions called    : usart_test
//*----------------------------------------------------------------------------
void test_usart(void)
//* Begin
{
    //* -- Configure Serial ports for internal loopback test
    USART0_BASE->US_MR   = (USART_MODE | US_CHMODE_LOCAL_LOOPBACK);
    USART1_BASE->US_IDR  = 0x3FF;
    USART0_BASE->US_BRGR = BAUD_RATE;
    USART0_BASE->US_RTOR = 0x0;
    USART0_BASE->US_TTGR = 0x0;
    USART0_BASE->US_CR   = USART_RESET;
    USART0_BASE->US_CR   = USART_ENABLE;

    USART1_BASE->US_MR   = (USART_MODE | US_CHMODE_LOCAL_LOOPBACK);
    USART1_BASE->US_IDR  = 0x3FF;
    USART1_BASE->US_BRGR = BAUD_RATE;
    USART1_BASE->US_RTOR = 0x0;
    USART1_BASE->US_TTGR = 0x0;
    USART1_BASE->US_CR   = USART_RESET;
    USART1_BASE->US_CR   = USART_ENABLE;

    //* -- Test 1 - send from Serial A to Serial A (loopback)
    usart_test (USART0_BASE, USART0_BASE, 0x0031);

    //* -- Test 2 - send from Serial B to Serial B (loopback)
    usart_test (USART1_BASE, USART1_BASE, 0x0032);

    //* -- Configure Serial ports for external cable test
    /* Normal loopback, 1 stop bit, no parity, async., 8 bit character, MCK */
    USART0_BASE->US_MR = USART_MODE;
    /* Normal loopback, 1 stop bit, no parity, async., 8 bit character, MCK */
    USART1_BASE->US_MR = USART_MODE;

    //* -- Test 3 - send from Serial A to Serial B (external cable)
    usart_test (USART0_BASE, USART1_BASE, 0x0033);

    //* -- Test 4 - send from Serial B to Serial A (external cable)
    usart_test (USART1_BASE, USART0_BASE, 0x0034);
//* End
}/*test_usart*/

//*----------------------------------------------------------------------------
//* Function Name           : BootFts
//* Object                  : expect an user action, and start the test
//* Input Parameters        : None
//* Output Parameters       : None
//* Functions called        :
//*     delay_one_tick, blink_led, test_usart,
//*     test_sram_size, test_sram_bus
//*----------------------------------------------------------------------------
void BootFts (void )
//* Begin
{
    //* -- Set up Timers
    TCB0_BASE->TC[0].TC_IDR = 0xFF;         /* Disable interrupts channel 0 */
    TCB0_BASE->TC[0].TC_CMR = TC_CLKDIS;       /* Stop channel 0 */
    TCB0_BASE->TC[1].TC_IDR = 0xFF;         /* Disable interrupts channel 1 */
    TCB0_BASE->TC[1].TC_CCR = TC_CLKDIS;       /* Stop channel 1 */
    TCB0_BASE->TC[2].TC_IDR = 0xFF;         /* Disable interrupts channel 2 */
    TCB0_BASE->TC[2].TC_CCR = TC_CLKDIS;       /* Stop channel 2 */
    /* Set each counter to NOT use external clock */
    TCB0_BASE->TC_BMR = 0x15;
    TCB0_BASE->TC[0].TC_CMR = TC0_MODE;     /* Set up Wave Mode on channel 0 */

    //* -- Blink LEDs to indicate life
    blink_led (LED1_2_3, 2);

    //* Repeat for ever
    for (;;)
    {
        //* If SW3 button pressed, test of ...
        if (PIO_BASE->PIO_PDSR & SW3)
        {
            //* Expect SW3 un-pressed
            PIO_BASE->PIO_SODR = LED2;
            while (PIO_BASE->PIO_PDSR & SW3);
            PIO_BASE->PIO_CODR = LED1_2_3;
            delay_one_tick();
            //* -- Test USART
            test_usart();
        }//* EndIf

        //* If SW4 button pressed, test of SRAM space size
        if (PIO_BASE->PIO_PDSR & SW4)
        {
            //* Expect SW4 un-pressed
            PIO_BASE->PIO_SODR = LED1;
            while (PIO_BASE->PIO_PDSR & SW4);
            PIO_BASE->PIO_CODR = LED1_2_3;
            delay_one_tick();
            //* -- Test SRAM size
            test_sram_size();
        }//* EndIf

        //* If SW5 button pressed, test of SRAM bus
        if (PIO_BASE->PIO_PDSR & SW5)
        {
            //* Expect SW5 un-pressed
            PIO_BASE->PIO_SODR = LED1_2;
            while (PIO_BASE->PIO_PDSR & SW5);
            PIO_BASE->PIO_CODR = LED1_2_3;
            delay_one_tick();
            //* -- Test SRAM bus
            test_sram_bus();
        }//* EndIf

    }//* EndRepeat

//* End
}
