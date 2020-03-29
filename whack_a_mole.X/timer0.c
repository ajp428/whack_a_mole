/* 
 * File:   pins.c
 * Author: User
 *
 * Created on March 28, 2020, 12:05 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <stdint.h>
#include <pic16f18446.h>
#include <stdbool.h>
#include "timer0.h"

time_t time = 0;

void timer0_config() {
    T0CON0bits.EN = 1;          // Enables Timer0
    T0CON1bits.T0CS = 0b010;    // Select the clock source as F_OSC / 4
    T0CON1bits.CKPS = 0b0101;   // Select a prescalar of 1:4
    T0CON1bits.ASYNC = 0;       // Set input to Timer0 counter as F_OSC / 4
    TMR0H = 249;                // Set the comparator so the timer counts to 250 before reset
    INTCONbits.GIE = 1;         // Enables global interrupts
    PIE0bits.TMR0IE = 1;        // Enables intterrupts on Timer0
}

void __interrupt() timer0ISR() {
    time++;
}

uint32_t getTime() {
    return time;
}

