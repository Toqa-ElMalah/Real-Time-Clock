#include <avr/interrupt.h>
#include <avr/io.h>
#include "std_macrous.h"

void Timer_CTC_init_interrupt (void){
	SET_BIT(TCCR0,WGM01);
	OCR0 = 80;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void Timerwave_NonPWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM01); //CTC mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00); //TOGGLE OC0
}

void Timerwave_PWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM00); //PWM mode
	SET_BIT(TCCR0,WGM01); //PWM mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*non_inverting mode
	SET_BIT(TCCR0,COM01); */
	
}

void Timerwave_PhasecorrectPWM (void){
	
	SET_BIT(DDRB,3); //OC0 as output
	SET_BIT(TCCR0,WGM00); //Phase correct PWM mode
	OCR0=64;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	/*clear OC0 up counting,set OC0 down counting
	SET_BIT(TCCR0,COM01); */
}

void Timer2_overflow_init_interrupt (void){
	
	SET_BIT(ASSR,AS2);
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	sei();
	SET_BIT(TIMSK,TOIE2);
}

void Timer1_wave_fastPWM (double val){
	SET_BIT(DDRD,5);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	OCR1A=val*1000;
	ICR1=19999;
	SET_BIT(TCCR1B,CS10);
	/* NON-INVERTING MODE */
	SET_BIT(TCCR1A,COM1A1);
}
