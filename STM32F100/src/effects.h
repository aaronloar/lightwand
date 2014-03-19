/*
 * effects.h
 *
 *  Created on: Mar 5, 2014
 *      Author: aloar
 */

#ifndef EFFECTS_H_
#define EFFECTS_H_

// #includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "universal.h"
#include "utilities.h"

#ifdef blink_enable
extern unsigned int blink_1s(unsigned int, unsigned int);
#endif

void generate_values(uint32_t *);


#endif /* EFFECTS_H_ */
