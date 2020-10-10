/* ========================================
 *
 * Andriotto Luca, Assignment #2
 *
 * ========================================
*/
#ifndef __RGB_LED_DRIVER_H
    #define __RGB_LED_DRIVER_H
    #define INITIALSTATE          0  // STATO DI PARTENZA
    #define PWMPERIOD           255  // NUMERO DI BIT DEL PWM
    #define PWMCLK              127  // CLOCK DEI PWM
    
    #include "cytypes.h"
    
    
    // STRUCT PER IL COLORE
    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8 cmpmoder;     // TIPO DI ONDA QUADRA (RISING/FALLING EDGE) PER RED CHANNEL
        uint8 cmpmodeg;     // TIPO DI ONDA QUADRA PER GREEN CHANNEL
        uint8_t periodR;    // PERIODO ONDA QUADRA PER RED CHANNEL
        uint8_t periodG;    // PERIODO ONDA QUADRA PER GREEN CHANNEL
    } Pattern;
    
    
    // DICHIARAZIONI FUNZIONI
    void RGBLed_Start();
    
    void RGBLed_Stop();
    
    void RGBLed_WritePattern(Pattern c);
    uint8_t state,isPeriodChanged;
    uint16_t period;
#endif
