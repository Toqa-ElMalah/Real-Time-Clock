/*
 * Keypad_Driver.h
 *
 * Created: 10/17/2023 11:09:45 PM
 *  Author: DELL
 */ 


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_
#define NOTPRESSED 0xff

void keypad_vInit (void);
unsigned char keypad_u8Read (void);

#endif /* KEYPAD_DRIVER_H_ */