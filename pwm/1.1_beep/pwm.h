#ifndef _PWN_H_
#define _PWN_H_

#ifdef __cplusplus
extern "C" {
#endif

struct tagPWM {
    unsigned long TCFG0;
    unsigned long TCFG1;
    unsigned long TCON;
    unsigned long TCNTB0;
    unsigned long TCMPB0;
    unsigned long TCNTO0;
    unsigned long TCNTB1;
    unsigned long TCMPB1;
    unsigned long TCNTO1;
    unsigned long TCNTB2;
    unsigned long TCMPB2;
    unsigned long TCNTO2;
    unsigned long TCNTB3;
    unsigned long TCMPB3;
    unsigned long TCNTO3;
    unsigned long TCMPB4;
    unsigned long TCNTO4;
    unsigned long TINT_CSTAT;
};

#define PWM (*((volatile struct tagPWM*)0x139D0000))

void pwm_timer0_init(int pwm_freq, int duty);

void pwm_timer0_update(int pwm_freq, int duty);

#ifdef __cplusplus
}
#endif

#endif