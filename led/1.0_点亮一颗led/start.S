/*
*	Filename   : start.S
*	Author     : Kilento 
*   Description: To Control LED on iTop-4412
*	Date       : 2021-8-15
*/

/*

LED2  KP_COL0（NetLable） XGNSS_GPIO_0/GPL2_0  	高电平导通（NPN三极管）
LED3  VDD50_EN(NetLable)  Xmmc1CMD/GPK1_1  	高电平导通（NPN三极管）

查阅数据手册《SEC_Exynos4412_Users Manual_Ver.1.00.00》"6.General Purpose Input/Output (GPIO) Control"部分
可以得知控制 GPL2_0 和 GPK1_1 引脚的一些寄存器物理地址
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
	
这个汇编代码0x1002330c是PS_HOLD_CONTROL寄存器，保证电源管理芯片正常工作，0x11000c08是GPX0组控制上下拉的寄存器，有个ONO（GPX0_2）在控制电源管理 
	
*/

#include "s3c4412_gpio.h"

.word 0x2000
.word 0x0
.word 0x0
.word 0x0

_start:
	ldr r0, =0x1002330C
	ldr r1, [r0]
	orr r1, r1, #0x300
	str r1, [r0]

	ldr r0, =0x11000C08
	ldr r1, =0x0
	str r1, [r0]

	//设置 GPL2 为输出模式
	ldr r0, =GPL2CON
	mov r1, #(0x01 << 0)
	str r1, [r0]

	//设置 GPK1 为输出模式
	ldr r0, =GPK1CON
	mov r1, #(0x01 << 4)
	str r1, [r0]

	//设置 GPK1_1 为高电平
	ldr r0, =GPK1DAT
	mov r1, #0x0
	str r1, [r0]

	//设置 GPL2_0 为低电平
	ldr r0, =GPL2DAT
	mov r1, #0x1
	str r1, [r0]
	
b .