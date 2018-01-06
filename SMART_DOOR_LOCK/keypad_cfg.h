/*
 * keypad_Cfg.h
 *
 *  created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_



#define R0 16
#define R1 17
#define R2 18
#define R3 19
#define C0 20
#define C1 21
#define C2 22




union keypad
{
	struct
	{
		u16 button1 : 1;
		u16 button2 : 1;
		u16 button3 : 1;
		u16 button4 : 1;
		u16 button5 : 1;
		u16 button6 : 1;
		u16 button7 : 1;
		u16 button8 : 1;
		u16 button9 : 1;
		u16 button_unlock : 1;
		u16 button_Zero : 1;
		u16 button_lock : 1;
	}Buttons;

	u16 Status;
};



#endif /* KEYPAD_CFG_H_ */
