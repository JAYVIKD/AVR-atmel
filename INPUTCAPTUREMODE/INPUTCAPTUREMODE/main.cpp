/*
 * INPUTCAPTUREMODE.cpp
 *
 * Created: 06-01-2019 01:12:17
 * Author : JAYVIK  DESAI
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <LCD_4BIT.h>
#include <avr/delay.h>

int i=0;

int main(void)
{	clc();
	config_lcd();
	lcd("jayvik");
	_delay_ms(100);
    sei();
	DDRD=0x00;
   TCCR1A=0x00;
   TCCR1B=0xc5;
   TIMSK=0x20;
       
   while (1) 
    {clc();
	 lcd(i);
	 lcd(" ",2);
	 lcd(ICR1L);
	 _delay_ms(10);
    }
}

ISR(TIMER1_CAPT_vect){
	i++;
}