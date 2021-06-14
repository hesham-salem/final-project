/*
 * Exercise1.c
 *
 * Created: 4/10/2014 9:23:41 PM
 * Author: Mohamed Tarek
 */ 

#include "uart.h"

int main(void)
{
	uint8 str[20];
	uint8 data;
	UART_configurationType UART_config ;
			UART_config.buadRate=9600;
		UART_config.character_size=8;
		strcpy(UART_config.mode,"double speed");
		UART_init(&UART_config);

    while(1)
    { 
	//	data = UART_recieveByte(); //Receive Byte from Terminal1
		//UART_sendByte(data); //Resend the received byte to Terminal2
		UART_receiveString(str); //Receive String from Terminal
		if(!strcmp(str,"123"))
			SET_BIT(DDRB,0);
	  //  _delay_ms(1000);
	    UART_sendString(str);

    }
}
