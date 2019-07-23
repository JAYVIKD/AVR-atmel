/*
 * SPI.cpp
 *
 * Created: 06-01-2019 08:42:24
 * Author : JAYVIK  DESAI
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <LCD_4BIT.h>
volatile char data;
char spi(char send);
int main(void)
{	config_lcd();
	clc();
	lcd("sp master");
	_delay_ms(200);
    //sei();
	DDRB|=(1<<4);
	DDRB|=(1<<5);
	DDRB|=(1<<7);
	
	//PORTB&=~(1<<4);
	SPCR=0X50;
	/*PORTB|=(1<<4);
	_delay_ms(1);
	SPDR='a';
	PORTB&=~(1<<4);
	*/
		
    while (1) 
    {data=spi('8');
	//clc();
	 
	 //lcd();
	 
	 _delay_ms(200);
    }
}
char spi(char send){
	char dataa;
	PORTB&=~(1<<4);
	SPDR=send;
	lcd(send);
	while(!(SPSR & (1<<SPIF)));
	PORTB|=(1<<4);
	dataa = SPDR;
	return dataa;	
}
/*ISR(SPI_STC_vect){
	
	
	//PORTB|=(1<<4);
	data= SPDR;
	//PORTB&=~(1<<4);
	SPDR='a';
	PORTB&=~(1<<4);
	
}*/