/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 18 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


/*ADCSRA*/
#define ADEN	7	// ADC Enable
#define ADSC	6	// ADC Start Conversion
#define ADATE	5	// ADC Auto Trigger Enable
#define ADIF	4	// ADC Interrupt Flag
#define ADIE	3	// ADC Interrupt Enable
#define	ADPS2	2	// ADC Prescaler Select Bits	2:0
#define	ADPS1	1	// ADC Prescaler Select Bits	2:0
#define	ADPS0	0	// ADC Prescaler Select Bits	2:0




/*Adjust*/
#define ADC_Left_Adjust		0x20	//ADC Left Adjust Result
#define ADC_Right_Adjust	0		//ADC Right Adjust Result

/*ADC Prescale mapping*/
#define ADC_PRESCALER_2  	1
#define ADC_PRESCALER_4  	2
#define ADC_PRESCALER_8  	3
#define ADC_PRESCALER_16 	4
#define ADC_PRESCALER_32 	5
#define ADC_PRESCALER_64 	6
#define ADC_PRESCALER_128	7


#define ADC_Enable			0x80
/*ADC Voltage Reference*/
#define EXTERNAL_VOLT_AREF  0
#define AVCC_VOLT  			0x40
#define Internal_2_56V		0xC0

#define ADC_ADCSRA	(*(volatile uint8_t*)(0x26))
#define ADC_SFIOR	(*(volatile uint8_t*)(0x50))
#define ADC_ADMUX	(*(volatile uint8_t*)(0x27))//Voltage Reference Selections
#define ADC_ADCL	(*(volatile uint16_t*)(0x24))
#define ADC_ADCH	(*(volatile uint8_t*)(0x25))
#define DDRA		(*(volatile uint8_t*)(0x3A))

#endif
