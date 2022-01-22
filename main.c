/*
 * main.c
 *
 *  Created on: Jan 18, 2022
 *      Author: Abdelrahman Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdlib.h>
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "DIO_interface.h"

int main()
{
	char String[5];
	int value;

	LCD_Init();			/* Initialization of LCD */
	ADC_Init();

	lcd_string("ADC value");	/* Write string on 1st line of LCD */

	while(1)
	{

		LCD_SendCommand(0xc4);	/* LCD16x2 cursor position */
		value = ADC_Read(0);	/* Read ADC channel 0 */
		itoa(value,String,10);	/* Integer to string conversion */
		lcd_string(String);
		lcd_string("  ");



	}

}
