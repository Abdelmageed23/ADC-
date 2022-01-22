/*************************************************
 * Author 	: Abdelrahman Mohamed
 * Version	: V1.0
 * Date 	: 16 / 1 / 2022
 *
 *************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

void LCD_Init()
{
	DIO_SetPinDircection(LCD_PORT,7,OUTPUT);  // LCD PORT OUTPUT
	DIO_SetPinDircection(LCD_PORT,1,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,2,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,3,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,4,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,5,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,6,OUTPUT);

	DELAY(50);
	LCD_SendCommand(0x28); // Initialize 2 lines  5x8 dots and 4 bit mode
	LCD_SendCommand(LCD_DISP_ON_CURSOR_BLINK); // Display On , Cursor blinking
	LCD_SendCommand(LCD_CLEAR_SCREEN);
	LCD_SendCommand(LCD_ENTRY_MODE); // Entry mode

}

void LCD_GotoXY (uint8_t line ,uint8_t postion)
{
	if(line==0)
	{
		if(postion < 16 && postion >=0)
			LCD_SendCommand(0x80+postion);
	}
	else if (line == 1)
	{
		if(postion < 16 && postion >=0)
			LCD_SendCommand(0xc0+postion);
	}
}

void LCD_SendCommand(uint8_t Command)
{
	DIO_SetPortValue(LCD_PORT,((LCD_PORT & 0x0F)|(Command & 0xF0)));

	DIO_SetPinValue(LCD_PORT,LCD_RS,LOW);
	//DIO_SetPinValue(LCD_PORT,LCD_RW,LOW);
	DIO_SetPinValue(LCD_PORT,LCD_E,HIGH);
	DELAY(1);
	DIO_SetPinValue(LCD_PORT,LCD_E,LOW);
	DELAY(1);

		DIO_SetPortValue(LCD_PORT,(LCD_PORT & 0x0F) | (Command << 4));
		DIO_SetPinValue(LCD_PORT,LCD_RS,LOW);
	//	DIO_SetPinValue(LCD_PORT,LCD_RW,LOW);
		DIO_SetPinValue(LCD_PORT,LCD_E,HIGH);
		DELAY(1);;
		DIO_SetPinValue(LCD_PORT,LCD_E,LOW);
		DELAY(1);
}

void LCD_SendChar(uint8_t Char)
{
//	LCD_Check_Busy();
	DIO_SetPortValue(LCD_PORT,((LCD_PORT & 0x0F) | (Char & 0xF0)));
	DIO_SetPinValue(LCD_PORT,LCD_RS,HIGH);
	//DIO_SetPinValue(LCD_PORT,LCD_RW,LOW);
	DIO_SetPinValue(LCD_PORT,LCD_E,HIGH);
	DELAY(1);
	DIO_SetPinValue(LCD_PORT,LCD_E,LOW);
	DELAY(1);

	DIO_SetPortValue(LCD_PORT,((LCD_PORT & 0x0F) | (Char << 4)));
	DIO_SetPinValue(LCD_PORT,LCD_RS,HIGH);
		//DIO_SetPinValue(LCD_PORT,LCD_RW,LOW);
		DIO_SetPinValue(LCD_PORT,LCD_E,HIGH);
		DELAY(1);
		DIO_SetPinValue(LCD_PORT,LCD_E,LOW);
		DELAY(1);

}

void lcd_string(char *str){
	uint8_t count=0;
	while (*str!='\0')
	{
		count++;
		LCD_SendChar(*str);
		str++;
		if (count == 16)
				{
			LCD_GotoXY(1,0);
				}
				else if (count == 32 || count ==33)
				{
					LCD_Clear_screen();
					LCD_GotoXY(0,0);
					count =0;
				}
	}
}

void LCD_Check_Busy(void)
{
	uint8_t LCD_Busy_Flag=0;

		DIO_SetPinDircection(LCD_PORT,LCD_PIN4,INPUT);
		DIO_SetPinDircection(LCD_PORT,LCD_PIN5,INPUT);
		DIO_SetPinDircection(LCD_PORT,LCD_PIN6,INPUT);
		DIO_SetPinDircection(LCD_PORT,LCD_PIN7,INPUT);

	DIO_SetPinValue(LCD_PORT,LCD_RS,LOW);
	DIO_SetPinValue(LCD_PORT,LCD_RW,HIGH);
	DIO_SetPinValue(LCD_PORT,LCD_E,HIGH);
	DELAY(1);
		DIO_SetPinValue(LCD_PORT,LCD_E,LOW);
		DELAY(1);

	DIO_SetPinDircection(LCD_PORT,LCD_PIN4,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,LCD_PIN5,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,LCD_PIN6,OUTPUT);
	DIO_SetPinDircection(LCD_PORT,LCD_PIN7,OUTPUT);

}

void Delay(uint32_t delay)
{
	volatile uint32_t i =0;
	for ( i =0 ; i < delay ; i++)
	{
		asm volatile ("NOP");
	}
}


void LCD_Clear_screen()
{
	LCD_SendCommand(0x01);
	DELAY(2);
	LCD_SendCommand(0x80);
	DELAY(2);
}


void LCD_MoveCursorLeft()
{
	LCD_SendCommand(0x10);
}


void LCD_MoveCursorRight()
{
	LCD_SendCommand(0x14);
}


void DELAY(uint32_t time)
{
	volatile uint32_t x,y;
	for(x=0;x<time ; x++)
	{
		for(x=0;x<450;x++)
		{

		}
	}
}
