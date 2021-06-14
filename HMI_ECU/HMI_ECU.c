/*
 * HMI_ECU.C
 *
 *  Created on: Jun 13, 2021
 *      Author: hesham
 */

#include"HMI_ECU.h"
char buff[16];
uint8 key=0;
uint8 str[100]="";
uint8 enter=1;
uint8 strrr[16]="hesham";
void intgerToString(int data);
UART_configurationType UART_config ;
int main()
{
	UART_config.buadRate=9600;
	UART_config.character_size=8;
	strcpy(UART_config.mode,"double speed");

LCD_init();
UART_init(&UART_config);
EEPROM_init();
//UART_sendByte('q');
//UART_sendString("hesham");

EE
while(1)
{


	key =KeyPad_getPressedKey();

	while(enter==1)
	{
	key =KeyPad_getPressedKey();
	_delay_ms(400);
	if(key==13)
		break;
	intgerToString(key);
	strcat(str,buff);
	}
	LCD_displayString(str);
	UART_sendString(str);
}
}
void intgerToString(int data)
{
	/* buffer to hold acii result */
	itoa(data,buff,10); /* 10 for decimal base */
}
