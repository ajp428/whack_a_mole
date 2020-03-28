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

uint32_t timeTurnedOn;

void main(void) {
    pins_t input[] = {PINB7};
    pins_t output[] = {PINC7};
    
    defineGPIODirection(input, output, 1, 1);
    
    while(1) {
        if(readPin(PINB7) == 0) {
            writePin(PINC7, 1);
        } else {
            writePin(PINC7, 0);
        }
    }
}

