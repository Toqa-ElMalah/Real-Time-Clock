/*
 * lcd1.c
 *
 * Created: 10/13/2023 3:29:49 PM
 *  Author: DELL
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "lcd1_config.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0c
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#if defined four_bits_mode
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EIGHT_BITS 0x38
#endif

#define port_EN 'A'
#define EN 0
#define port_RW 'A'
#define RW 1
#define port_RS 'A'
#define RS 2

void LCD_vInit(char port);
static void enable (void);
void LCD_vSend_cmd(char port,char cmd);
void LCD_vSend_char(char port,char data);
void LCD_vSend_string(char port,char *data);
void LCD_clearscreen(char port);
void LCD_movecursor(char port,char row,char coloumn);

#endif

