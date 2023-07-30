#include "s3c4412_interrupt.h"
#include "key.h"
#include "led.h"
#include "s3c4412_gpio.h"
#include "s3c4412_wdt.h"
#include "stdio.h"

// 函数指针类型
typedef void (*ExcHandler)(void);

// 全局异常向量表
ExcHandler g_ExcVectorTable[32];

// 异常处理函数入口
void ExcHandlerEntry(unsigned int vector)
{
    ExcHandler handler = g_ExcVectorTable[vector >> 2];
    handler();
}

static void reset_exception(void)
{
    printf("reset_exception.\n");
    return;
}

static void undef_exception(void)
{
    printf("undef_exception.\n");

    return;
}

void soft_exception(void)
{
    printf("soft_exception.\n");

    return;
}

static void prefetch_exception(void)
{
    printf("prefetch_exception.\n");

    return;
}

static void data_exception(void)
{
    printf("data_exception.\n");

    return;
}

static void fiq_exception(void)
{
    printf("fiq_exception.\n");

    return;
}

void irq_exception(void)
{
    int irq_num = 0;
    int key_id = 0;

    led_ctrl(0, 0);
    led_ctrl(1, 1);

    irq_num = ICCIAR_CPU0 & 0x3ff;
    printf("%d\n", irq_num);
    switch (irq_num) {
        /* HOME 按键 */
    case 57: {
        key_id = KEY_HOME;
        EXT_INT41_PEND |= (0x1 << 1); // 清GPIO中断标志位
        put_key_value(key_id);
        break;
    }
    /* 看门狗中断 */
    case 75: {
        printf("irq number=%d\n", irq_num);
        WTCLRINT = 0x1;
        break;
    }
    default: {
        printf("unknown irq number=%d\n", irq_num);
        break;
    }
    }

    ICCEOIR_CPU0 = (ICCEOIR_CPU0 & (~0x3FF)) | irq_num; // 清cpu中断标志

    return;
}

void interrupt_init(void)
{
    /* 中断处理:
     * <1> IRQ模式: 中断irq引脚, 中断GIC
     * <2> GIC中断：中断号ID
     *      Key2: GPX1_1/XEINT9
     *      (1) Page 752: EINT9  ---> 中断ID: 57
     *      (2) GPX1_1 配置成中断功能: 0xF
     *      (3) GPX1_1 禁止上拉和下拉 PUD[3:2]
     *      (4) EXT_INT41CON[1] : 0x2 ---> 下降沿触发中断falling edge
     *      (5) EXT_INT41_MASK[1]: 0x0 ---> Enables Interrupt
     * <3> GIC 配置:
     *      (1) ICCICR_CPU0[0] : 0x1048_0000 :   1 ---> enable
     *      (2) ICDDCR:   0x1049_0000 :  1 ---> enable
     *      (3) ICCPMR_CPU0[7:0]:  0x1048_004 :  255屏蔽优先级
     *           ICDIPR_CPU0  偏移57个字节(每个中断占一个字节), 默认0，最高优先级
     *      (4) ICCIAR_CPU0[9:0]: 0x1048_000C:  中断ID
     *      (5) 结束中断
     *      (6) ICDISER_CPU0[57]:   Set-Enable Interrupt 1
     *      (7)  ICDIPTR_CPU:   选择该中断递送给哪一个CPU
     *
     * <4> 中断清除
     *      (1) EXT_INT41_PEND[1]:  0
     *      (2)  (4) ICCICPR_CPU0
     *      (3)  (5) ICCEOIR_CPU0[9:0]: 0x1048_0010: 回写ID给GIC
     */

    printf("interrupt_init\n");
    /*
        GPX1_1 - HOME - EXT_INT41[1] - EINT[9] - SPI(25) - ID(57)
        GPX1_2 - BACK - EXT_INT41[2] - EINT[10] - SPI(26) - ID(58)
        GPX3_3 - SLEEP - EXT_INT43[3] - EINT[27] - SPI(32) - ID(64)
        GPX2_0 - VOL- - EXT_INT42[0] - EINT[16] - SPI(32) - ID(64)
        GPX2_1 - VOL+ - EXT_INT42[1] - EINT[17] - SPI(32) - ID(64)
        WDT - SPI(43) - ID(75)
    */

    ICDDCR = 1; // 使能中断分配器
    ICDISER1_CPU0 |= 1 << 25; // 57/32 = 1...25
    // ICDISER1_CPU0 |= 1 << 26; // 58/32 = 1...26
    // ICDISER2_CPU0 |= 1 << 0;  // 64/32 = 2...0
    ICDISER2_CPU0 |= 1 << 11; // 75 / 32 = 2..11
    // 设置SPI[25]/ID[57]由哪个cpu处理，当前设置为cpu0的irq中断
    ICDIPTR14_CPU0 |= 1 << 8;
    // 设置SPI[43]/ID[75]由哪个cpu处理，当前设置为cpu0的irq中断
    ICDIPTR18_CPU0 |= 1 << 24;
    ICCPMR_CPU0 = 0xff;
    ICCICR_CPU0 = 1;

    return;
}

void interrupt_vector_table(void)
{
    printf("interrupt_vector_table begin\n");
    __asm volatile("mcr p15, 0, %0, c12, c0, 0" ::"r"(EXCEPTION_VECTOR_TABLE_BASE));

    EXCEPTION_VECTOR_RESET = (unsigned long)reset_exception;
    EXCEPTION_VECTOR_UNDEF = (unsigned long)undef_exception;
    EXCEPTION_VECTOR_SUPERVISOR = (unsigned long)soft_exception;
    EXCEPTION_VECTOR_PREFETCH = (unsigned long)prefetch_exception;
    EXCEPTION_VECTOR_DATA = (unsigned long)data_exception;
    EXCEPTION_VECTOR_IRQ = (unsigned long)irq_handler;
    EXCEPTION_VECTOR_FIQ = (unsigned long)fiq_exception;

    // g_ExcVectorTable[0] = (ExcHandler)reset_exception;
    // g_ExcVectorTable[1] = (ExcHandler)undef_exception;
    // g_ExcVectorTable[2] = (ExcHandler)soft_exception;
    // g_ExcVectorTable[3] = (ExcHandler)prefetch_exception;
    // g_ExcVectorTable[4] = (ExcHandler)data_exception;
    // g_ExcVectorTable[5] = (ExcHandler)irq_exception;
    // g_ExcVectorTable[6] = (ExcHandler)fiq_exception;

    //    asm("mcr p15, 0, %[addr], c12, c0, 0" ::[addr] "r"(g_ExcVectorTable));
    // 将全局异常向量表的地址写入协处理器 12 中

    printf("interrupt_vector_table end = %p\n", EXCEPTION_VECTOR_TABLE_BASE);

    return;
}
