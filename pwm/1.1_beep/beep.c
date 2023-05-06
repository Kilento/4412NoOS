#include "pwm.h"
#include "s3c4412_gpio.h"
#include "stdio.h"

void beep_init(void)
{
    GPD0CON = (GPD0CON & ~0xf) | 0x2; // 设置引脚为 TOUT 模式（PWM）
    GPD0PUD = GPD0PUD & ~0x3; // 清除引脚上下拉模式

    return;
}

void beep_ctrl(int on)
{
    if (on) {
        PWM.TCON = (PWM.TCON & ~(1 << 0)) | (1 << 0); // 开启 PWM 定时器
    } else {
        PWM.TCON = PWM.TCON & ~(1 << 0); // 关闭 PWM 定时器
    }
}
