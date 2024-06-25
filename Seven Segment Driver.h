/*
 * Seven_Segment_Driver.h
 *
 * Created: 10/27/2023 10:10:45 AM
 *  Author: DELL
 */ 


#ifndef SEVEN SEGMENT DRIVER_H_
#define SEVEN SEGMENT DRIVER_H_


void sevensegment_init (unsigned char port);
void sevensegment_write (unsigned char port,unsigned char number);

#endif /* SEVEN SEGMENT DRIVER_H_ */