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
#include "project.h"
#include "RGBLedDriver.h"

static void RGBLed_WriteRed(uint8_t red);
static void RGBLed_WriteGreen(uint8_t green);

void RGBLed_Start(){
    PWM_LED_Start(); // inizializza il dispositivo pwm RG
}

void RGBLed_Stop(){
    PWM_LED_Stop(); // stoppa il dispositivo pwm RG.
}

void RGBLed_WriteColor(Color c){
    RGBLed_WriteRed(c.red);
    RGBLed_WriteGreen(c.green);
}

void RGBLed_WriteRed(uint8_t red){
    PWM_LED_WriteCompare1(red);
}

void RGBLed_WriteGreen(uint8_t green){
    PWM_LED_WriteCompare2(green);
}

/* [] END OF FILE */
