#include "rtc.h"
#include "s3c4412_rtc.h"

static unsigned int dec_2_bcd(unsigned int dec)
{
    return ((dec / 10) << 4 | (dec % 10));
}

static unsigned int bcd_2_dec(unsigned int bcd)
{
    return (((bcd & 0xf0) >> 4) * 10 + (bcd & 0x0f));
}

void rtc_init(void)
{
    return;
}

void rtc_set_time(const struct rtc_time* time)
{
    // 打开RTC读写开关
    RTCCON |= (1 << 0);

    /// 写 RTC时间寄存器
    BCDYEAR = dec_2_bcd(time->year) - 2000;
    BCDMON = dec_2_bcd(time->month);
    BCDDAY = dec_2_bcd(time->day);
    BCDDAYWEEK = dec_2_bcd(time->dayweek);
    BCDHOUR = dec_2_bcd(time->hour);
    BCDMIN = dec_2_bcd(time->minute);
    BCDSEC = dec_2_bcd(time->second);

    RTCCON &= ~(1 << 0);

    return;
}

void rtc_get_time(struct rtc_time* time)
{
    // 打开RTC读写开关
    RTCCON |= (1 << 0);

    /// 写 RTC时间寄存器
    time->year = bcd_2_dec(BCDYEAR) + 2000;
    time->month = bcd_2_dec(BCDMON);
    time->day = bcd_2_dec(BCDDAY);
    time->dayweek = bcd_2_dec(BCDDAYWEEK);
    time->hour = bcd_2_dec(BCDHOUR);
    time->minute = bcd_2_dec(BCDMIN);
    time->second = bcd_2_dec(BCDSEC);

    RTCCON &= ~(1 << 0);
}

void rtc_set_sec_alarm(unsigned int sec)
{
    ALMSEC = dec_2_bcd(sec);
    RTCALM |= 1 << 0;
    RTCALM |= 1 << 6;

    return;
}
