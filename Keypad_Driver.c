#include "Keypad_Driver.h"

void keypad_vInit (void){
	
	DIO_vsetPINDir('D',0,1);
	DIO_vsetPINDir('D',1,1);
	DIO_vsetPINDir('D',2,1);
	DIO_vsetPINDir('D',3,1);
	DIO_vsetPINDir('D',4,0);
	DIO_vsetPINDir('D',5,0);
	DIO_vsetPINDir('D',6,0);
	DIO_vsetPINDir('D',7,0);
	DIO_vconnectpullup('D',4,1);
	DIO_vconnectpullup('D',5,1);
	DIO_vconnectpullup('D',6,1);
	DIO_vconnectpullup('D',7,1);

}

unsigned char keypad_u8Read (void){
	unsigned char arr[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
		char x,row,col,return_val= NOTPRESSED;
		for(row=0;row<4;row++){
			DIO_write('D',0,1);
			DIO_write('D',1,1);
			DIO_write('D',2,1);
			DIO_write('D',3,1);
			DIO_write('D',row,0);
			
			for (col=0;col<4;col++){
				x = DIO_u8read('D',(col+4));
				if(x==0){
					return_val = arr[row][col];
					break;
				}
			}				
		if (x==0){
			break;
		}
			}				
		return return_val;
			}
