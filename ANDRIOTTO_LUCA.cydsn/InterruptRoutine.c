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
#include "RGBLedDriver.h"
#include "InterruptRoutine.h"

CY_ISR_PROTO(SW_ISR){
    // AGGIORNO LO STATO IN MANIERA CIRCOLARE
    state=(state+1)%7;
}



/* [] END OF FILE */
