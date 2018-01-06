/*
 * LCD.c
 *
 *  Created on: Mar 11, 2017
 *      Author: Mohamed Tarek
 */
#undef F_CPU
#define F_CPU 16000000ul
#include "LCD_Cfg.h"
#include "DIO_Driver.h"
#include "Datatype.h"
#include "util/delay.h"




void LCD_WriteData(u8 Data)
{
	DIO_SetPinsValue(RS_PIN,High);

	DIO_SetPortValue(DATA_PORT,Data);

	DIO_SetPinsValue(E_PIN,High);
	_delay_ms(1);

	DIO_SetPinsValue(E_PIN,Low);
	_delay_ms(1);
}





void LCD_WriteCommand(u8 Command)
{
	DIO_SetPinsValue(RS_PIN,Low);

	DIO_SetPortValue(DATA_PORT,Command);

	DIO_SetPinsValue(E_PIN,High);
	_delay_ms(1);

	DIO_SetPinsValue(E_PIN,Low);
	_delay_ms(1);
}





void LCD_Init(void)
{
	DIO_SetPortDirection(DATA_PORT,Output);

	DIO_SetPinsDirection(RS_PIN,Output);

	DIO_SetPinsDirection(E_PIN,Output);

	LCD_WriteCommand(0x01); // Clear display screen
	_delay_ms(50);

	LCD_WriteCommand(0x0c); //return cursor home

	LCD_WriteCommand(0x38); //8 bit data bus
}



//========================================================
void LCD_WriteString(u8 Char_Arr[LCD_RowLength] )
{
	u8 i = 0;

	//*Write Data*//
	for(i=0;i<LCD_RowLength;i++)
	{
		if(Char_Arr[i]  != '\0')
		{
			DIO_SetPinsValue(RS_PIN,High);

			DIO_SetPortValue(DATA_PORT,Char_Arr[i] );

			DIO_SetPinsValue(E_PIN,High);
			_delay_ms(1);

			DIO_SetPinsValue(E_PIN,Low);
			_delay_ms(1);
		}

		else
		{
			break;
		}
	}

}


//===================================================
void LCD_WriteDigits(u8 Digit_Number, u32 Value )
{
	u8 Digits_Arr[Digit_Number];
	u8 i = 0;

	for(i=0;i<Digit_Number;i++)
	{
		if(Value != 0 )
		{
			Digits_Arr[i] = (Value % 10);
			Value /= 10;
		}

		else
		{
			Digits_Arr[i] = 0;
		}
	}


	for(i=0;i<Digit_Number;i++)
	{
		Digits_Arr[i] += '0' ;
	}

	for(i=Digit_Number;i>0;i--)
	{

		DIO_SetPinsValue(RS_PIN,High);

		DIO_SetPortValue(DATA_PORT,Digits_Arr[i-1]  );

		DIO_SetPinsValue(E_PIN,High);
		_delay_ms(1);

		DIO_SetPinsValue(E_PIN,Low);
		_delay_ms(1);

	}
}
