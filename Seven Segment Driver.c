#include "DIO.h"

void sevensegment_init (unsigned char port){
	DIO_set_port_direction(port,0xff);
}

void sevensegment_write (unsigned char port,unsigned char number){
	
	unsigned char arr[]={ 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
		DIO_write_port (port,arr[number]);
}
