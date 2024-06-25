
#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD-CONFIG.h"

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#define EN_port 'B'
#define EN_pin 0
#define RS_port 'B'
#define RS_pin 2
#define RW_port 'B'
#define RW_pin 1

#if defined four_bits_mode
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EIGHT_BITS 0x38
#endif

void LCD_int (char Data_port);
void LCD_send_char (char Data_port, char data);
static void enable (void);
void LCD_send_command (char Data_port, char command);
void LCD_send_string (char Data_port, char *ptr);
void LCD_move_coursor (char Data_port, char row, char column);

#endif 
