#ifndef S3C4412_INTERRUPT_H
#define S3C4412_INTERRUPT_H

#define EXCEPTION_VECTOR_TABLE_BASE 0x50000000
#define INTERRUPT_CONTROLLER_BASE1 0x10480000
#define INTERRUPT_CONTROLLER_BASE2 0x10490000

#define EXCEPTION_VECTOR_RESET \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x00))
#define EXCEPTION_VECTOR_UNDEF \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x04))
#define EXCEPTION_VECTOR_SUPERVISOR \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x08))
#define EXCEPTION_VECTOR_PREFETCH \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x0C))
#define EXCEPTION_VECTOR_DATA \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x10))
#define EXCEPTION_VECTOR_IRQ \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x18))
#define EXCEPTION_VECTOR_FIQ \
    (*(volatile unsigned long *)(EXCEPTION_VECTOR_TABLE_BASE + 0x1C))

#define ICCICR_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x0000))
#define ICCICR_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x4000))
#define ICCICR_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x8000))
#define ICCICR_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0xC000))

#define ICCPMR_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x0004))
#define ICCPMR_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x4004))
#define ICCPMR_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x8004))
#define ICCPMR_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0xC004))

#define ICCBPR_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x0008))
#define ICCBPR_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x4008))
#define ICCBPR_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x8008))
#define ICCBPR_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0xC008))

#define ICCEOIR_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x0010))
#define ICCEOIR_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x4010))
#define ICCEOIR_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x8010))
#define ICCEOIR_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0xC010))

#define ICCIAR_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x000C))
#define ICCIAR_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x400C))
#define ICCIAR_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0x800C))
#define ICCIAR_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE1 + 0xC00C))

#define ICDDCR \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0000))

#define ICDISER0_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0100))
#define ICDISER1_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0104))
#define ICDISER2_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0108))
#define ICDISER3_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x010c))
#define ICDISER4_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0110))
#define ICDISER0_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x4100))
#define ICDISER0_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x8100))
#define ICDISER0_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0xc100))

#define ICDICPR0_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0280))
#define ICDICPR1_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0284))
#define ICDICPR2_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0288))
#define ICDICPR3_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x028C))
#define ICDICPR4_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0290))
#define ICDICPR0_CPU1 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x4280))
#define ICDICPR0_CPU2 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x8280))
#define ICDICPR0_CPU3 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0xC280))

#define ICDIPTR0_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0800))
#define ICDIPTR1_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0804))
#define ICDIPTR2_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0808))
#define ICDIPTR3_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x080C))
#define ICDIPTR4_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0810))
#define ICDIPTR5_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0814))
#define ICDIPTR6_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0818))
#define ICDIPTR7_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x081C))
#define ICDIPTR8_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0820))
#define ICDIPTR9_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0824))
#define ICDIPTR10_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0828))
#define ICDIPTR11_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x082C))
#define ICDIPTR12_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0830))
#define ICDIPTR13_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0834))
#define ICDIPTR14_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0838))
#define ICDIPTR15_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x083C))
#define ICDIPTR16_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0840))
#define ICDIPTR17_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0844))
#define ICDIPTR18_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0848))
#define ICDIPTR19_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x084C))
#define ICDIPTR20_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0850))
#define ICDIPTR21_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0854))
#define ICDIPTR22_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0858))
#define ICDIPTR23_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x085C))
#define ICDIPTR24_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0860))
#define ICDIPTR25_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0864))
#define ICDIPTR26_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0868))
#define ICDIPTR27_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x086C))
#define ICDIPTR28_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0870))
#define ICDIPTR29_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0874))
#define ICDIPTR30_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0878))
#define ICDIPTR31_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x087c))
#define ICDIPTR32_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0880))
#define ICDIPTR33_CPU0 \
    (*(volatile unsigned long *)(INTERRUPT_CONTROLLER_BASE2 + 0x0884))

void irq_handler(void);

void irq_exception(void);

void interrupt_init(void);

void interrupt_vector_table(void);

#endif