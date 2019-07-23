/*
 * PWM.cpp
 *
 * Created: 05-01-2019 15:28:42
 * Author : JAYVIK  DESAI
 */ 

#include <avr/io.h>


int main(void)
{
    TCCR0=0x73;
	DDRB= 0xff;
	OCR0=0xFE;
    while (1) 
    {
    }
}

