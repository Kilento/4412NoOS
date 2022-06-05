#include "s3c4412_uart.h"

void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

void uart_init(void)
{
	int i = 0;
	ULCON2 = 0x00000003; // 8bit数据域 1bit 停止位，无奇偶校验位
	UCON2 = 0x00000005; // 设置收发均为 poll mode
	UFCON2 = 0x00000000; // 禁止FIFO
	UMCON2 = 0x00000000; // 禁止 AFC，禁止Modem
	/* 波特率设置为 115200 */
	/* 	DIV_VAL = UBRDIVn + UFRACVALn/16
	   	DIV_VAL = (SCLK_UART/(bps * 16)) - 1
	   	Where, the divisor should be from 1 to (216 – 1).
       	By using UFRACVALn, you can generate the Baud rate more accurately.
       	For example, if the Baud rate is 115200 bps and SCLK_UART is 24 MHz, UBRDIVn and UFRACVALn are:
	   	DIV_VAL = (24000000/(115200 * 16)) – 1 = 13.02 – 1 = 12.02
	    UBRDIVn = 12 (integer part of DIV_VAL)
		UFRACVALn/16 = 0.02
		Therefore, UFRACVALn = 0 */
	UBRDIV2 = 0x0000000C;
	UFRACVAL2 = 0x00000000;
}

void uart_putc(char c)
{
	while (!(UTRSTAT2 & (1 << 2)));
	UTXH2 = c;

	return;
}

int uart_main(void)
{
	uart_init();

	uart_putc('a');

	return 0;
}