#include "pwm.h"
#include "s3c4412_gpio.h"
#include "stdio.h"

void pwm_timer0_init(int pwm_freq, int duty)
{
    // int count = 0;
    //  使用 timer0 产生一个 2KHz 的时钟频率
    //  PCLK = MOUTCORE / (ATB_RATIO + 1) / (PCLK_DBG_RATIO + 1) = 1000MHz / 5 / 2 = 100MHz
    //  PWM 时钟频率 = PCLK/({prescaler value + 1})/{divider value} = 100MHz / 25 / 4 = 1MHz
    //  PWM 时钟周期 = 1 / 100KHz = 10us
    PWM.TCFG0 = (PWM.TCFG0 & ~0xff) | 0XF9; // prescaler value = 24
    PWM.TCFG1 = (PWM.TCFG1 & ~0xf) | 0X2; // divider value = 4
    PWM.TCON = (PWM.TCON & ~0xff) | (1 << 1) | (1 << 0) | (1 << 4);

    if (pwm_freq != 0) {
        // 暂时未移植除法，暂时写死
        // count = 1000000 / pwm_freq;
        // PWM.TCNTB0 = count; // 例如设置 PWM 波频率为 2KHz，TCNTB0 = 1000KHz / 2KHz = 500
        // if (duty <= 100 && duty >= 0) {
        //     // 占空比 50%， 则 TCMPB0 = 500 * 50 / 100 = 250
        //     PWM.TCMPB0 = count * duty / 100;
        // }
        PWM.TCNTB0 = 100;
        PWM.TCMPB0 = 50;
    }

    return;
}

void pwm_timer0_update(int pwm_freq, int duty)
{
    // unsigned long count = 0;

    if (pwm_freq != 0) {
        // count = 1000000 / pwm_freq;
        // PWM.TCNTB0 = count; // 例如设置 PWM 波频率为 2KHz，TCNTB0 = 1000KHz / 2KHz = 500
        // if (duty <= 100 && duty >= 0) {
        //     // 占空比 50%， 则 TCMPB0 = 500 * 50 / 100 = 250
        //     PWM.TCMPB0 = count * duty / 100;
        // }
        PWM.TCNTB0 = 100;
        PWM.TCMPB0 = 50;
    }
    PWM.TCON = (PWM.TCON & ~0xff) | (1 << 1) | (1 << 0);

    return;
}