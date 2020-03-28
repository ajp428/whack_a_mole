/* 
 * File:   timer0.h
 * Author: User
 *
 * Created on March 28, 2020, 12:05 AM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#define _XTAL_FREQ 4000000

uint32_t count;

void timer0_config();

uint32_t getCount();

#endif	/* TIMER0_H */

