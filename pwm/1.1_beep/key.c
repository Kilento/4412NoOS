#include "key.h"
#include "s3c4412_gpio.h"
#include "stdio.h"

void key_init(void)
{
    /*
        GPX1_1 - HOME - EXT_INT41[1] - EINT[9] - SPI(25) - ID(57)
        GPX1_2 - BACK - EXT_INT41[2] - EINT[10] - SPI(26) - ID(58)
        GPX3_3 - SLEEP - EXT_INT43[3] - EINT[27] - SPI(32) - ID(64)
        GPX2_0 - VOL- - EXT_INT42[0] - EINT[16] - SPI(32) - ID(64)
        GPX2_1 - VOL+ - EXT_INT42[1] - EINT[17] - SPI(32) - ID(64)
    */
    //  GPX1CON = 0x00000ff0; // 设置引脚 GPX1_1 and GPX1_2 为中断模式
    //   GPX2CON = 0x000000ff; // 设置引脚 GPX2_0 and GPX2_1 为中断模式
    //    GPX3CON = 0x0000f000; // 设置引脚 GPX3_3 为中断模式
    GPX1CON = (GPX1CON & (~(0xf << 4))) | (0xf << 4); // 配置引脚功能为外部中断
    GPX1PUD = GPX1PUD & (~(0x3 << 2)); // 关闭上下拉电阻
    EXT_INT41_CON = (EXT_INT41_CON & (~(0xf << 4))) | (0x2 << 4); // 外部中断触发方式
    EXT_INT41_MASK = EXT_INT41_MASK & (~(0x1 << 1)); // 使能中断

    // GPX1PUD = 0x00000000; // 引脚 GPX1_1 and GPX1_2 禁止上下拉
    // GPX2PUD = 0x00000000; // 引脚 GPX2_0 and GPX2_1 禁止上下拉
    // GPX3PUD = 0x00000000; // 引脚 GPX3_3 禁止上下拉

    // EXT_INT41_CON = 0x00000220; // 设置引脚 GPX1_1 and GPX1_2 中断为下降沿模式
    // EXT_INT42_CON = 0x00000022; // 设置引脚 GPX2_0 and GPX2_1 中断为下降沿模式
    // EXT_INT43_CON = 0x00002000; // 设置引脚 GPX3_3 中断为下降沿模式

    // EXT_INT41_MASK = 0x00000000; // 使能  GPX1_1 and GPX1_2 的中断
    // EXT_INT42_MASK = 0x00000000; // 使能  GPX2_0 and GPX2_1 的中断
    // EXT_INT43_MASK = 0x00000000; // 使能  GPX3_3 的中断

    return;
}

int get_key_value(int key_id)
{
    int key_value = 0;

    switch (key_id) {
    case KEY_HOME: {
        key_value = GPX1DAT & 0x2;
        break;
    }
    case KEY_BACK: {
        key_value = GPX1DAT & 0x4;
        break;
    }
    case KEY_SLEEP: {
        key_value = GPX3DAT & 0x8;
        break;
    }
    case KEY_VOLUME_REDUCE: {
        key_value = GPX2DAT & 0x1;
        break;
    }
    case KEY_VOLUME_PLUS: {
        key_value = GPX2DAT & 0x2;
        break;
    }
    default: {
        key_value = 1;
        break;
    }
    }

    return key_value;
}

void put_key_value(int key_id)
{
    switch (key_id) {
    case KEY_HOME: {
        printf("Home\n");
        break;
    }
    case KEY_BACK: {
        printf("Back\n");
        break;
    }
    case KEY_SLEEP: {
        printf("Sleep\n");
        break;
    }
    case KEY_VOLUME_REDUCE: {
        printf("Vol-\n");
        break;
    }
    case KEY_VOLUME_PLUS: {
        printf("Vol+\n");
        break;
    }
    default: {
        printf("Invalid key id = %d\n", key_id);
        break;
    }
    }

    return;
}
