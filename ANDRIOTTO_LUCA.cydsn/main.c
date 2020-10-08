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
#define DELAY 2000

int main(void)
{
    CyGlobalIntEnable;
    
    RGBLed_Start();
    
    //RGBLed_WriteColor(ZERO);
    //CyDelay(DELAY);
    //RGBLed_Stop();
    
    for(;;)
    {
        RGBLed_WriteColor(RED);
        CyDelay(DELAY);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
