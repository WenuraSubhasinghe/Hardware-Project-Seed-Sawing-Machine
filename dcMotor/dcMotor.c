#include <avr/io.h>											// Include AVR std. library file
#include <stdio.h>											// Include std. library file
#include <util/delay.h>										// Include Delay header file
#include "dcMotor.h"

void activeDcMotors()
{
	//TT Gear Motors
	DDRC |=(1<<DDC0) | (1<<DDC1);
	TCCR1B &= ~(1<<WGM13);									//SET MODE OF THE TIMER
	TCCR1B |= (1<<WGM12);
	TCCR1A |= (1<<WGM10)|(1<<WGM11);						//FAST PWM 10 BIT MODE
	TCCR1A |= (1<<COM1A1);									//SET PWM MODE
	TCCR1A &= ~(1<<COM1A0);									//PWM PIN IN NON-INVERTED MODE
	TCCR1B |= (1<<CS10) | (1<<CS11);						//SET PRESCALER FOR THE TIMER FOR SETTING PWM FREQUENCY  //CLOCK 16MHz = 250KHz = 64 = 16MHz/64 = 250KHz
	TCCR1B &= ~(1<<CS12);									//PRE SCALER 64
	DDRD |= (1<<DDD5);										//CONFIGURE THE OUTPUT COMPARE PIN AS O/P
	OCR1A = 1023;
	
	//Cog Wheel
	DDRC |=(1<<DDC2) | (1<<DDC3);
	TCCR1A |= (1<<COM1B1);									//SET PWM MODE
	TCCR1A &= ~(1<<COM1B0);									//PWM PIN IN NON-INVERTED MODE
	DDRD |= (1<<DDD4);										//CONFIGURE THE OUTPUT COMPARE PIN AS O/P
	OCR1B = 1023;
}

void moveForward()
{
	PORTC |=(1<<PC0);
}

void moveBackward()
{
	PORTC |= (1<<PC1);
}

void cogWheel()
{			
	PORTC |=(1<<PC2);
}

void stopDcMotors()
{
	PORTC &=(~(1<<PC0));
	PORTC &=(~(1<<PC1));
	PORTC &=(~(1<<PC2));
}

