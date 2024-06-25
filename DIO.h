/*
 * DIO.h
 *
 * Created: 10/14/2023 3:10:11 PM
 *  Author: DELL
 */ 


#ifndef DIO_H_
#define DIO_H_
void DIO_vsetPINDir (unsigned char port,unsigned char pinnumber,unsigned char direction);
void DIO_write (unsigned char portname,unsigned char pinnumber,unsigned char outputvalue);
unsigned char DIO_u8read (unsigned char portname,unsigned char pinnumber);
void DIO_toggle (unsigned char portname,unsigned char pinnumber);
void DIO_set_port_direction (unsigned char portname,unsigned char direction);
void DIO_write_port (unsigned char portname,unsigned char portvalue);
unsigned char DIO_read_port (unsigned char portname);
void DIO_vconnectpullup (char portname,char pinnumber,char connect_pullup);
void write_low_nibble (unsigned char portname,unsigned char val);
void write_high_nibble (unsigned char portname,unsigned char val1);

#endif