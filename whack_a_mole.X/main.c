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

void main(void) {
    pins_t input[] = {PINB7};
    pins_t output[] = {PINC7};
    bool led = false;
    
    defineGPIODirection(input, output, 1, 1);
    
    while(1) {
        if(PORTBbits.RB7 == 0) {
            led = true;
        } else {
            led = false;
        }
        if(led) {
            LATCbits.LATC7 = 1;
        } else {
            LATCbits.LATC7 = 0;
        }
    }
}

