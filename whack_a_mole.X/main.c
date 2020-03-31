/* 
 * File:   main.c
 * Author: User
 *
 * Created on March 26, 2020, 4:30 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdint.h>
#include <pic16f18446.h>
#include <stdbool.h>
#include "pins.h"
#include "timer0.h"

#define _XTAL_FREQ 4000000
#pragma config WDTE = OFF

struct mole_t moles[5];
int divisor = RAND_MAX / 5;

void initMoles(pins_t input[], pins_t output[], uint8_t inputLength, uint8_t outputLength) {
    int i;
    for(i = 0; i < 5; i++) {
        moles[i].id = i;
        moles[i].button = input[i];
        moles[i].led = output[i];
    }
}

void main(void) {
    pins_t input[] = {PINC4, PINC3, PINC6, PINC7, PINB7};
    pins_t output[] = {PINC1, PINC2, PINB4, PINB5, PINB6};
    
    shuffle(input, 5);
    shuffle(output, 5);
    
    defineGPIODirection(input, output, 5, 5);
    
    initMoles(input, output, 5, 5);
    
    while(1) {
        if(countNumOn() == 0) {
            int moleNum = rand() / divisor;
            mole_t moleOn= moles[moleNum];
            
        }
    }
}