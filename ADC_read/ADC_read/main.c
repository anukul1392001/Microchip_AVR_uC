/*
 * ADC_read.c
 *
 * Created: 6/28/2021 10:36:54 PM
 * Author : Anukul Anand
 */ 

#define  F_CPU 16000000UL  
#include <avr/io.h>
#include<util/delay.h>

float adc_val=0;


// function to read ADC
uint16_t adc_read(uint8_t adc_channel){
	ADMUX |= adc_channel;
	ADCSRA |= (1<<ADSC);
	
	while(ADCSRA & (1<<ADSC));
	return ADC;
}


// function to initialize ADC with prescalar = 64 & Vref = Vcc
void adc_init(void){
	
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN) | (1<<ADSC) | (1<<ADPS2) | (1<<ADPS1);
}


int main(void)
{
    adc_init();
    while (1) 
    {
		adc_val = adc_read(0);
		_delay_ms(200);
    }
}

