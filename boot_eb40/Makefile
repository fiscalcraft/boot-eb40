CC = arm-elf-gcc
LD = arm-elf-ld
NM = arm-elf-nm

OBJS =  bo_reset.o bo_entry.o bo_fts.o bo_load.o bo_usart.o  

CFLAGS := -g -c -I../include -Wall -O2 -mcpu=arm7tdmi

all: $(OBJS)
	$(LD) -g -T AT91R40807.ld $(OBJS) -o boot_eb40
#	arm-elf-nm boot_eb40 | grep -v '\(compiled\)\|\(\.o$\)\|\( a \)' | sort > boot_eb40.map


bo_entry.o:	bo_entry.c
		$(CC) $(CFLAGS) bo_entry.c -o $@

bo_fts.o:	bo_fts.c
		$(CC) $(CFLAGS) bo_fts.c -o $@

bo_load.o:	bo_load.c
		$(CC) $(CFLAGS) bo_load.c -o $@

bo_usart.o:	bo_usart.c
		$(CC) $(CFLAGS) bo_usart.c -o $@


bo_reset.o:	bo_reset.S
		$(CC)  $(CFLAGS) bo_reset.S -o $@

clean:
		rm ./*.o ./*.map ./boot_eb40

