/*
 * RTC.c
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd1.h"
#include "Seven Segment Driver.h"
#include "TIMER.h"
#include "Keypad_Driver.h"
#include "std_macrous.h"

unsigned char minutes_counter=0,hours_counter=0,first_digit,second_digit,val;
volatile unsigned char seconds_counter=0;

int main(void)
{
	LCD_vInit('A');
	keypad_vInit();
	sevensegment_init('B');
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_vSend_string('A',"press 1 to:");
	LCD_movecursor('A',2,1);
	LCD_vSend_string('A',"set clock");
	Timer2_overflow_init_interrupt ();

    while(1)
    {
		val = keypad_u8Read();
		if (val != NOTPRESSED){
			if(val=='1'){
				LCD_clearscreen('A');
				LCD_vSend_string('A',"hours=--");
				LCD_movecursor('A',1,7);
				_delay_ms(500);
				do{
					first_digit=keypad_u8Read();
    }while(first_digit==NOTPRESSED);
	
	LCD_vSend_char('A',first_digit);
	_delay_ms(300);
	
	do{
		second_digit=keypad_u8Read();
	}while (second_digit==NOTPRESSED);
	
	LCD_vSend_char('A',second_digit);
	_delay_ms(300);
	hours_counter=(second_digit-48)+10*(first_digit-48);
	LCD_clearscreen('A');
	
	LCD_vSend_string('A',"minutes=--");
				LCD_movecursor('A',1,9);
				_delay_ms(500);
				do{
					first_digit=keypad_u8Read();
    }while(first_digit==NOTPRESSED);
	
	LCD_vSend_char('A',first_digit);
	_delay_ms(300);
	
	do{
		second_digit=keypad_u8Read();
	}while (second_digit==NOTPRESSED);
	
	LCD_vSend_char('A',second_digit);
	_delay_ms(300);
	minutes_counter=(second_digit-48)+10*(first_digit-48);
	LCD_clearscreen('A');
	
	LCD_vSend_string('A',"seconds=--");
	LCD_movecursor('A',1,9);
	_delay_ms(500);
	do{
		first_digit=keypad_u8Read();
	}while(first_digit==NOTPRESSED);
	
	LCD_vSend_char('A',first_digit);
	_delay_ms(300);
	
	do{
		second_digit=keypad_u8Read();
	}while (second_digit==NOTPRESSED);
	
	LCD_vSend_char('A',second_digit);
	_delay_ms(300);
	seconds_counter=(second_digit-48)+10*(first_digit-48);
	LCD_clearscreen('A');
	LCD_vSend_string('A',"press 1 to:");
	LCD_movecursor('A',2,1);
	LCD_vSend_string('A',"set clock");
	
  }
   else {
	   LCD_clearscreen('A');
	   LCD_vSend_string('A',"wrong choice");
	   _delay_ms(200);
	   LCD_clearscreen('A');
	   LCD_vSend_string('A',"press 1 to:");
	   LCD_movecursor('A',2,1);
	   LCD_vSend_string('A',"set clock");
   }

				}
				
				SET_BIT(PORTC,1);
				SET_BIT(PORTC,2);
				SET_BIT(PORTC,3);
				SET_BIT(PORTC,4);
				SET_BIT(PORTC,5);
				CLR_BIT(PORTC,0);
				sevensegment_write('B',seconds_counter%10);
				_delay_ms(5);
				
				SET_BIT(PORTC,0);
				SET_BIT(PORTC,2);
				SET_BIT(PORTC,3);
				SET_BIT(PORTC,4);
				SET_BIT(PORTC,5);
				CLR_BIT(PORTC,1);
				sevensegment_write('B',seconds_counter/10);
				_delay_ms(5);
				
				SET_BIT(PORTC,0);
				SET_BIT(PORTC,1);
				SET_BIT(PORTC,3);
				SET_BIT(PORTC,4);
				SET_BIT(PORTC,5);
				CLR_BIT(PORTC,2);
				sevensegment_write('B',minutes_counter%10);
				_delay_ms(5);
				
				SET_BIT(PORTC,0);
				SET_BIT(PORTC,1);
				SET_BIT(PORTC,2);
				SET_BIT(PORTC,4);
				SET_BIT(PORTC,5);
				CLR_BIT(PORTC,3);
				sevensegment_write('B',minutes_counter/10);
				_delay_ms(5);
				
				SET_BIT(PORTC,0);
				SET_BIT(PORTC,1);
				SET_BIT(PORTC,2);
				SET_BIT(PORTC,3);
				SET_BIT(PORTC,5);
				CLR_BIT(PORTC,4);
				sevensegment_write('B',hours_counter%10);
				_delay_ms(5);
				
				SET_BIT(PORTC,0);
				SET_BIT(PORTC,1);
				SET_BIT(PORTC,2);
				SET_BIT(PORTC,3);
				SET_BIT(PORTC,4);
				CLR_BIT(PORTC,5);
				sevensegment_write('B',hours_counter/10);
				_delay_ms(5);
				
				if (seconds_counter==60){
					seconds_counter=0;
					minutes_counter++;
				}
				if (minutes_counter==60){
					minutes_counter=0;
					hours_counter++;
				}
				if (hours_counter==24){
					hours_counter=0;
				}
	}
				}				
				
	ISR (TIMER2_OVF_vect){
		 seconds_counter++;
				}	