/*
 * Interrupt_Registers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef INTERRUPT_REGISTERS_H_
#define INTERRUPT_REGISTERS_H_

#define MCUCR *((volatile u8*)  0x55)
#define MCUCSR *((volatile u8*)  0x54)
#define GICR *((volatile u8*)  0x5B)
#define SREG *((volatile u8*)  0x5F)

#endif /* INTERRUPT_REGISTERS_H_ */
