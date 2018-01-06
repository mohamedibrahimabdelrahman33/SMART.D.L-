/*
 * Timer_Counter_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#undef F_CPU
#define F_CPU 16000000ul
#include "Datatype.h"
#include  "Macros.h"
#include  "PWM_Register.h"
#include  "PWM_Cfg.h"
#include  "avr/interrupt.h"



void Pwm_Init(void)
{
	TCCR0 = ( ( TIMER0_MODE )  |  ( OC0_FUNC )  |  ( PRESCALER ) );
}


void Pwm_CtcCompValue(u8 Value)
{
	OCR0 = Value;
}




