/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 18 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_Init()
{
	ADC_ADMUX	= VOLT_REF ;
	CLR_BIT(ADC_ADMUX,5);
	SET_BIT(ADC_ADCSRA,ADC_PRESCALER);
	ADC_ADCSRA	|= ADC_Enable ;	// Enable + Prescal

}


uint16_t ADC_Read(uint8_t Channel)
{
	uint8_t ADC_Low,ADC_Hight;
	uint16_t ADC_Value;
	ADC_ADMUX = ADC_ADMUX | (Channel & 0x0f);	/* Set input channel to read */
	ADC_ADCSRA |= (1<<ADSC);					/* Start conversion */

	while((GET_BIT(ADC_ADCSRA,ADIF))==0);
	SET_BIT(ADC_ADCSRA,ADIF);
	ADC_Low = ADC_ADCL;
	ADC_Hight = ADC_ADCH;
	//ADC_Value = (uint32_t)ADC_ADCH*256;
	ADC_Value = (uint16_t)ADC_Low + (((uint16_t)ADC_Hight)*256);

	return ADC_Value;

}
