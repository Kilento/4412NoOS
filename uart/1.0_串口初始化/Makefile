CFLAGS := -nostdlib -O0
TARGET := uart.bin
LOCATION := /dev/sdb 
CROSS_COMPILE := arm-none-linux-gnueabi-
Q := @
$(TARGET) : start.o uart.o lowlevel_init.o sdram_init.o
	$(Q)$(CROSS_COMPILE)ld -T link.lds -o uart.elf $^
	$(Q)$(CROSS_COMPILE)objcopy -O binary uart.elf $@
	$(Q)$(CROSS_COMPILE)objdump -D uart.elf > uart.dis

%.o : %.S
	$(Q)$(CROSS_COMPILE)gcc -o $@ $< -c

%.o : %.c
	$(Q)$(CROSS_COMPILE)gcc $(CFLAGS) -o $@ $< -c

.PHONY:clean install
clean:
	rm -rf *.o *.elf *.bin *.dis mkbl1

install:
	$(Q)gcc ./mkbl1.c -static -o mkbl1
	$(Q)./mkbl1 $(TARGET) 
	$(Q)if [ -b $(LOCATION) ]; then \
	#sudo mkfs.vfat -F 32 -I $(LOCATION); \
	dd if=/dev/zero of=$(LOCATION) bs=512 seek=1 iflag=dsync oflag=dsync count=16; \
	dd if=./$(TARGET) of=$(LOCATION) bs=512 seek=1 iflag=dsync oflag=dsync; \
	fi
