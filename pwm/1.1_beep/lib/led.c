#include "key.h"
#include "s3c4412_gpio.h"
#include "stdio.h"

void led_int(void)
{
	GPL2CON = 0x00000001;
	GPK1CON = 0x00000010;

	return;
}

void led_ctrl(int led_num, int on)
{
	if (led_num == 0)
	{
		if (on)
		{
			GPL2DAT = 0b00000001;
		}
		else
		{
			GPL2DAT = 0b00000000;
		}
	}
	else if (led_num == 1)
	{
		if (on)
		{
			GPK1DAT = 0b00000010;
		}
		else
		{
			GPK1DAT = 0b00000000;
		}
	}

	return;
}