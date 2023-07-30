#ifndef S3C4412_RTC_H
#define S3C4412_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * RTC Register
 */

#define RTCBASE (0x10070000)

#define INTP (*(volatile unsigned long*)(RTCBASE + 0x0030))
#define RTCCON (*(volatile unsigned long*)(RTCBASE + 0x0040))
#define TICCNT (*(volatile unsigned long*)(RTCBASE + 0x0044))
#define RTCALM (*(volatile unsigned long*)(RTCBASE + 0x0050))
#define ALMSEC (*(volatile unsigned long*)(RTCBASE + 0x0054))
#define ALMMIN (*(volatile unsigned long*)(RTCBASE + 0x0058))
#define ALMHOUR (*(volatile unsigned long*)(RTCBASE + 0x005C))
#define ALMDAY (*(volatile unsigned long*)(RTCBASE + 0x0060))
#define ALMMON (*(volatile unsigned long*)(RTCBASE + 0x0064))
#define ALMYEAR (*(volatile unsigned long*)(RTCBASE + 0x0068))
#define BCDSEC (*(volatile unsigned long*)(RTCBASE + 0x0070))
#define BCDMIN (*(volatile unsigned long*)(RTCBASE + 0x0074))
#define BCDHOUR (*(volatile unsigned long*)(RTCBASE + 0x0078))
#define BCDDAYWEEK (*(volatile unsigned long*)(RTCBASE + 0x007C))
#define BCDDAY (*(volatile unsigned long*)(RTCBASE + 0x0080))
#define BCDMON (*(volatile unsigned long*)(RTCBASE + 0x0084))
#define BCDYEAR (*(volatile unsigned long*)(RTCBASE + 0x0088))
#define CURTICCNT (*(volatile unsigned long*)(RTCBASE + 0x0090))

#ifdef __cplusplus
}
#endif

#endif