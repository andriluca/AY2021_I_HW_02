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
#include "colors.h"
#include "RGBLedDriver.h"
#include "InterruptRoutine.h"

int main(void)
{
    CyGlobalIntEnable;
    state=0;
    RGBLed_Start();
    isr_SW_StartEx(SW_ISR);
    
    for(;;){
        RGBLed_WriteColor(color[state]);
        CyDelay(DELAY);    
    }
}

/* [] END OF FILE */
