/*
 * GPIO_demo.cpp
 *
 * Created: 10/26/2021 5:47:00 PM
 * Author : Anukul Anand
 */ 

#define F_CPU 16000000UL  //Set CPU Frequency
#include <avr/io.h>
#include<util/delay.h>



int main(void)
{
    DDRB = 0xFF;         //PortB input 
    while (1) 
    {
		PORTB = 0xFF;    //PortB high
		_delay_ms(1000); //delay 1second
		PORTB = 0x00;    //PortB low  
		_delay_ms(1000); //delay 1second
    }
}

