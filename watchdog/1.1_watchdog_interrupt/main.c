#include "key.h"
#include "led.h"
#include "s3c4412_interrupt.h"
#include "stdio.h"
#include "uart.h"
#include "wdt.h"

int main(void)
{
    uart_init();
    key_init();
    led_int();
    wdt_init();

    printf("OK");

    led_ctrl(0, 1);
    led_ctrl(1, 0);

    interrupt_init();

    // interrupt_vector_table();

    // 等待中断程序发生
    while (1) {
    }

    return 0;
}