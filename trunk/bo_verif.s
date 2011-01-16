;------------------------------------------------------------------------------
;-    ATMEL Microcontroller Software Support  -   ROUSSET -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;-----------------------------------------------------------------------------
;- File source          : bo_verif.s
;- Object               : Verify the copy of flash to SRAM
;- Translator           : ARM Software Development Toolkit V2.50
;-
;- Exported Resources   : VerifyFlash
;- Imported Resources   : None
;-
;- 1.0 08/01/99 JLV   : Creation
;- 2.0 10/04/00 JCZ   : Clean up
;------------------------------------------------------------------------------

                AREA        TEST, CODE, READONLY

;-------------------------- List of Included Files ---------------------------
; None

;------------------------ List of constants and types ------------------------
; None

;------------------------ List of Imported resources -------------------------
; None

;------------------------ List of Internal resources -------------------------
; None

;------------------------ List of Exported resources -------------------------

;------------------------------------------------------------------------------
;- Function             : VerifyFlash
;- Treatments           : AT91 boot code
;- Input Parameters     :
;- . ad_ram   (r0) - base address of internal RAM
;- . ad_sram  (r1) - base address of SRAM
;- . ad_flash (r2) - base address of flash
;- . sz_flash (r3) - size of flash
;- Output Parameters    :
;- . ad_flash (r0) - last address of flash tested (0 if OK)
;- Registers lost       : None
;- Called Functions     : None
;- Called Macros        : None
;------------------------------------------------------------------------------

            EXPORT      VerifyFlash
;- Begin
VerifyFlash
;- | Save context
            stmfd       sp!, { r4-r7, r14}
;- | Copy FLASH in SRAM
            mov     r4, r1
            mov     r5, r2
            mov     r6, r3
VerifyFlash_copy
            ldr     r7,[r5],#4
;            str     r7,[r4],#4
            subs    r6, r6, #4
            bne     VerifyFlash_copy
;- | Copy code in RAM
            mov     r4, r0
            ldr     r5, =VerifyFlash_begin
            ldr     r6, =VerifyFlash_end
VerifyFlash_code
            ldr     r7,[r5],#4
            str     r7,[r4],#4
            cmp     r5,r6
            blo     VerifyFlash_code
;- | goto code in RAM
            mov     pc,r0
VerifyFlash_begin
;- | Compare SRAM with FLASH
            mov     r4, r1
            mov     r5, r2
            mov     r6, r6
VerifyFlash_read
            ldr     r4, [r1],#4
            ldr     r5, [r2],#4
            cmp     r4, r5
            bne     VerifyFlash_over
            subs    r3, r3, #4
            bne     VerifyFlash_read
            mov     r2,#4
VerifyFlash_over
            sub     r0, r2, #4
;- | Save context
            ldmia   sp!, { r4-r7, r14}
;- End
            bx      lr
VerifyFlash_end

            END
