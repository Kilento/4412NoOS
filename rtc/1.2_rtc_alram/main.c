#include "key.h"
#include "led.h"
#include "rtc.h"
#include "s3c4412_interrupt.h"
#include "stdio.h"
#include "uart.h"
#include "wdt.h"

void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

int main(void)
{
    uart_init();
    // key_init();
    led_int();
    // wdt_init();
    rtc_init();

    led_ctrl(0, 1);
    led_ctrl(1, 0);

    struct rtc_time time = { 2023, 7, 30, 17, 44, 20, 0 };

    rtc_set_time(&time);
    rtc_set_sec_alarm(30);
    interrupt_init();

    // interrupt_vector_table();

    // 等待中断程序发生
    while (1) {
        rtc_get_time(&time);
        printf("time: %04u-%02u-%02u %02u:%02u:%02u %u\n", time.year, time.month, time.day, time.hour, time.minute, time.second, time.dayweek);
        delay(0x400000);
    }

    return 0;
}