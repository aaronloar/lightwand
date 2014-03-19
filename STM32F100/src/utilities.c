/*
 * utilities.c
 *
 *  Created on: Mar 10, 2014
 *      Author: Aaron Loar
 */

#include "utilities.h"

void pause_50us() {         // not 50ms, but is well over it
    int k;
    for (k = 0; k < 200; k++) {
        asm volatile ("NOP\n\t");
    }
}
void pause_500ms() {         // not 500ms, just a guess
    int k;
    for (k = 0; k < 60000; k++) {
        asm volatile ("NOP\n\t");
    }
}
void pause_1s() {           // not 1s yet, just a guess
    int k;
    for (k = 0; k < 160000; k++) {
        asm volatile ("NOP\n\t");
    }
}
void pause_2s() {           // closer to 3-4 seconds
    int k;
    for (k = 0; k < 0x00CF9A42; k++) {
        asm volatile ("NOP\n\t");
    }
}

void bitBanger(uint32_t value){

    // R0 = value
    // R1 = counter - 24 count
    // STEPS:
    //  set up ports - r1 = 24 counter, r2 = mem location, r3 = on or off in BSRR
    //  rotate value left 1 position
    //  if carry = 1, BB 1; if carry = 0, BB 0

    asm volatile (
            "MOV R1, #25\n\t"       // set counter to 24
            "LDR R2, =0x40010810\n\t"   // Address of GPIOA_BSRR
            "NEXT:\n\t"                     // Estimating 5 cycles for this set of commands
                "SUB R1, R1, #1\n\t"            // decrement counter
                "CBZ R1, END\n\t"       // if counter zero, jump to end
                "LSLS R0, R0, #1\n\t"        // logical shift value left through carry
                "BCS BB1\n\t"
            "BB0:\n\t"
                "LDR R3, =0x00000100\n\t"   // Address to toggle pin 8
                "STR R3, [R2,#0]\n\t"       // Start counting cycles, 8 cycles
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"                   // 7 cycles.  LDR in next line = 8 cycles
                "LDR R3, =0x01000000\n\t"   // load with clear value
                "STR R3, [R2, #0]\n\t"      // Clear bit down, 19 cycles
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"                   // 10 cycles
                "NOP\n\t"
                "NOP\n\t"                   // 12 cycles
                "B NEXT\n\t"                // branch back for next bit to send
            "BB1:\n\t"
                "LDR R3, =0x00000100\n\t"   // Address to toggle pin 8
                "STR R3, [R2,#0]\n\t"       // Start counting cycles, 17 cycles
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"       // 10 cycles
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"
                "NOP\n\t"                   // 16 cycles.  LDR in next line = 17 cycles
                "LDR R3, =0x01000000\n\t"   // load with low value
                "STR R3, [R2, #0]\n\t"      // Clear bit down, 14 cycles
                "B NEXT\n\t"                // return branch and logic above accounts
                                            // for neccessary time delay
            "END:\n\t"
    );

}

/* Concatenates GRB values into a single 4 byte integer. */
uint32_t concatenate_pixel (uint8_t green, uint8_t red, uint8_t blue)
{
    uint32_t value = 0;

    value += green;
    value <<= 8;
    value += red;
    value <<= 8;
    value += blue;
    value <<= 8;

    return value;
}


