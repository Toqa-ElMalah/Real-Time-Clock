/*
 * lcd1.c
 *
 * Created: 10/14/2023 1:10:33 PM
 *  Author: DELL
 */ 

#include "lcd1.h"
#define  F_CPU 8000000UL
#include <util/delay.h>


void LCD_vInit (char port){
	_delay_ms(200);
	#if defined eight_bits_mode
	DIO_set_port_direction(port,0xff);
	DIO_vsetPINDir(port_EN,EN,1);
	DIO_vsetPINDir(port_RW,RW,1);
	DIO_vsetPINDir(port_RS,RS,1);
	DIO_write(port_RW,RW,0);
	LCD_vSend_cmd(port,EIGHT_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(port,CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(port,CLR_SCREEN);		
	_delay_ms(10);	
	LCD_vSend_cmd(port,ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined four_bits_mode
	DIO_vsetPINDir(port,4,1);
	DIO_vsetPINDir(port,5,1);
	DIO_vsetPINDir(port,6,1);
	DIO_vsetPINDir(port,7,1);
	DIO_vsetPINDir(port_EN,EN,1);
	DIO_vsetPINDir(port_RW,RW,1);
	DIO_vsetPINDir(port_RS,RS,1);
	DIO_write(port_RW,RW,0);
	LCD_vSend_cmd(port,RETURN_HOME);
	_delay_ms(10);
	LCD_vSend_cmd(port,FOUR_BITS);
	_delay_ms(1);
	LCD_vSend_cmd(port,CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_vSend_cmd(port,CLR_SCREEN);
	_delay_ms(10);
	LCD_vSend_cmd(port,ENTRY_MODE);
	_delay_ms(1);
	#endif
}

static void enable(void){
	DIO_write(port_EN,EN,1);
	_delay_ms(2);
	DIO_write(port_EN,EN,0);
	_delay_ms(2);
}

void LCD_vSend_cmd (char port,char cmd){
	#if defined eight_bits_mode
	DIO_write_port(port,cmd);
	DIO_write(port_RS,RS,0);
	enable();
	
	#elif defined four_bits_mode
	write_high_nibble(port,cmd>>4);
	DIO_write(port_RS,RS,0);
	enable();
	write_high_nibble(port,cmd);
	DIO_write(port_RS,RS,0);
	enable();
	#endif
	_delay_ms(1);
}

void LCD_vSend_char (char port,char data){
	#if defined eight_bits_mode
	DIO_write_port(port,data);
	DIO_write(port_RS,RS,1);
	enable();
	
	#elif defined four_bits_mode
	write_high_nibble(port,data>>4);
	DIO_write(port_RS,RS,1);
	enable();
	write_high_nibble(port,data);
	DIO_write(port_RS,RS,1);
	enable();
	#endif
	_delay_ms(1);
}

void LCD_vSend_string (char port,char * data){
	while((* data) != '\0'){
		LCD_vSend_char(port,* data);
		data++;
	}	
	}
	
void LCD_clearscreen(char port){
	LCD_vSend_cmd(port,CLR_SCREEN);
	_delay_ms(10);
}

void LCD_movecursor (char port,char row,char coloumn){
	char data;
	if(row>2 || row<1 || coloumn>16 || coloumn<1){
		data=0x80;
	}
	else if (row==1){
		data = 0x80+coloumn-1;
	}
	else if (row==2){
		data = 0xc0+coloumn-1;
	}
	LCD_vSend_cmd(port,data);
	_delay_ms(1);
	
}
