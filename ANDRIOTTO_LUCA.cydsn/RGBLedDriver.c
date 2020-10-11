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
static void RGBLed_PeriodInit(Pattern c);
static void RGBLed_DelayChange(Pattern c);
static void RGBLed_SetCompareMode(Pattern c);

void RGBLed_Start(){
    PWM_RED_Start();
    PWM_GREEN_Start();
}

void RGBLed_Stop(){
    PWM_RED_Stop();
    PWM_GREEN_Stop();
}

void RGBLed_WritePattern(Pattern c){
    // INIZIALIZZAZIONE DEL PERIODO DEI PWM
    RGBLed_PeriodInit(c);
    // IMPOSTAZIONE DEL DELAY
    RGBLed_DelayChange(c);
    // IMPOSTAZIONE DEL DUTY CYCLE
    RGBLed_WriteRed(c.red);
    RGBLed_WriteGreen(c.green);
    // IMPOSTAZIONE DELLA TIPOLOGIA DI ONDA QUADRA (DISCENDENTE O ASCENDENTE)
    RGBLed_SetCompareMode(c);
}

void RGBLed_WriteRed(uint8_t red){
    PWM_RED_WriteCompare(red);
}

void RGBLed_WriteGreen(uint8_t green){
    PWM_GREEN_WriteCompare(green);
}

void RGBLed_DelayChange(Pattern c){
    // CAMBIA DINAMICAMENTE IL DELAY IN BASE ALLO STATO.
    if(state&&!isPeriodChanged) period=50;         // SE SPENTO -> DELAY RIDOTTO
    else period=((float)c.periodR/PWMCLK)*1000;    // FORMULA PER CALCOLARE IL DELAY
    isPeriodChanged=1;
}

void RGBLed_PeriodInit(Pattern c){
    // INIZIALIZZAZIONE VALORE INIZIALE DEL CONTEGGIO
    PWM_GREEN_WriteCounter(INITIALSTATE);
    PWM_RED_WriteCounter(INITIALSTATE);
    // IMPOSTAZIONE DEL PERIODO DELL'ONDA QUADRA
    PWM_RED_WritePeriod(c.periodR);
    PWM_GREEN_WritePeriod(c.periodG);
}

static void RGBLed_SetCompareMode(Pattern c){
    // INIZIALIZZAZIONE TIPO DI ONDA QUADRA
    PWM_RED_SetCompareMode(c.cmpmoder);
    PWM_GREEN_SetCompareMode(c.cmpmodeg);
}