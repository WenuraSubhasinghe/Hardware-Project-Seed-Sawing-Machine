#ifndef USART_RS232_H_FILE_H_								// Define library H file if not defined 
#define USART_RS232_H_FILE_H_

#define BAUD_PRESCALE (((F_CPU/ (BAUDRATE * 16UL))) - 1)	// Define prescale value 

void USART_Init(unsigned long);								// USART initialize function 
char USART_RxChar();										// Data receiving function 
void USART_TxChar(char);									// Data transmitting function 
void USART_SendString(char*);								// Send string of USART data function

//void clear();

#endif														// USART_RS232_H_FILE_H_ 