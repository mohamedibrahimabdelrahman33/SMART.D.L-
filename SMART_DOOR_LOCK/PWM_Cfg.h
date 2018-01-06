/*
 * Timer_Counter_Cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef PWM_CFG_H_
#define PWM_CFG_H_


// PWM_MODE
#define PWM																	0b01000000
#define FAST_PWM 													0b01001000


//OC0_Func in fast pwm
#define DIS_CON														0b00000000
#define NONINVERTING										0b00100000
#define INVERTING													0b00110000


//PRESCALER
#define OFF																	0b00000000
#define NO_PRESC													0b00000001
#define CLK_8																0b00000010
#define CLK_64															0b00000011
#define CLK_256															0b00000100
#define CLK_1024														0b00000101
#define EXT_CLK_FALLING_EDGE				0b00000110
#define EXT_CLK_RISING_EDGE						0b00000111


// TCCR0 Register
#define TIMER0_MODE											FAST_PWM
#define OC0_FUNC													NONINVERTING
#define PRESCALER													CLK_1024




#endif /* PWM_CFG_H_ */
