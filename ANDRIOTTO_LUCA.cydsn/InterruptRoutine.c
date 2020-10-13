/* ========================================
 *
 * Andriotto Luca, Assignment #2
 *
 * ========================================
*/
#include "InterruptRoutine.h"

CY_ISR_PROTO(SW_ISR){
    // AGGIORNO LO STATO IN MANIERA CIRCOLARE
    state=(state+1)%7;
    // RICHIESTA DI RECUPERO PERIODO MANCANTE
    isButtonPressed=1;
}