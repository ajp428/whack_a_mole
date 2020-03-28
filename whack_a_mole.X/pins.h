/* 
 * File:   pins.h
 * Author: User
 *
 * Created on March 27, 2020, 7:19 PM
 */

#ifndef PINS_H
#define	PINS_H

typedef enum{
    PINA0 = 0,
    PINA1 = 1,
    PINA2 = 2,
    PINA4 = 3,
    PINA5 = 4,
    PINB4 = 5,
    PINB5 = 6,
    PINB6 = 7,
    PINB7 = 8,
    PINC0 = 9,
    PINC1 = 10,
    PINC2 = 11,
    PINC3 = 12,
    PINC4 = 13,
    PINC5 = 14,
    PINC6 = 15,
    PINC7 = 16
} pins_t;

pins_t pinStates[17];

void defineGPIODirection(pins_t input[], pins_t output[], uint8_t inputLength, uint8_t outputLength);

uint8_t readPin(pins_t read);

void writePin(pins_t write, uint8_t value);

#endif