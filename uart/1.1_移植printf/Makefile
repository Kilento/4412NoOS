INCDIR := $(shell pwd)
LIB := lib
CFLAGS := -nostdlib -nostdinc -I$(INCDIR)/$(LIB)/include
CPPFLAGS := -Wall -O0 -fno-builtin  -fno-tree-scev-cprop 
TARGET := uart.bin
LOCATION := /dev/sdb 
CROSS_COMPILE := arm-none-linux-gnueabi-
Q := @

objs := start.o uart.o lowlevel_init.o sdram_init.o main.o
objs += $(LIB)/libc.a

export CFLAGS CPPFLAGS CROSS_COMPILE INCDIR Q

$(TARGET) : $(objs)
	$(Q)$(CROSS_COMPILE)ld -T link.lds -o uart.elf $^
	$(Q)$(CROSS_COMPILE)objcopy -O binary uart.elf $@
	$(Q)$(CROSS_COMPILE)objdump -D uart.elf > uart.dis

$(LIB)/libc.a:
	$(Q)cd $(LIB);make;cd ..

%.o : %.S
	$(Q)$(CROSS_COMPILE)gcc $(CPPFLAGS) $(CFLAGS)  -o $@ $< -c

%.o : %.c
	$(Q)$(CROSS_COMPILE)gcc $(CPPFLAGS) $(CFLAGS)  -o $@ $< -c

.PHONY:clean install
clean:
	$(Q)cd $(LIB);make clean; cd ..
	$(Q)rm -rf *.o *.elf *.bin *.dis mkbl1

install:
	$(Q)gcc ./mkbl1.c -static -o mkbl1
	$(Q)./mkbl1 $(TARGET) 
	$(Q)if [ -b $(LOCATION) ]; then \
	#sudo mkfs.vfat -F 32 -I $(LOCATION); \
	dd if=/dev/zero of=$(LOCATION) bs=512 seek=1 iflag=dsync oflag=dsync count=16; \
	dd if=./$(TARGET) of=$(LOCATION) bs=512 seek=1 iflag=dsync oflag=dsync; \
	fi
