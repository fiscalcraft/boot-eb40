/*;------------------------------------------------------------------------------
;-    ATMEL Microcontroller Software Support  -   ROUSSET -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;-----------------------------------------------------------------------------
;- File source          : bo_reset.s
;- Object               : Boot of AT91EB40
;-
;- Exported Resources   : BootReset
;- Imported Resources   : BootEntry
;-
;- 1.0 JLV 05/09/98     : Creation
;- 2.0 21/10/98 JCZ     : Clean up.
;------------------------------------------------------------------------------

;                AREA        reset, CODE, READONLY	*/

#include     "r40807.inc"

#define AT91_EBI	0xFFE00000 /*; Memory controller*/

#define ONCHIP_RAM	0x00300000 /*; Onchip SRAM base address (REBOOT mode)*/
#define ONCHIP_RAM_SZE	0x00001000 /*; 4K of SRAM from address 0x0*/
#define SVC_STACK	ONCHIP_RAM_SZE /*; SVC Stack*/
/*;--------------------------------
;- ARM Core Mode and Status Bits
;--------------------------------

#define ARM_MODE_USER	0x10
#define ARM_MODE_FIQ	0x11
#define ARM_MODE_IRQ	0x12
#define ARM_MODE_SVC 	0x13
#define ARM_MODE_ABORT	0x17
#define ARM_MODE_UNDEF	0x1B
#define ARM_MODE_SYS	0x1F

#define I_BIT		0x80
#define F_BIT		0x40
#define T_BIT		0x20*/
/*
;            IMPORT      main
;            IMPORT      |Image$$RO$$Limit|      ; End of ROM code (=start of ROM data)
;            IMPORT      |Image$$RW$$Base|       ; Base of RAM to initialise
;            IMPORT      |Image$$ZI$$Base|       ; Base and limit of area
;            IMPORT      |Image$$ZI$$Limit|      ; to zero initialise


;- Define the entry point
;            ENTRY	*/
.text
.align

.global start
.global _start
.global _stext
.global __start
.global __stext


start:
_start:
_stext:
_entry:
__stext:
__entry:
/*
;------------------------------------------------------------------------------
;- Function             : boot
;- Treatments           : AT91 boot code
;- Input Parameters     : None
;- Output Parameters    : None
;- Registers lost       : None
;- Called Functions :
;-      BootEntry
;- Called Macros        : None
;------------------------------------------------------------------------------

;- Define "__main" to ensure that C runtime system is not linked in 
                .global      __main
__main:
                .global      BootReset*/
BootReset:
        B       resetvec /*; reqset*/
undefvec:
        B       undefvec /*; Undef*/
swivec:
        B       swivec   /*; SW*/
pabtvec:
        B       pabtvec  /*; P abt*/
dabtvec:
        B       dabtvec  /*; D abt*/
rsvdvec:
        B       rsvdvec  /*; reserved*/
        ldr     pc, [pc,#-0xF20]         /*; IRQ : read the Advanced Interrupt Controller*/
        ldr     pc, [pc,#-0xF20]         /*; FIQ : read the Advanced Interrupt Controller*/

resetvec:

/*;- | Initialise the Memory Controller
;- | ---------------------------------
;- | Copy the Image of the Memory Controller*/
            ldr         r10, PtImageMemorySelect /*; get the address of the chip select register image*/

/*;- | If pc > 0x100000*/
            movs        r0, pc, LSR #20
/*;- | | Mask the 12 highest bits of the address*/
            moveq       r10, r10, LSL #12
            moveq       r10, r10, LSR #12
/*;- | EndIf*/

/*;- | Copy Chip Select Register Image to Memory Controller and command remap*/
            ldmia       r10!, {r0-r9,r11-r12}           /*; load the complete image*/
            stmia       r11!, {r0-r9}                   /*; store the complete image with the remap command*/

/*;- | Jump to ROM at its new address*/
            mov         pc, r12                         /*; jump and break the pipeline*/

JumpAddress:
/*;- | Setup Exception Vectors
;- | -----------------------
;- | Copy the hard exception vectors*/
            mov         r8, #0                  /*; @ of the hard vector*/
            ldr         r9, PtVectorInit        /*; @ where to read values*/
            ldmia       r9!, {r0-r7}            /*; read the vectors*/
            stmia       r8!, {r0-r7}            /*; store them*/

/*;- | Copy the handler addresses unless IRQ and FIQ stored in the Interrupt Controller*/
            ldmia       r9!, {r0-r4}            /*; read the DCD'ed addresses*/
            stmia       r8!, {r0-r4}            /*; store them*/

/*;- | Set up the SVC stack pointer last and return to SVC mode*/
            MOV         R0, #(ARM_MODE_SVC|I_BIT|F_BIT) /*; No interrupts*/
            MSR         CPSR/*_cxsf*/, R0
            LDR         R13, =SVC_STACK

/*;- enable All peripherial clock for test
;----------------------------------------------------------*/
                mov         r0,#0xffffffff
                ldr         r1,=PS_BASE
                str         r0,[r1, #4/*PS_PCER*/]

/*;- | Initialise memory required by C code
            LDR     r0, =|Image$$RO$$Limit| ; Get pointer to ROM data
            LDR     r1, =|Image$$RW$$Base|  ; and RAM copy*/
            LDR     r3, =__bss_start__	    /*;|Image$$ZI$$Base|  ; Zero init base => top of initialised data*/
            CMP     r0, r1                  /*; Check that they are different*/
/*;            BEQ     %1
;0           CMP     r1, r3                  ; Copy init data
;            LDRCC   r2, [r0], #4
;            STRCC   r2, [r1], #4
;            BCC     %0*/
/*1*/       LDR     r1, =__bss_end__	/*;|Image$$ZI$$Limit| ; Top of zero init segment*/
            MOV     r2, #0
2:          CMP     r3, r1                 /* ; Zero init*/
            STRCC   r2, [r3], #4
            BCC     2b	/*%2*/

/*;- | Branch on C code BootEntry function*/
            bl      bo_start

/*;- | Jmp to address returnd*/
            mov     pc, r0

PtImageMemorySelect:
            .long       ImageMemorySelect
ImageMemorySelect:
            .long       0x01002535  /*; 0x01000000, 16MB,  2 cycles added after transfer, 16-bit, 6 wait states*/
            .long       0x02002121  /*; 0x02000000, 16MB,  0 cycles added after transfer, 16-bit, 1 wait state*/
            .long       0x20000000  /*; unused*/
            .long       0x30000000  /*; unused*/
            .long       0x40000000  /*; unused*/
            .long       0x50000000  /*; unused*/
            .long       0x60000000  /*; unused*/
            .long       0x70000000  /*; unused*/
            .long       0x00000001  /*; REMAP commande*/
            .long       0x00000006  /*; 7 memory regions, standard read*/
            .long       AT91_EBI    /*; EBI address*/
            .long       JumpAddress /*; address where to jump*/
PtVectorInit:
            .long       BootReset

/*            END*/
