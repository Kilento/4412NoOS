#ifndef _BEEP_H_
#define _BEEP_H_

#ifdef __cplusplus
extern "C" {
#endif

void beep_init(void);

void beep_ctrl(int on);

#ifdef __cplusplus
}
#endif

#endif