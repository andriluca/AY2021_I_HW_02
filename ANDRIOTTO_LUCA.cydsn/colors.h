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

#define CMPMODE1R PWM_RED__B_PWM__GREATER_THAN_OR_EQUAL_TO
#define CMPMODE1G PWM_GREEN__B_PWM__GREATER_THAN_OR_EQUAL_TO
#define CMPMODE2R PWM_RED__B_PWM__GREATER_THAN_OR_EQUAL_TO
#define CMPMODE2G PWM_GREEN__B_PWM__GREATER_THAN_OR_EQUAL_TO
#define CMPMODE3R PWM_RED__B_PWM__LESS_THAN
#define CMPMODE3G PWM_GREEN__B_PWM__GREATER_THAN
#define CMPMODE4R PWM_RED__B_PWM__GREATER_THAN
#define CMPMODE4G PWM_GREEN__B_PWM__LESS_THAN
#define CMPMODE5R PWM_RED__B_PWM__LESS_THAN
#define CMPMODE5G PWM_GREEN__B_PWM__GREATER_THAN
#define CMPMODE6R PWM_RED__B_PWM__GREATER_THAN
#define CMPMODE6G PWM_GREEN__B_PWM__GREATER_THAN
#define CMPMODE7R PWM_RED__B_PWM__LESS_THAN
#define CMPMODE7G PWM_GREEN__B_PWM__GREATER_THAN

                    
static Color color[] =  {
//                         r   g  CMP_MOD_R  CMP_MOD_G  PERIOD_R    PERIOD_G
                        {  0,  0, CMPMODE1R, CMPMODE1G, 255,        255},
                        {  0,128, CMPMODE2R, CMPMODE2G, 255,        255},
                        {128,  0, CMPMODE3R, CMPMODE3G, 255,        255},
                        { 64, 64, CMPMODE4R, CMPMODE4G, 128,        128},
                        { 32, 32, CMPMODE5R, CMPMODE5G,  64,         64},
                        { 64,128, CMPMODE6R, CMPMODE6G, 255,        255},
                        {128, 64, CMPMODE7R, CMPMODE7G, 255,        127}    //127 per evitare le sovrapposizioni con il pwm del rosso.
                        };


/* [] END OF FILE */
