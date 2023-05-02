#include "key.h"
#include "s3c4412_interrupt.h"
#include "stdio.h"
#include "led.h"

extern void uart_init(void);

extern void putc(unsigned char c);

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

    led_ctrl(0, 0);
    led_ctrl(1, 1);

    interrupt_init();

    interrupt_vector_table();

    // 等待中断程序发生
    while (1)
    {
    }

    return 0;
}