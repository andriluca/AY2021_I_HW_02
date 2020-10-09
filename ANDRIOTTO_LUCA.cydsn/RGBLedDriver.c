/* ========================================
 * 
 * Andriotto Luca, Assignment #2
 *
 * ========================================
*/
#include "project.h"
#include "RGBLedDriver.h"

static void RGBLed_WriteRed(uint8_t red);
static void RGBLed_WriteGreen(uint8_t green);


void RGBLed_Start(){
    PWM_RED_Start();
    PWM_GREEN_Start();
}

void RGBLed_Stop(){
    PWM_RED_Stop();
    PWM_GREEN_Stop();
}

void RGBLed_WriteColor(Color c){
    // IMPOSTO LA TIPOLOGIA DI ONDA QUADRA (DISCENDENTE O ASCENDENTE)
    PWM_RED_SetCompareMode(c.cmpmoder);
    PWM_GREEN_SetCompareMode(c.cmpmodeg);
    // IMPOSTO IL PERIODO DELL'ONDA QUADRA
    PWM_RED_WritePeriod(c.periodR);
    PWM_GREEN_WritePeriod(c.periodG);
    // IMPOSTO IL DUTY CYCLE
    RGBLed_WriteRed(c.red);
    RGBLed_WriteGreen(c.green);
}

void RGBLed_WriteRed(uint8_t red){
    PWM_RED_WriteCompare(red);
}

void RGBLed_WriteGreen(uint8_t green){
    PWM_GREEN_WriteCompare(green);
}
