/* ========================================
 *
 * Andriotto Luca, Assignment #2
 *
 * ========================================
*/
#include "project.h"
#include "colors.h"
#include "RGBLedDriver.h"
#include "InterruptRoutine.h"

int main(void){
    CyGlobalIntEnable;
    state=INITIALSTATE;     // INIZIALIZZAZIONE VARIABILE GLOBALE DI STATO
    RGBLed_Start();         // INIZIALIZZAZIONE PWM LED
    isr_SW_StartEx(SW_ISR); // INIZIALIZZAZIONE ISR SU SWITCH

    for(;;){
        // RIPETIZIONE PATTERN SCELTO
        RGBLed_WritePattern(pattern[state]);
        CyDelay(period);
    }
}
