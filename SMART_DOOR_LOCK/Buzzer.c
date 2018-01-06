/*
 * Buzzer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */
#include "DIO_Driver.h"
#include "Datatype.h"
#include "Macros.h"
#include "util/delay.h"
#include "Buzzer_cfg.h"



void Buzzer_Init(void)
{
	DIO_SetPinDirection(BUZZER_PORT, BUZZER_PIN, OUTPUT);
}




void Buzzer_Active(u16 Time)
{
	DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, HIGH);
	_delay_us(Time);
	DIO_SetPinValue(BUZZER_PORT, BUZZER_PIN, LOW);
	_delay_us(Time);

}
