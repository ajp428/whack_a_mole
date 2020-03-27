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

void main(void) {
    TRISCbits.TRISC7 = 0;   // Configure pin C7 at LED output
    TRISBbits.TRISB7 = 1;   // Configure pin B7 as button input
    ANSELBbits.ANSB7 = 0;   // Configure pin B7 for digital input
    WPUBbits.WPUB7 = 1;     // Enable weak pull-up resistor for pin B7
    bool led = false;
    
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

