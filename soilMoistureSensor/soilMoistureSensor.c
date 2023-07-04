#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ADC_Init1()
{
	DDRA &= ~(1<<PA1);		/* Make ADC port as input */
	ADCSRA = 0x87;	/* Enable ADC, fr/128  */
}

int ADC_Read1()
{
	ADMUX = 0x41;					/* Vref: Avcc, ADC channel: 0 */
	ADCSRA |= (1<<ADSC);			/* start conversion */
	while ((ADCSRA &(1<<ADIF))==0);	/*monitor end of conversion interrupt flag */
	ADCSRA |=(1<<ADIF);				/* set the ADIF bit of ADCSRA register */
	return(ADCW);					/* return the ADCW */
}