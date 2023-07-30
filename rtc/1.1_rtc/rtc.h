#ifndef _RTC_H_
#define _RTC_H_

#ifdef __cplusplus
extern "C" {
#endif

struct rtc_time {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
    unsigned int dayweek;
};

void rtc_init(void);

void rtc_set_time(const struct rtc_time* time);

void rtc_get_time(struct rtc_time* time);

#ifdef __cplusplus
}
#endif

#endif