/*
 * Timer_Counter_Register.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_


//Timer_0 8_Bit
#define TCCR0 *((volatile u8*)  0x53)
#define TCNT0  *((volatile u8*)  0x52)
#define OCR0  *((volatile u8*)  0x5c)


//Timer_1 16_Bit
#define TCCR1A *((volatile u8*)  0x4f)
#define TCCR1B *((volatile u8*)  0x4e)
#define TCNT1H *((volatile u8*)  0x4d)
#define TCNT1L *((volatile u8*)  0x4c)
#define TCNT1LH *((volatile u16*)  0x4c)
#define OCR1AH *((volatile u8*)  0x4b)
#define OCR1AL *((volatile u8*)  0x4a)
#define OCR1ALH *((volatile u16*)  0x4a)
#define OCR1BH *((volatile u8*)  0x49)
#define OCR1BL *((volatile u8*)  0x48)
#define OCR1BLH *((volatile u16*)  0x48)



#define TIMSK *((volatile u8*)  0x59)
#define TIFR *((volatile u8*)  0x53)

#endif /* PWM_REGISTER_H_ */
