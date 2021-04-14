/* ************************************************************************** */
/** 
  @Summary
 Implements simple blinking example for X2Cscope usage.

 */
/* ************************************************************************** */
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "hal.h"
#include "X2CScope/X2CScope.h"
#define PI (3.14)
/**
 Section: Global Variables
 */

volatile bool btnState;
volatile bool led1Control = false;
volatile bool led2State;

uint16_t sawTooth;
uint8_t speed = 1; // slope speed of the sawtooth
int16_t gain = 100; // amplitude of the generated sawtooth
    
typedef struct _MY_STRUCT_T
{ 
    float sinus;
    double rad;
}MY_STRUCT_t;

MY_STRUCT_t myStruct;

void myAppInit(void){
    
    //TMR 0; 
    TMR1 = 0x00;
    //Period = 0.001 s; Frequency = 50000000 Hz; PR 49999; 
    PR1 = 0xC34F;
    //TCKPS 1:1; PRWIP Write complete; TMWIP Write complete; TON enabled; TSIDL disabled; TCS FOSC/2; TECS T1CK; TSYNC disabled; TMWDIS disabled; TGATE disabled; 
    T1CON = 0x8000;

    IPC0bits.T1IP = 1; //    Priority: 1
    IFS0bits.T1IF = false;//Clear timer interrupt flag
    IEC0bits.T1IE = true; //Enable timer interrupt
}

/**
 * Generate sawtooth and sine wave. Then do sample point for X2Cscope.
 * 1ms timer interrupt
 */
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt (  )
{
    sawTooth += speed;          // Generate sawtooth
    if(sawTooth >= ((uint16_t)360 * (uint16_t)2) )     // up-to multiple of 360
    {   
        sawTooth = 0;
        IO_LED2_Toggle();       //Toggle LED to Signal of sawtooth overflow (hearthbeat)
    }
    // Generate sinus from the sawtooth signal
    myStruct.rad = ((double) sawTooth) * PI / 360.0;
    myStruct.sinus = gain * sin(myStruct.rad);
    
    X2CScope_Update(); // SAmple point of X2Cscope
    
    // Clear interrupt flag in the end
    IFS0bits.T1IF = false;
}


/**
 * @Summary
 * Example app task
 */
void myAppTask(void){
        //Handle LED1
        if(led1Control)
        {
            IO_LED1_SetHigh();
        }
        else
        {
            IO_LED1_SetLow();
        }
        //Read SW1 state
        btnState = IO_SW1_GetValue();
        //Read back LED2 state
        led2State = IO_LED2_GetValue();
}



/* *****************************************************************************
 End of File
 */
