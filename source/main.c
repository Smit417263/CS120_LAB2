/*	Author: spate130
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0x00;
	DDRC = 0x00; PORTC = 0x00;
	DDRD = 0xFF; PORTD = 0x00;

	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00; 
	unsigned char weightTotal = 0x00;

    while (1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		weightTotal = tmpA + tmpB + tmpC;
   
		if(tmpA+tmpB+tmpC >= 140){	// if it is greater than or equal to 140 then it should change the first bit
			tmpD = tmpD | 0x01;
		}

		if(abs(tmpA-tmpC) > 80){       // if it is greater than 80 than it should change the second bit
			tmpD = tmpD | 0x02;
		}


		weightTotal = weightTotal & 0xFC;	// make sure you don't include the first two bits

		tmpD = weightTotal + tmpD;
		PORTD = tmpD;

    }
    return 1;
}
