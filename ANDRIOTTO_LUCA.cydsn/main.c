/* ========================================
 *
 * Andriotto Luca, Assignment #2
 *
 * ========================================
*/
#include "InterruptRoutine.h"
#include "colors.h"

int main(void){
    CyGlobalIntEnable;
    state=INITIALSTATE;     // INIZIALIZZAZIONE VARIABILE GLOBALE DI STATO
    RGBLed_Start();         // INIZIALIZZAZIONE PWM LED
    isr_SW_StartEx(SW_ISR); // INIZIALIZZAZIONE ISR SU SWITCH

    for(;;){
        // RIPETIZIONE PATTERN SCELTO
        RGBLed_WritePattern(pattern[state]);
        CyDelay(period);
        
        // TRANSIZIONE DA UNA CONFIGURAZIONE ALL'ALTRA
        if(!isPeriodChanged){
           // SPEGNIMENTO MOMENTANEO PER AGEVOLARE LA DISTINZIONE DEGLI STATI
           RGBLed_WritePattern(SWITCHEDOFF);
           CyDelay(300);
        }
    }
}
