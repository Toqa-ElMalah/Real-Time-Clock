/*
 * TIMER.h
 *
 * Created: 10/26/2023 12:01:05 AM
 *  Author: DELL
 */ 


#ifndef TIMER_H_
#define TIMER_H_


void Timer_CTC_init_interrupt (void);
void Timerwave_NonPWM (void);
void Timerwave_PWM (void);
void Timerwave_PhasecorrectPWM (void);
void Timer2_overflow_init_interrupt (void);
void Timer1_wave_fastPWM (double val);

#endif /* TIMER_H_ */