/*
 * INTERRUPT_Demo.cpp
 *
 * Created: 6/20/2022 6:07:31 PM
 * Author : Anukul Anand
 */ 

#define F_CPU 16000000UL

#define LED PINB5
#define BUTTON PB4
#define BUTTON_PIN PINB

#define DEBOUNCE_TIME 1000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>

/*  
 * Interrupt Service Routine 
 * for Toggling LED
 */
 ISR (INT0_vect){
  _delay_us(DEBOUNCE_TIME);
  PORTB = PORTB ^ (1 << LED); 
 }


/* 
 * define Pin Change Interrupt INT0,
 * the falling edge of INT0 generates 
 * an interrupt request
 */
void init_interrupt0(void){
  EIMSK = _BV(INT0);
  EICRA = _BV(ISC01);
  sei();
}

int main(void){ 
  DDRB = _BV(LED); /* LED Pin active */
  PORTB = _BV(BUTTON); /* Button pullup */
  init_interrupt0();
    while (1)
    {
      /* do nothing */
    }
}

