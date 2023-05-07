#include "beep.h"
#include "key.h"
#include "led.h"
#include "pwm.h"
#include "s3c4412_interrupt.h"
#include "stdio.h"
#include "system.h"
#include "uart.h"

void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

int main(void)
{
    uart_init();
    key_init();
    led_int();

    printf("OK");

    beep_init();
    pwm_timer0_init(2000, 50);

    interrupt_init();

    //  等待中断程序发生
    while (1) {
        // beep_ctrl(1);
        led_ctrl(0, 1);
        led_ctrl(1, 0);
        delay(0x300000);
        // beep_ctrl(0);
        led_ctrl(0, 0);
        led_ctrl(1, 1);
        delay(0x300000);
        // pwm_timer0_update(2000, 50);
    }

    return 0;
}