#ifndef S3C4412_GPIO_H
#define S3C4412_GPIO_H

#define GPK1CON (0x11000000 + 0x0060)
#define GPK1DAT (0x11000000 + 0x0064)
#define GPK1PUD (0x11000000 + 0x0068)
#define GPK1DRV (0x11000000 + 0x006C)

#define GPL2CON (0x11000000 + 0x0100)
#define GPL2DAT (0x11000000 + 0x0104)
#define GPL2PUD (0x11000000 + 0x0108)
#define GPL2DRV (0x11000000 + 0x010C)

#define GPX0CON (0x11000000 + 0x0C00)
#define GPX0DAT (0x11000000 + 0x0C04)
#define GPX0PUD (0x11000000 + 0x0C08)
#define GPX0DRV (0x11000000 + 0x0C0C)

#define GPIOBASE 0x11400000

#define GPA0CON (*(volatile unsigned long *)(GPIOBASE + 0x0000))
#define GPA1CON (*(volatile unsigned long *)(GPIOBASE + 0x0020))

#endif