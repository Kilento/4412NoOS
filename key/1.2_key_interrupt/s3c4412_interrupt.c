#include "s3c4412_interrupt.h"
#include "key.h"
#include "s3c4412_gpio.h"
#include "stdio.h"

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

void irq_exception(void)
{
    int irq_num = 0;
    int key_id = 0;

    irq_num = ICCIAR_CPU0 & 0x3ff;

    switch (irq_num) {
        case 57:
        {
            key_id = KEY_HOME;
            EXT_INT41_PEND = EXT_INT41_PEND | ((0x1 << 1)); // 清GPIO中断标志位
            ICDICPR1_CPU0 |= (0x1 << 25); // 清GIC中断标志位
            put_key_value(key_id);
            break;
        }
        default:
        {
            printf("unknown irq number=%d", irq_num);
            break;
        }
    }

    ICCEOIR_CPU0 &= (~(0x3ff)) | irq_num; // 清cpu中断标志

    return;
}

static void fiq_exception(void)
{
    printf("fiq_exception.\n");

    return;
}

void interrupt_init(void)
{
    /*
        GPX1_1 - HOME - EXT_INT41[1] - EINT[9] - SPI(25) - ID(57)
        GPX1_2 - BACK - EXT_INT41[2] - EINT[10] - SPI(26) - ID(58)
        GPX3_3 - SLEEP - EXT_INT43[3] - EINT[27] - SPI(32) - ID(64)
        GPX2_0 - VOL- - EXT_INT42[0] - EINT[16] - SPI(32) - ID(64)
        GPX2_1 - VOL+ - EXT_INT42[1] - EINT[17] - SPI(32) - ID(64)
    */

    ICDDCR = 1;               // 使能中断分配器
    ICDISER1_CPU0 |= 1 << 25; // 57/32 = 1...25
    ICDISER1_CPU0 |= 1 << 26; // 58/32 = 1...26
    ICDISER2_CPU0 |= 1 << 0;  // 64 / 32 = 2...0
    // 设置SPI[25]/ID[57]由哪个cpu处理，当前设置为cpu0的irq中断
    ICDIPTR14_CPU0 |= 1 << 8;
    ICCICR_CPU0 |= 1;
    ICCPMR_CPU0 = 0xff;

    return;
}

void interrupt_vector_table(void)
{
    EXCEPTION_VECTOR_RESET = (unsigned long)reset_exception;
    EXCEPTION_VECTOR_UNDEF = (unsigned long)undef_exception;
    EXCEPTION_VECTOR_SUPERVISOR = (unsigned long)soft_exception;
    EXCEPTION_VECTOR_PREFETCH = (unsigned long)prefetch_exception;
    EXCEPTION_VECTOR_DATA = (unsigned long)data_exception;
    EXCEPTION_VECTOR_IRQ = (unsigned long)irq_handle;
    EXCEPTION_VECTOR_FIQ = (unsigned long)fiq_exception;

    return;
}