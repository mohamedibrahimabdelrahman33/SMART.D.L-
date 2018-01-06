/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: MOHAMED
 */
#undef  F_CPU
#define  F_CPU 16000000ul
#include  "Datatype.h"
#include  "Macros.h"
#include  "Led_Driver.h"
#include  "keypad.h"
#include "LCD.h"
#include "util/delay.h"



int main(void)
{
	u16 static tempButton= 0;
	u8 i,passCnt,passLenghtCnt;
	u8 static passCode[8] = {3,3,9,0};
	u8 static tempPassCode[8] = {0};


	Keypad_Init();
	LCD_Init();
	Led_Init(1);

	while(1)
	{
		tempButton = 0;
		tempButton = Keypad_WaitforKey();


		if(tempButton == BUTTON_UNLOCK)
		{
			tempButton = 0; //reset
			LCD_WriteCommand(START_AT_1ST_LINE);
			LCD_WriteString("WELCOME SIR..");
			LCD_WriteCommand(STAR_AT_2ND_LINE);
			LCD_WriteString("Enter Pass Code.");


			tempButton = Keypad_WaitforKey();
			LCD_WriteCommand(CLEAR_DISPLAY);


			while(tempButton != BUTTON_UNLOCK)
			{
				tempButton = 0; //reset
				tempButton = Keypad_WaitforKey();

				if(tempButton == BUTTON_UNLOCK)
					break;

				LCD_WriteCommand(START_AT_1ST_LINE);
				LCD_WriteDigits(1, tempButton);

				tempPassCode[passLenghtCnt] = tempButton;
				LCD_WriteCommand(STAR_AT_2ND_LINE);
				LCD_WriteDigits(1, tempPassCode[passLenghtCnt]);

				passLenghtCnt++;

			}

			for(i=0;i<passLenghtCnt;i++)
			{
				if(tempPassCode[i] == passCode[i])
					passCnt++;

			}

			if(i == passCnt)
			{
				LCD_WriteCommand(CLEAR_DISPLAY);
				LCD_WriteString("passed");
			}


		}
	}



	return 0;
}

