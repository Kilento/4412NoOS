#ifndef _LED_H_
#define _LED_H_

#ifdef __cplusplus
extern "C" {
#endif

void led_int(void);

void led_ctrl(int led_num, int on);

#ifdef __cplusplus
}
#endif

#endif