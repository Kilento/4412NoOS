#include "stdio.h"

extern void uart_init(void);

extern void putc(unsigned char c);

int uart_main(void)
{
    uart_init();

    while (1) {
        printf("hello world\n");
    }

    return 0;
}