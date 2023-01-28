#include "key.h"
#include "stdio.h"

extern void uart_init(void);

extern void putc(unsigned char c);

int main(void)
{
    uart_init();
    key_init();

    int key_value = 0;
    printf("OK\n");
    while (1) {
        key_value = get_key_value(KEY_HOME);
        if (0 == key_value) {
            put_key_value(KEY_HOME);
        }

        key_value = get_key_value(KEY_BACK);
        if (0 == key_value) {
            put_key_value(KEY_BACK);
        }

        key_value = get_key_value(KEY_SLEEP);
        if (0 == key_value) {
            put_key_value(KEY_SLEEP);
        }

        key_value = get_key_value(KEY_VOLUME_REDUCE);
        if (0 == key_value) {
            put_key_value(KEY_VOLUME_REDUCE);
        }

        key_value = get_key_value(KEY_VOLUME_PLUS);
        if (0 == key_value) {
            put_key_value(KEY_VOLUME_PLUS);
        }
    }

    return 0;
}