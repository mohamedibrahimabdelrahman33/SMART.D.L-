/*
 * Timer_Counter_Driver.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_

#include "Datatype.h"

void Timer0_Init(void);
void Timer0_Preload(u8 Value);
void Timer0_CtcCompValue(u8 Value);
u8 Get_IntFlag(void);
void Clear_IntFlag(void);



#endif /* PWM_DRIVER_H_ */
