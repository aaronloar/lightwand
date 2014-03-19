/*
 * effects.c
 *
 *  Created on: Mar 5, 2014
 *      Author: Aaron Loar
 */


#include "effects.h"

/*
 * BLINK FUNCTIONS
 */

#ifdef blink_enable
// blink all LEDs - 1 second on, one second off
unsigned int blink_1s (unsigned int ouputPort, unsigned int outputPin){

    unsigned int value = 0;
    value += 1;
    outputPin = 0x0000FFFF;
    return value;
}
#endif

// This function populates the values into the array of values
void generate_values(uint32_t val_array[(NUM_LED * STEPS)]){

    /*
    Colors in       RGB         GRB
    Red             FF0000      00FF00
    Orange          FF8000      80FF00
    Yellow          FFFF00      FFFF00
    Yellow Green    80FF00      FF8000
    Green           00FF00      FF0000
                    00FF80      FF0080
    Teal            00FFFF      FF00FF
                    0080FF      8000FF
    Blue            0000FF      0000FF
                    8000FF      0080FF
    Purple          FF00FF      00FFFF
                    FF0080      00FF80
    */


    uint32_t colors[12] = {0x00FF0000,
                           0x80FF0000,
                           0xFFFF0000,
                           0xFF800000,
                           0xFF000000,
                           0xFF008000,
                           0xFF00FF00,
                           0x8000FF00,
                           0x0000FF00,
                           0x0080FF00,
                           0x00FFFF00,
                           0x00FF8000
                           };

    int i = 0;
    int j = 0;

    // cycle through colors 6 times
    for (; i < 72; i++) {
        val_array[((i * NUM_LED) + 0)] = colors[((i+0)%12)];
        val_array[((i * NUM_LED) + 1)] = colors[((i+1)%12)];
        val_array[((i * NUM_LED) + 2)] = colors[((i+2)%12)];
    }

    // fade in RGB,  24 steps
    for (; i < 96; i++){
        val_array[((i * NUM_LED) + 0)] = ((j*10)*0x00010000);
        val_array[((i * NUM_LED) + 1)] = ((j*10)*0x01000000);
        val_array[((i * NUM_LED) + 2)] = ((j*10)*0x00000100);
        j++;
    }

    // RGB, 8 steps
    for (; i < 104; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00FF0000;
        val_array[((i * NUM_LED) + 1)] = 0xFF000000;
        val_array[((i * NUM_LED) + 2)] = 0x0000FF00;
    }
    // GBR, 8 steps
    for (; i < 112; i++){
        val_array[((i * NUM_LED) + 0)] = 0xFF000000;
        val_array[((i * NUM_LED) + 1)] = 0x0000FF00;
        val_array[((i * NUM_LED) + 2)] = 0x00FF0000;
    }
    // BRG, 8 steps
    for (; i < 120; i++){
        val_array[((i * NUM_LED) + 0)] = 0x0000FF00;
        val_array[((i * NUM_LED) + 1)] = 0x00FF0000;
        val_array[((i * NUM_LED) + 2)] = 0xFF000000;
    }
    // MYC, 8 steps
    for (; i < 128; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00FFFF00;
        val_array[((i * NUM_LED) + 1)] = 0xFFFF0000;
        val_array[((i * NUM_LED) + 2)] = 0xFF00FF00;
    }
    // YCM, 8 steps
    for (; i < 136; i++){
        val_array[((i * NUM_LED) + 0)] = 0xFFFF0000;
        val_array[((i * NUM_LED) + 1)] = 0xFF00FF00;
        val_array[((i * NUM_LED) + 2)] = 0x00FFFF00;
    }
    // CMY, 8 steps
    for (; i < 144; i++){
        val_array[((i * NUM_LED) + 0)] = 0xFF00FF00;
        val_array[((i * NUM_LED) + 1)] = 0x00FFFF00;
        val_array[((i * NUM_LED) + 2)] = 0xFFFF0000;
    }
    // RGB, 8 steps
    for (; i < 152; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00FF0000;
        val_array[((i * NUM_LED) + 1)] = 0xFF000000;
        val_array[((i * NUM_LED) + 2)] = 0x0000FF00;
    }
    // fade out RGB, 24 steps
    j = 0;
    for (; i < 176; i++){
        val_array[((i * NUM_LED) + 0)] = ((255 - (j*10))*0x00010000);
        val_array[((i * NUM_LED) + 1)] = ((255 - (j*10))*0x01000000);
        val_array[((i * NUM_LED) + 2)] = ((255 - (j*10))*0x00000100);
        j++;
    }

    // fade in white, 40 steps
    j = 0;
    for (; i < 216; i++){
        val_array[((i * NUM_LED) + 0)] = ((255/40*j)*0x01010100);
        val_array[((i * NUM_LED) + 1)] = ((255/40*j)*0x01010100);
        val_array[((i * NUM_LED) + 2)] = ((255/40*j)*0x01010100);
        j++;
    }
    // fade out white, 40 steps
    j = 0;
    for (; i < 256; i++){
        val_array[((i * NUM_LED) + 0)] = ((255 - (255/40*j))*0x01010100);
        val_array[((i * NUM_LED) + 1)] = ((255 - (255/40*j))*0x01010100);
        val_array[((i * NUM_LED) + 2)] = ((255 - (255/40*j))*0x01010100);
        j++;
    }

    /*
     * Alternate blink red, green, blue, on 3 leds
     */
    for (; i < 266; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00FF0000;
        val_array[((i * NUM_LED) + 1)] = 0x00000000;
        val_array[((i * NUM_LED) + 2)] = 0x00000000;
    }
    for (; i < 276; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00000000;
        val_array[((i * NUM_LED) + 1)] = 0xFF000000;
        val_array[((i * NUM_LED) + 2)] = 0x00000000;
    }
    for (; i < 286; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00000000;
        val_array[((i * NUM_LED) + 1)] = 0x00000000;
        val_array[((i * NUM_LED) + 2)] = 0x0000FF00;
    }
    for (; i < 296; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00FF0000;
        val_array[((i * NUM_LED) + 1)] = 0x00000000;
        val_array[((i * NUM_LED) + 2)] = 0x00000000;
    }
    for (; i < 306; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00000000;
        val_array[((i * NUM_LED) + 1)] = 0xFF000000;
        val_array[((i * NUM_LED) + 2)] = 0x00000000;
    }
    for (; i < 316; i++){
        val_array[((i * NUM_LED) + 0)] = 0x00000000;
        val_array[((i * NUM_LED) + 1)] = 0x00000000;
        val_array[((i * NUM_LED) + 2)] = 0x0000FF00;
    }



}
