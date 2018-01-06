/*
 * LCD.h
 *
 *  Created on: Mar 11, 2017
 *      Author: Mohamed Tarek
 */

#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"
#include "Datatype.h"


//----------LCD Commands----------
#define	CLEAR_DISPLAY										0x01
#define	RETURN_HOME										0x02
#define	DECREMENT_CURSOR							0x04
#define	INCREMENT_CURSOR							0x06
#define	SHIFT_DISPLAY_RIGHT							0x05
#define	SHIFT_DISPLAY_LEFT								0x07
#define	DISPLAY_OFF_CURSOR_OFF					0x08
#define	DISPLAY_OFF_CURSOR_ON					0x0A
#define	DISPLAY_ON_CURSOR_OFF					0x0C
#define	DISPLAY_ON_CURSOR_BLINKING			0x0E
#define	SHIFT_CURSOR_POS_LEFT						0x10
#define	SHIFT_CURSOR_POS_RIGHT					0x14
#define	SHIFT_ALL_DISPALY_LEFT						0x18
#define	SHIFT_ALL_DISPLAY_RIGHT					0x1C
#define	START_AT_1ST_LINE								0x80
#define	STAR_AT_2ND_LINE								0xC0

void LCD_WriteData(u8 Data);
void LCD_WriteCommand(u8 Command);
void LCD_Init(void);
void LCD_WriteString(u8 Char_Arr[LCD_RowLength]);
void LCD_WriteDigits(u8 Digit_Number, u32 Value );

#endif /* LCD_H_ */
