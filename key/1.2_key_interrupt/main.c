#include "key.h"
#include "s3c4412_interrupt.h"
#include "stdio.h"

extern void uart_init(void);

extern void putc(unsigned char c);

int main(void)
{
    uart_init();
    key_init();

    interrupt_vector_table();

    interrupt_init();

    return 0;
}