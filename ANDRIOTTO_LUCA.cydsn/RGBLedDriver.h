/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef __RGB_LED_DRIVER_H
    #define __RGB_LED_DRIVER_H
    #define DELAY 2000
    
    #include "cytypes.h" // serve per definire il tipo di dato uint8_t
    
    
    // STRUCT PER IL COLORE
    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8 cmpmoder;
        uint8 cmpmodeg;
        uint8_t periodR;
        uint8_t periodG;
    } Color;
    
    
    // DICHIARAZIONI FUNZIONI
    void RGBLed_Start();
    
    void RGBLed_Stop();
    
    void RGBLed_WriteColor(Color c);
    uint8_t state;
#endif
/* [] END OF FILE */
