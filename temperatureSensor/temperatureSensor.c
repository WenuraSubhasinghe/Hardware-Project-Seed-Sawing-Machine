#include <avr/io.h>
#include <util/delay.h>
#include "temperatureSensor.h"

void ADC_Init(){										
	DDRA &= ~(1<<PA0);							        // Make ADC port as input 
	ADCSRA = 0x87;									// Enable ADC, with freq/128  
	ADMUX = 0x40;									// Vref: Avcc, ADC channel: 0 
}

int ADC_Read(char channel)							
{
	ADMUX = 0x40 | (channel & 0x07);				// set input channel to read 
	ADCSRA |= (1<<ADSC);							// Start ADC conversion 
	while (!(ADCSRA & (1<<ADIF)));					// Wait until end of conversion by polling ADC interrupt flag 
	ADCSRA |= (1<<ADIF);							// Clear interrupt flag 
	_delay_ms(1);									// Wait a little bit 
	return ADCW;									// Return ADC word 
}


