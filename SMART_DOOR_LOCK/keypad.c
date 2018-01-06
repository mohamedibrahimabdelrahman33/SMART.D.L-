/*
 * keypad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed
 */

#include "DIO_Driver.h"
#include "Macros.h"
#include "Datatype.h"
#include "keypad_cfg.h"

//----------KEYPAD STATUS MASK----------
#define	BUTTON_NOT_PRESSED			0b000000000000
#define	BUTTON_1_PRESSED					0b000000000001
#define	BUTTON_2_PRESSED					0b000000000010
#define	BUTTON_3_PRESSED					0b000000000100
#define	BUTTON_4_PRESSED					0b000000001000
#define	BUTTON_5_PRESSED					0b000000010000
#define	BUTTON_6_PRESSED					0b000000100000
#define	BUTTON_7_PRESSED					0b000001000000
#define	BUTTON_8_PRESSED					0b000010000000
#define	BUTTON_9_PRESSED					0b000100000000
#define	BUTTON_UNLOCK_PRESSED		0b001000000000
#define	BUTTON_ZERO_PRESSED			0b010000000000
#define	BUTTON_LOCK_PRESSED			0b100000000000
#define	BUTTON_MODE_PRESSED		0b101000000000
#define	FLOAT_STATE								0xdd
#define	NO_ACTION								0xff


#define Output		1
#define Input  		0
#define High 			1
#define Low 			0





void Keypad_Init(void)
{
	u8 arr[7]= {R0,R1,R2,R3,C0,C1,C2};
	u8 i = 0;

	for(i=0;i<4;i++)
	{
		DIO_SetPinsDirection(arr[i], Output );
	}

	for(i=4;i<7;i++)
	{
		DIO_SetPinsDirection(arr[i], Input);
	}


	DIO_EnablePullupResistance( C0 );
	DIO_EnablePullupResistance( C1 );
	DIO_EnablePullupResistance( C2 );

}




u8 Keypad_ReadButton(u8 Button_Number)
{
	u8 Return_Input =  0 ;
	u8 Row_Number = 0;

	Button_Number -= 1;

	Row_Number = ( Button_Number  / 4) ;
	Button_Number =  ( Button_Number  % 4) ;


	switch( Row_Number )
	{
	case 0:
		DIO_SetPinsValue(R0,Low);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,High);
		break;

	case 1:
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,Low);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,High);
		break;

	case 2:
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,Low);
		DIO_SetPinsValue(R3,High);
		break;

	case 3:
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,Low);
		break;

	default :
		break;
	}



	switch( Button_Number)
	{
	case 0:
		Return_Input  =  DIO_GetPinsValue( C0 );
		break;

	case 1:
		Return_Input  = DIO_GetPinsValue( C1 );
		break;

	case 2:
		Return_Input = DIO_GetPinsValue( C2 );
		break;

	default :
		break;
	}


	return Return_Input;
}




union keypad  Keypad_ScanAll(void)
{
	union keypad Mykeypad;

	DIO_SetPinsValue(R0,High);
	DIO_SetPinsValue(R1,High);
	DIO_SetPinsValue(R2,High);
	DIO_SetPinsValue(R3,High);


	DIO_SetPinsValue(R0,Low);
	Mykeypad.Buttons.button1			= DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button2   		= DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button3   		= DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R0,High);


	DIO_SetPinsValue(R1,Low);
	Mykeypad.Buttons.button4   		= DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button5   		= DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button6   		= DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R1,High);


	DIO_SetPinsValue(R2,Low);
	Mykeypad.Buttons.button7 		 = DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button8		 = DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button9 		 = DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R2,High);


	DIO_SetPinsValue(R3,Low);
	Mykeypad.Buttons.button_unlock    = DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button_Zero   	= DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button_lock  	= DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R3,High);

	return Mykeypad;

}



