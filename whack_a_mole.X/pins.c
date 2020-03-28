/* 
 * File:   pins.c
 * Author: User
 *
 * Created on March 27, 2020, 7:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdint.h>
#include <pic16f18446.h>
#include <stdbool.h>
#include "pins.h"

void defineGPIODirection(pins_t input[], pins_t output[], uint8_t inputLength, uint8_t outputLength) {
    uint8_t i;
    for(i = 0; i < inputLength; i++) {
        switch(input[i]) {
            case PINA0 :
                TRISAbits.TRISA0 = 1;
                ANSELAbits.ANSA0 = 0;
                WPUAbits.WPUA0 = 1;
                break;
            case PINA1 :
                TRISAbits.TRISA1 = 1;
                ANSELAbits.ANSA1 = 0;
                WPUAbits.WPUA1 = 1;
                break;
            case PINA2 :
                TRISAbits.TRISA2 = 1;
                ANSELAbits.ANSA2 = 0;
                WPUAbits.WPUA2 = 1;
                break;
            case PINA4 :
                TRISAbits.TRISA4 = 1;
                ANSELAbits.ANSA4 = 0;
                WPUAbits.WPUA4 = 1;
                break;
            case PINA5 : 
                TRISAbits.TRISA5 = 1;
                ANSELAbits.ANSA5 = 0;
                WPUAbits.WPUA5 = 1;
                break;
            case PINB4 :
                TRISBbits.TRISB4 = 1;
                ANSELBbits.ANSB4 = 0;
                WPUBbits.WPUB4 = 1;
                break;
            case PINB5 :
                TRISBbits.TRISB5 = 1;
                ANSELBbits.ANSB5 = 0;
                WPUBbits.WPUB5 = 1;
                break;
            case PINB6 :
                TRISBbits.TRISB6 = 1;
                ANSELBbits.ANSB6 = 0;
                WPUBbits.WPUB6 = 1;
                break;
            case PINB7 :
                TRISBbits.TRISB7 = 1;
                ANSELBbits.ANSB7 = 0;
                WPUBbits.WPUB7 = 1;
                break;
            case PINC0 :
                TRISCbits.TRISC0 = 1;
                ANSELCbits.ANSC0 = 0;
                WPUCbits.WPUC0 = 1;
                break;
            case PINC1 : 
                TRISCbits.TRISC1 = 1;
                ANSELCbits.ANSC1 = 0;
                WPUCbits.WPUC1 = 1;
                break;
            case PINC2 : 
                TRISCbits.TRISC2 = 1;
                ANSELCbits.ANSC2 = 0;
                WPUCbits.WPUC2 = 1;
                break;
            case PINC3 :
                TRISCbits.TRISC3 = 1;
                ANSELCbits.ANSC3 = 0;
                WPUCbits.WPUC3 = 1;
                break;
            case PINC4 :
                TRISCbits.TRISC4 = 1;
                ANSELCbits.ANSC4 = 0;
                WPUCbits.WPUC4 = 1;
                break;
            case PINC5 :
                TRISCbits.TRISC5 = 1;
                ANSELCbits.ANSC5 = 0;
                WPUCbits.WPUC5 = 1;
                break;
            case PINC6 :
                TRISCbits.TRISC6 = 1;
                ANSELCbits.ANSC6 = 0;
                WPUCbits.WPUC6 = 1;
                break;
            case PINC7 :
                TRISCbits.TRISC7 = 1;
                ANSELCbits.ANSC7 = 0;
                WPUCbits.WPUC7 = 1;
                break;
        }
    }
    
    for(i = 0; i < outputLength; i++) {
        switch(output[i]) {
            case PINA0 :
                TRISAbits.TRISA0 = 0;
                break;
            case PINA1 :
                TRISAbits.TRISA1 = 0;
                break;
            case PINA2 :
                TRISAbits.TRISA2 = 0;
                break;
            case PINA4 :
                TRISAbits.TRISA4 = 0;
                break;
            case PINA5 :
                TRISAbits.TRISA5 = 0;
                break;
            case PINB4 :
                TRISBbits.TRISB4 = 0;
                break;
            case PINB5 :
                TRISBbits.TRISB5 = 0;
                break;
            case PINB6 : 
                TRISBbits.TRISB6 = 0;
                break;
            case PINB7 :
                TRISBbits.TRISB7 = 0;
                break;
            case PINC0 :
                TRISCbits.TRISC0 = 0;
                break;
            case PINC1 :
                TRISCbits.TRISC1 = 0;
                break;
            case PINC2 :
                TRISCbits.TRISC2 = 0;
                break;
            case PINC3 :
                TRISCbits.TRISC3 = 0;
                break;
            case PINC4 :
                TRISCbits.TRISC4 = 0;
                break;
            case PINC5 :
                TRISCbits.TRISC5 = 0;
                break;
            case PINC6 :
                TRISCbits.TRISC6 = 0;
                break;
            case PINC7 :
                TRISCbits.TRISC7 = 0;
        }
    }
}