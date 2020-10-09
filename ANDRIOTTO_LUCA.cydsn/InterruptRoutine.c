/* ========================================
 *
 * Andriotto Luca, Assignment #2
 *
 * ========================================
*/
#include "RGBLedDriver.h"
#include "InterruptRoutine.h"

CY_ISR_PROTO(SW_ISR){
    // AGGIORNO LO STATO IN MANIERA CIRCOLARE
    state=(state+1)%7;
}
