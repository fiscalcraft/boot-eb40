MEMORY
{
iram : org = 0x0000000, len = 8K
flash : org = 0x01000000, len = 64K
/*ram : org = 0x02000000, len = 2M*/
}
__stack_end__ = 0x00000000 + 8K - 4;
/*//__stack_end__ = 0x02000000 + 512K - 4;
//__stack_end__ = 0x00300000 + 8K - 4;*/

addr_angel = 0x01020000;
sram_addr = 0x02000000;


SECTIONS
{
. = 0x40;
.data :
{
__data_beg__ = .;
/*__data_beg_src__ = __end_of_text__;*/
*(.data)
__data_end__ = .;
} >iram

.bss :
{
__bss_start__ = .;
*(.bss)
_bss_end__ = . ; __bss_end__ = . ;
} >iram

/*//. = 0x02000000;
//. = 0x00300000;
. = 0x00000000;
startup : { *(.startup)} >sram*/

. = 0x01000000;
.text :
{
*(.text)
*(.rodata)
*(.rodata*)
*(.glue_7)
*(.glue_7t)
} >flash

__end_of_text__ = .;

/* Align here to ensure that the .bss section occupies space up to
_end. Align after .bss to ensure correct alignment even if the
.bss section disappears because there are no input sections. */
. = ALIGN(32 / 8);
}
. = ALIGN(32 / 8);
_end = .;
 __end__ = . ;
PROVIDE (end = .);

