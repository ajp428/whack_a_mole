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

pins_t pinStates[17] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
                break;
        }
    }
}

uint8_t readPin(pins_t read) {
    switch (read) {
        case PINA0 :
            return PORTAbits.RA0;
        case PINA1 :
            return PORTAbits.RA1;
        case PINA2 :
            return PORTAbits.RA2;
        case PINA4 :
            return PORTAbits.RA4;
        case PINA5 :
            return PORTAbits.RA5;
        case PINB4 :
            return PORTBbits.RB4;
        case PINB5 :
            return PORTBbits.RB5;
        case PINB6 :
            return PORTBbits.RB6;
        case PINB7 :
            return PORTBbits.RB7;
        case PINC0 :
            return PORTCbits.RC0;
        case PINC1 :
            return PORTCbits.RC1;
        case PINC2 :
            return PORTCbits.RC2;
        case PINC3 :
            return PORTCbits.RC3;
        case PINC4 :
            return PORTCbits.RC4;
        case PINC5 :
            return PORTCbits.RC5;
        case PINC6: 
            return PORTCbits.RC6;
        case PINC7:
            return PORTCbits.RC7;
    }
}

void writePin(pins_t write, uint8_t value) {
    switch(write) {
        case PINA0 :
            LATAbits.LATA0 = value;
            pinStates[PINA0] = value;
            break;
        case PINA1 :
            LATAbits.LATA1 = value;
            pinStates[PINA1] = value;
            break;
        case PINA2 :
            LATAbits.LATA2 = value;
            pinStates[PINA2] = value;
            break;
        case PINA4 :
            LATAbits.LATA4 = value;
            pinStates[PINA4] = value;
            break;
        case PINA5 :
            LATAbits.LATA5 = value;
            pinStates[PINA5] = value;
            break;
        case PINB4 :
            LATBbits.LATB4 = value;
            pinStates[PINB4] = value;
            break;
        case PINB5 :
            LATBbits.LATB5 = value;
            pinStates[PINB5] = value;
            break;
        case PINB6 :
            LATBbits.LATB6 = value;
            pinStates[PINB6] = value;
            break;
        case PINB7 :
            LATBbits.LATB7 = value;
            pinStates[PINB7] = value;
            break;
        case PINC0 :
            LATCbits.LATC0 = value;
            pinStates[PINC0] = value;
            break;
        case PINC1 :
            LATCbits.LATC1 = value;
            pinStates[PINC1] = value;
            break;
        case PINC2 :
            LATCbits.LATC2 = value;
            pinStates[PINC2] = value;
            break;
        case PINC3 :
            LATCbits.LATC3 = value;
            pinStates[PINC3] = value;
            break;
        case PINC4 :
            LATCbits.LATC4 = value;
            pinStates[PINC4] = value;
            break;
        case PINC5 :
            LATCbits.LATC5 = value;
            pinStates[PINC5] = value;
            break;
        case PINC6 :
            LATCbits.LATC6 = value;
            pinStates[PINC6] = value;
            break;
        case PINC7 :
            LATCbits.LATC7 = value;
            pinStates[PINC7] = value;
            break;
    }
}