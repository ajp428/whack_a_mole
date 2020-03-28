/* 
 * File:   pins.h
 * Author: User
 *
 * Created on March 27, 2020, 7:19 PM
 */

#ifndef PINS_H
#define	PINS_H

typedef enum{
    PINA0,
    PINA1,
    PINA2,
    PINA4,
    PINA5,
    PINB4,
    PINB5,
    PINB6,
    PINB7,
    PINC0,
    PINC1,
    PINC2,
    PINC3,
    PINC4,
    PINC5,
    PINC6,
    PINC7
} pins_t;

void defineGPIODirection(pins_t input[], pins_t output[], uint8_t inputLength, uint8_t outputLength);

uint8_t readPin(pins_t read);

void writePin(pins_t write, uint8_t value);

#endif