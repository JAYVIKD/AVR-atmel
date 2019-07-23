/*
 * led_blink.cpp
 *
 * Created: 21-07-2018 19:16:54
 * Author : JAYVIK  DESAI
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{ char pind;
 
	DDRB =0xFF;
	DDRD&=~(1<<PIND1);
	PORTD|=1<<PIND1;
    while (1)
	{pind = PIND & 1<<1;
	if(pind==0)
		{pind = PIND & 1<<1;
	 PORTB=0x00;
	_delay_ms(500);
	PORTB=0xFF; 
	_delay_ms(500);
		}
	}
    
    
}




