/*
 * ledblink.c
 *
 * Created: 21-07-2018 18:03:28
 * Author : JAYVIK  DESAI
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{	DDRB = 0xFF;
	while(1){
	PORTB= 0xFF;
	_delay_ms(1000);
	PORTB = 0x00; 
    }
    
    
}

