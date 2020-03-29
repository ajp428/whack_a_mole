/* 
 * File:   pins.h
 * Author: User
 *
 * Created on March 27, 2020, 7:19 PM
 */

#ifndef PINS_H
#define	PINS_H

// Enumerated type created to represent each GPIO pin
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

// Enumerated type created to keep track of a button's state for debouncing purposes
typedef enum{
    STATE_PRESSED,
    STATE_UNPRESSED
} buttonState_t;

typedef enum{
    STATE_ON,
    STATE_OFF
} ledState_t;

// Array that keeps track of the state of the pins (high vs. low) for the purpose
// of determining how many moles might be on)
pins_t pinStates[17];

// Function that takes the pins in the input array, configures as inputs
// Also takes pins in output array, configures as outputs
void defineGPIODirection(pins_t input[], pins_t output[], uint8_t inputLength, uint8_t outputLength);

// Reads and returns a pin's value
bool readPin(pins_t read);

// Writes a value to a pin
void writePin(pins_t write, uint8_t value);

#endif