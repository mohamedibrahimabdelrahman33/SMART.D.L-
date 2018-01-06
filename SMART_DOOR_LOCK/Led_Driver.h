/*
 * Led_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "Datatype.h"

void Led_Init(u8 LedNumber);
void Led_On(u8 LedNumber);
void Led_Off(u8 LedNumber);
void Led_Toggle(u8 LedNumber);
void Leds_On(u8 Value);

#endif /* LED_DRIVER_H_ */
