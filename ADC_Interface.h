/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 18 Jan	2022                   			 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H



/*ADC Select*/
#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

void ADC_Init();
uint16_t ADC_Read(uint8_t Channel);

#endif
