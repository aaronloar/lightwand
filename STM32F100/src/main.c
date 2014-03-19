#include "universal.h"
#include "effects.h"
#include "utilities.h"

#define NUM_LED         3


//#define ENABLE_TIMERS
//#define RAINBOW

void toggle_PC8();

#ifdef RAINBOW
#define STEPS           64
#else
#define STEPS           316
#endif


#ifdef ENABLE_TIMERS
void startTIM6();
#endif

/* LED data structure = 32 bit int => green(FF), red(FF), blue(FF), 00 */

int main()
{

    // set up output pins

    GPIOA_CRL = 0x44444443;
    GPIOA_CRH = 0x44444333;
    GPIOC_CRH = 0x44444433;
    GPIOB_CRH = 0x44444433;  // Setup port B for output, 50MHz max

#ifdef ENABLE_TIMERS
    // TIMERS

    //Turn on TIM6 for 0.1 second timeout and with interrupt enabled.
    TIM6_DIER = 0x00000001;     // Timeout interrupt enabled
    TIM6_PSC = 0x00000025;      //
    TIM6_ARR = 0x0000FB5E;
    TIM6_CR1 = 0x0000000C;      // Counter stops after each run

    /*
    //Turn on TIM7 for 0.5 second timeout and with interrupt disabled.
    TIM7_DIER = 0x00000001;
    TIM7_PSC = 0x000000B7;
    TIM7_ARR = 0x0000FEC1;
    TIM7_CR1 = 0x00000005;
    */
#endif


#ifdef RAINBOW

    unsigned int rainbowTable[STEPS];
    makeRainbowTable(rainbowTable);
#endif


    uint32_t val_array[(NUM_LED * STEPS)];
    generate_values(val_array);

    uint32_t step;

    while (1){
    // Loop through value array, and output to the 2812s

        for (step = 0; step < STEPS; step++) {
                bitBanger(val_array[((NUM_LED * step) + 0)]);  // first LED
                bitBanger(val_array[((NUM_LED * step) + 1)]);  // second LED
                bitBanger(val_array[((NUM_LED * step) + 2)]);  // third LED
                pause_50us();
                toggle_PC8();

#ifdef ENABLE_TIMERS
                // set 'run' pin
                startTIM6();
                // wait for timer to time out
                while (TIM6_SR && 0x00000001) {     // wait for timer 6 to time out
                    TIM6_SR = 0x00000000;

                }
#else
                pause_500ms();
#endif
        }
    }

    return 0;
}


#ifdef ENABLE_TIMERS
void tim6_dac_irq_handler(void){
    TIM6_CLEAR_UIF_BIT;
    toggle_PC8();
}

void startTIM6(){
    TIM6_CR1 &= 0x11111110; // Clear last bit for sure
    TIM6_CR1 |= 0x00000001; // Set last bit to start timer
}


#endif


// Simple function to toggle pin
void toggle_PC8() {
    if ((GPIOC_ODR & BIT8) == 0)
        SET_PC8;
    else
        CLEAR_PC8;
}
