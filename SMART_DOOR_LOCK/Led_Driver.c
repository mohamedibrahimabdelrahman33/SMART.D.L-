/*
 * Led_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#include "Datatype.h"
#include  "Macros.h"
#include  "DIO_Registers.h"
#include  "DIO_Driver.h"
#include  "Led_Cfg.h"


u8 static State = 0;

void Led_Init(u8 LedNumber)
{
	DIO_SetPinDirection(LED_PORT,LedNumber,OUTPUT);
}


void Led_On(u8 LedNumber)
{
	DIO_SetPinValue(LED_PORT,LedNumber,HiGH);
	State = ON;
}

void Led_Off(u8 LedNumber)
{
	DIO_SetPinValue(LED_PORT,LedNumber,LOW);
	State = OFF;
}

void Led_Toggle(u8 LedNumber)
{
	if (State == ON)
	{
		DIO_SetPinValue(LED_PORT,LedNumber,LOW);
		State = OFF;
	}

	else if (State == OFF)
	{
		DIO_SetPinValue(LED_PORT,LedNumber,HiGH);
		State = ON;
	}

}

void Leds_On(u8 Value)
{
	DIO_SetPortValue(LED_PORT,Value);
}
