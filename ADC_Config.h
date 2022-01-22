/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 18 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


#define ADC_PIN	0
/*
 * PORTA
 * PORTB
 * PORTC
 * PORTD
 */
#define ADC_PORT PORTA
/*
 * ADC_PRESCALER_2
 * ADC_PRESCALER_4
 * ADC_PRESCALER_8
 * ADC_PRESCALER_16
 * ADC_PRESCALER_32
 * ADC_PRESCALER_64
 * ADC_PRESCALER_128
 */
#define ADC_PRESCALER	ADC_PRESCALER_128

/*EXTERNAL_VOLT_AREF
 * AVCC_VOLT
 * Internal_2_56V
 */
#define VOLT_REF	 AVCC_VOLT


#endif
