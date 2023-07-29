#include "s3c4412_wdt.h"

void wdt_init(void)
{
    /* t_watchdog = 1 / ( PCLK / (Prescaler value + 1) / Division factor ) */
    WTCON &= ~(0xff << 8);
    WTCON |= (0x63 << 8); // 设置预分频系数为 99，则预分频后的时钟为 1MHz

    WTCON &= ~(0x3 << 3);
    WTCON |= (0x3 << 3); // 设置时钟系数为 128，则最终得到的时钟周期为  T= 1 / (1MHz / 128) = 128us

    WTCON |= (1 << 2); // 使能看门狗中断
    WTCON &= ~(1 << 0); //< 禁止看门狗中断

    WTDAT = 10000; // 初此定时： 128us * 10000 = 1.28s
    WTCNT = 10000; // 看门狗定时间隔： 128us * 10000 = 1.28s

    WTCON &= ~(1 << 5);
    WTCON |= (1 << 5); // 打开看门狗

    return;
}