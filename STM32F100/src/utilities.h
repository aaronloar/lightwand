/*
 * utilities.h
 *
 *  Created on: Mar 10, 2014
 *      Author: Aaron Loar
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "universal.h"

// The workhorse
void bitBanger(uint32_t value);

uint32_t concatenate_pixel (uint8_t red, uint8_t green, uint8_t blue);


// temp functions, to be replaced by timers
void pause_50us();
void pause_500ms();
void pause_1s();
void pause_2s();


#endif /* UTILITIES_H_ */
