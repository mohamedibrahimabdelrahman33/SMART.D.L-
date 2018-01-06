/*
 * keypad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Datatype.h"
#include "keypad_cfg.h"


//----------KEYPAD BUTTONS----------

#define	BUTTON_UNLOCK	0xaa
#define	BUTTON_LOCK		0xbb
#define	NOT_PRESSED		0xff
#define	MODE						0xcc
#define	FLOAT_STATE			0xdd



void Keypad_Init(void);
u8 Keypad_ReadButton(u8 button_number);
union keypad  Keypad_ScanAll(void);
u16 Keypad_ScanButton(void);
u16 Keypad_WaitforKey(void);



#endif /* KEYPAD_H_ */
