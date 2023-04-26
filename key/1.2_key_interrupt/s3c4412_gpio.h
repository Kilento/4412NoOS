#ifndef S3C4412_GPIO_H
#define S3C4412_GPIO_H

#define GPIOBASE1 0x11000000
#define GPIOBASE2 0x11400000

#define GPK1CON (GPIOBASE1 + 0x0060)
#define GPK1DAT (GPIOBASE1 + 0x0064)
#define GPK1PUD (GPIOBASE1 + 0x0068)
#define GPK1DRV (GPIOBASE1 + 0x006C)

#define GPL2CON (GPIOBASE1 + 0x0100)
#define GPL2DAT (GPIOBASE1 + 0x0104)
#define GPL2PUD (GPIOBASE1 + 0x0108)
#define GPL2DRV (GPIOBASE1 + 0x010C)

#define GPX0CON (GPIOBASE1 + 0x0C00)
#define GPX0DAT (GPIOBASE1 + 0x0C04)
#define GPX0PUD (GPIOBASE1 + 0x0C08)
#define GPX0DRV (GPIOBASE1 + 0x0C0C)

#define GPX1CON (*(volatile unsigned long *)(GPIOBASE1 + 0x0C20))
#define GPX1DAT (*(volatile unsigned long *)(GPIOBASE1 + 0x0C24))
#define GPX1PUD (*(volatile unsigned long *)(GPIOBASE1 + 0x0C28))
#define GPX2CON (*(volatile unsigned long *)(GPIOBASE1 + 0x0C40))
#define GPX2DAT (*(volatile unsigned long *)(GPIOBASE1 + 0x0C44))
#define GPX2PUD (*(volatile unsigned long *)(GPIOBASE1 + 0x0C48))
#define GPX3CON (*(volatile unsigned long *)(GPIOBASE1 + 0x0C60))
#define GPX3DAT (*(volatile unsigned long *)(GPIOBASE1 + 0x0C64))
#define GPX3PUD (*(volatile unsigned long *)(GPIOBASE1 + 0x0C68))

#define GPA0CON (*(volatile unsigned long *)(GPIOBASE2 + 0x0000))
#define GPA1CON (*(volatile unsigned long *)(GPIOBASE2 + 0x0020))

#define EXT_INT41CON (*(volatile unsigned long *)(GPIOBASE1 + 0x0E04))
#define EXT_INT42CON (*(volatile unsigned long *)(GPIOBASE1 + 0x0E08))
#define EXT_INT43CON (*(volatile unsigned long *)(GPIOBASE1 + 0x0E0C))

#define EXT_INT41_MASK (*(volatile unsigned long *)(GPIOBASE1 + 0x0F04))
#define EXT_INT42_MASK (*(volatile unsigned long *)(GPIOBASE1 + 0x0F08))
#define EXT_INT43_MASK (*(volatile unsigned long *)(GPIOBASE1 + 0x0F0C))

#define EXT_INT41_PEND (*(volatile unsigned long *)(GPIOBASE1 + 0x0F44))
#define EXT_INT42_PEND (*(volatile unsigned long *)(GPIOBASE1 + 0x0F48))
#define EXT_INT43_PEND (*(volatile unsigned long *)(GPIOBASE1 + 0x0F4C))

#endif