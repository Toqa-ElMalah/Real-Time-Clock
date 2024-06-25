#include <avr/io.h>
#include "std_macrous.h"

void DIO_vsetPINDir (unsigned char port,unsigned char pinnumber,unsigned char direction){
	switch (port){
		
		case'A':
		if (direction==1){
			SET_BIT(DDRA,pinnumber);
		}
		else
		CLR_BIT(DDRA,pinnumber);
	
	break;
	
	case'B':
	if (direction==1){
		SET_BIT(DDRB,pinnumber);
	}
	else
	CLR_BIT(DDRB,pinnumber);
   break;
 
   case'C':
    if (direction==1){
	 SET_BIT(DDRC,pinnumber);
  }
   else
    CLR_BIT(DDRC,pinnumber);
	break;
	
	case'D':
	if (direction==1){
		SET_BIT(DDRD,pinnumber);
	}
	else
	CLR_BIT(DDRD,pinnumber);
    break;
    deafult:
    break;
}
}

void DIO_write (unsigned char portname,unsigned char pinnumber,unsigned char outputvalue){
	
	switch (portname){
		
		case'A':
		if (outputvalue==1){
			SET_BIT(PORTA,pinnumber);
		}
		else
		CLR_BIT(PORTA,pinnumber);
		
		break;
		
		case'B':
		if (outputvalue==1){
			SET_BIT(PORTB,pinnumber);
		}
		else
		CLR_BIT(PORTB,pinnumber);
		break;
		
		case'C':
		if (outputvalue==1){
			SET_BIT(PORTC,pinnumber);
		}
		else
		CLR_BIT(PORTC,pinnumber);
		break;
		
		case'D':
		if (outputvalue==1){
			SET_BIT(PORTD,pinnumber);
		}
		else
		CLR_BIT(PORTD,pinnumber);
		break;
		deafult:
		break;
	}
}

unsigned char DIO_u8read (unsigned char portname,unsigned char pinnumber){
	unsigned char return_value = 0;
	switch(portname){
		
		case'A':
		return_value = READ_BIT(PINA,pinnumber);
		break;
		case'B':
		return_value = READ_BIT(PINB,pinnumber);
		break;
		case'C':
		return_value = READ_BIT(PINC,pinnumber);
		break;
		case'D':
		return_value = READ_BIT(PIND,pinnumber);
		break;
		default:
		break;
	}
	return return_value;
}

void DIO_toggle (unsigned char portname,unsigned char pinnumber){
	switch(portname){
		case'A':
		TOG_BIT(PORTA,pinnumber);
		break;
		case'B':
		TOG_BIT(PORTB,pinnumber);
		break;
		case'C':
		TOG_BIT(PORTC,pinnumber);
		break;
		case'D':
		TOG_BIT(PORTD,pinnumber);
		break;
		default:
		break;
	}
}

void DIO_set_port_direction (unsigned char portname,unsigned char direction){
	switch(portname){
		case'A':
		DDRA=direction;
		break;
		case'B':
		DDRB=direction;
		break;
		case'C':
		DDRC=direction;
		break;
		case'D':
		DDRD=direction;
		break;
		default:
		break;
	}		
}

void DIO_write_port (unsigned char portname,unsigned char portvalue){
	switch(portname){
		case'A':
		PORTA=portvalue;
		break;
		case'B':
		PORTB=portvalue;
		break;
		case'C':
		PORTC=portvalue;
		break;
		case'D':
		PORTD=portvalue;
		break;
		default:
		break;
	}
}

unsigned char DIO_read_port (unsigned char portname){
	unsigned char return_val=0;
	switch(portname){
		case'A':
		return_val=PINA;
		break;
		case'B':
		return_val=PINB;
		break;
		case'C':
		return_val=PINC;
		break;
		case'D':
		return_val=PIND;
		break;
		default:
		break;
	}
	return return_val;
}

void DIO_vconnectpullup (char portname,char pinnumber,char connect_pullup){
	switch(portname){
		case'A':
		if (connect_pullup==1){
			SET_BIT(PORTA,pinnumber);
		}
		else{
			CLR_BIT(PORTA,pinnumber);
      }
	  break;
	  case'B':
	  if (connect_pullup==1){
		  SET_BIT(PORTB,pinnumber);
	  }
	  else{
		  CLR_BIT(PORTB,pinnumber);
	  }
	  break;
	  case'C':
	  if (connect_pullup==1){
		  SET_BIT(PORTC,pinnumber);
	  }
	  else{
		  CLR_BIT(PORTC,pinnumber);
	  }
	  break;
	  case'D':
	  if (connect_pullup==1){
		  SET_BIT(PORTD,pinnumber);
	  }
	  else{
		  CLR_BIT(PORTD,pinnumber);
	  }
	  break;
	  default:
	  break;
	}
}

void write_low_nibble (unsigned char portname,unsigned char  val){
	val&=0x0f;
	switch(portname){
		case'A':
		PORTA&=0xf0;
		PORTA|=val;
		break;
		case'B':
		PORTB&=0xf0;
		PORTB|=val;
		break;
		case'C':
		PORTC&=0xf0;
		PORTC|=val;
		break;
		case'D':
		PORTD&=0xf0;
		PORTD|=val;
		break;
	}
}

void write_high_nibble(unsigned char portname,unsigned char val1)
{
	val1<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=val1;
		break;
		case 'B':
		PORTB&=0x0f;
		PORTB|=val1;
		break;
		case 'C':
		PORTC&=0x0f;
		PORTC|=val1;
		break;
		case 'D':
		PORTD&=0x0f;
		PORTD|=val1;
		break;
	}
}		  
