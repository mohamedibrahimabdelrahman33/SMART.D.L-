/*
 * Regisers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */



#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_
#include "Datatype.h"

#define PORTA *((volatile u8*)  0x3B)
#define DDRA *((volatile  u8*)  0x3A)
#define PINA *((volatile const u8*)  0x39)

#define PORTB *((volatile u8*)  0x38)
#define DDRB *((volatile u8*)  0x37)
#define PINB *((volatile const u8*)  0x36)

#define PORTC *((volatile u8*)  0x35)
#define DDRC *((volatile u8*)  0x34)
#define PINC *((volatile const u8*)  0x33)

#define PORTD *((volatile u8*)  0x32)
#define DDRD *((volatile u8*)  0x31)
#define PIND *((volatile const u8*)  0x30)






#endif /* DIO_REGISTERS_H_ */