u16 Keypad_ScanButton(void)
{
	u16  pressedButton = 0;
	u8 i;
	union keypad Mykeypad;
	Mykeypad.Status = 0;

	DIO_SetPinsValue(R0,High);
	DIO_SetPinsValue(R1,High);
	DIO_SetPinsValue(R2,High);
	DIO_SetPinsValue(R3,High);


	DIO_SetPinsValue(R0,Low);
	Mykeypad.Buttons.button1			= DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button2   		= DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button3   		= DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R0,High);


	DIO_SetPinsValue(R1,Low);
	Mykeypad.Buttons.button4   		= DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button5   		= DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button6   		= DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R1,High);


	DIO_SetPinsValue(R2,Low);
	Mykeypad.Buttons.button7 		 = DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button8		 = DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button9 		 = DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R2,High);


	DIO_SetPinsValue(R3,Low);
	Mykeypad.Buttons.button_unlock    = DIO_GetPinsValue( C0 );
	Mykeypad.Buttons.button_Zero 	= DIO_GetPinsValue( C1 );
	Mykeypad.Buttons.button_lock  	= DIO_GetPinsValue( C2 );
	DIO_SetPinsValue(R3,High);

	pressedButton = (~Mykeypad.Status);

	if(pressedButton > 0)
	{
		for(i=0;i<12;i++)
		{
			if( GET_BIT(pressedButton,i) == 1)
			{
				pressedButton = i+1 ;
				break;
			}

			else
				"Do Nothing";
		}
	}

	else if(pressedButton == 0)
	{
		pressedButton = 0xff;  // nothing is pressed
	}


	return pressedButton;

}




u16 Keypad_WaitforKey(void)
{
	u16  pressedButton = 0;
	u8 i;
	union keypad Mykeypad;
	Mykeypad.Status = 0xffff;

	do
	{
		Mykeypad.Status = 0xffff;
		DIO_SetPinsValue(R0,High);
		DIO_SetPinsValue(R1,High);
		DIO_SetPinsValue(R2,High);
		DIO_SetPinsValue(R3,High);


		DIO_SetPinsValue(R0,Low);
		Mykeypad.Buttons.button1			= DIO_GetPinsValue( C0 );
		Mykeypad.Buttons.button2   		= DIO_GetPinsValue( C1 );
		Mykeypad.Buttons.button3   		= DIO_GetPinsValue( C2 );
		DIO_SetPinsValue(R0,High);


		DIO_SetPinsValue(R1,Low);
		Mykeypad.Buttons.button4   		= DIO_GetPinsValue( C0 );
		Mykeypad.Buttons.button5   		= DIO_GetPinsValue( C1 );
		Mykeypad.Buttons.button6   		= DIO_GetPinsValue( C2 );
		DIO_SetPinsValue(R1,High);


		DIO_SetPinsValue(R2,Low);
		Mykeypad.Buttons.button7 		 = DIO_GetPinsValue( C0 );
		Mykeypad.Buttons.button8		 = DIO_GetPinsValue( C1 );
		Mykeypad.Buttons.button9 		 = DIO_GetPinsValue( C2 );
		DIO_SetPinsValue(R2,High);


		DIO_SetPinsValue(R3,Low);
		Mykeypad.Buttons.button_unlock    = DIO_GetPinsValue( C0 );
		Mykeypad.Buttons.button_Zero   	= DIO_GetPinsValue( C1 );
		Mykeypad.Buttons.button_lock  	= DIO_GetPinsValue( C2 );
		DIO_SetPinsValue(R3,High);

		pressedButton = 0;
		pressedButton = (~(Mykeypad.Status));

		switch(pressedButton)
		{
		case BUTTON_NOT_PRESSED:
			pressedButton = 0xff;
			break;
		case BUTTON_1_PRESSED:
			pressedButton = 1;
			break;
		case BUTTON_2_PRESSED:
			pressedButton = 2;
			break;
		case BUTTON_3_PRESSED:
			pressedButton = 3;
			break;
		case BUTTON_4_PRESSED:
			pressedButton = 4;
			break;
		case BUTTON_5_PRESSED:
			pressedButton = 5;
			break;
		case BUTTON_6_PRESSED:
			pressedButton = 6;
			break;
		case BUTTON_7_PRESSED:
			pressedButton = 7;
			break;
		case BUTTON_8_PRESSED:
			pressedButton = 8;
			break;
		case BUTTON_9_PRESSED:
			pressedButton = 9;
			break;
		case BUTTON_UNLOCK_PRESSED:
			pressedButton = 0xaa;
			break;
		case BUTTON_ZERO_PRESSED:
			pressedButton = 0;
			break;
		case BUTTON_LOCK_PRESSED:
			pressedButton = 0xbb;
			break;
		case BUTTON_MODE_PRESSED:
			pressedButton = 0xcc;
			break;
		default:
			pressedButton = 0xdd;
			break;

		}

	}while( (pressedButton == NO_ACTION) && (pressedButton > FLOAT_STATE));

	return pressedButton;

}
