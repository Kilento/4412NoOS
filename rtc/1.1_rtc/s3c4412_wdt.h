#ifndef S3C4412_WDT_H
#define S3C4412_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * WDT Register
 */

#define WTBASE (0x10060000)

#define WTCON (*(volatile unsigned long*)(WTBASE))
#define WTDAT (*(volatile unsigned long*)(WTBASE + 0x0004))
#define WTCNT (*(volatile unsigned long*)(WTBASE + 0x0008))
#define WTCLRINT (*(volatile unsigned long*)(WTBASE + 0x000C))

#ifdef __cplusplus
}
#endif

#endif