/*

LED2  KP_COL0（NetLable） XGNSS_GPIO_0/GPL2_0  	高电平导通（NPN三极管）
LED3  VDD50_EN(NetLable)  Xmmc1CMD/GPK1_1  	高电平导通（NPN三极管）

查阅数据手册《SEC_Exynos4412_Users Manual_Ver.1.00.00》"6.General Purpose Input/Output (GPIO) Control"部分
可以得知控制GPL2_0和GPK1_1引脚的一些寄存器物理地址
GPL2_0：

GPL2CON(用于控制GPIO的模式)：
Base Address: 0x1100_0000
Address = Base Address + 0x0100, Reset Value = 0x0000_0000
将其配置成输出模式：GPL2CON[3:0]=0x1

GPL2DAT(输出模式时，用于控制GPIO的输出电平)：
	Base Address: 0x1100_0000
	Address = Base Address + 0x0104, Reset Value = 0x00
控制GPL2_0的输出电平：GPL2[0]=0|1

其余寄存器不需要用到

GPK1CON(用于控制GPIO的模式)：
Base Address: 0x1100_0000
Address = Base Address + 0x0060, Reset Value = 0x0000_0000
将其配置成输出模式：GPKCON[7:4]=0x1
GPK1DAT(输出模式时，用于控制GPIO的输出电平)：
	Base Address: 0x1100_0000
	Address = Base Address + 0x0064, Reset Value = 0x00
控制GPK_1的输出电平：GPLK[1]=0|1

*/

#define     GPL2CON     (*(volatile unsigned long *) 0x11000100)
#define		GPL2DAT     (*(volatile unsigned long *) 0x11000104)

#define 	GPK1CON 	(*(volatile unsigned long *) 0x11000060)
#define 	GPK1DAT		(*(volatile unsigned long *) 0x11000064)

//GPL2_0, GPK1_1
void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

void led_blink(void)
{
	GPL2CON = 0x00000001;
	GPK1CON = 0x00000010;

	while(1)
	{
		GPL2DAT = 0b00000001;
		GPK1DAT = 0b00000000;
		delay(0x80000);
		GPL2DAT = 0b00000000;
		GPK1DAT = 0b00000010;
		delay(0x80000);
	}	
}