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

time_t timeTurnedOff = 0;
time_t timeButtonReleased;
buttonState_t buttonState;
buttonState_t buttonLastState;
ledState_t ledState;
ledState_t ledLasteState;

void main(void) {
    pins_t input[] = {PINB7};
    pins_t output[] = {PINC7};
    
    defineGPIODirection(input, output, 1, 1);
    
    timer0_config();
    
    while(1) {
        if(readPin(PINB7) == false) {
            writePin(PINC7, 1);
        } else {
            writePin(PINC7, 0);
        }
    }
}

