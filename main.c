/**
  @Summary
 This simple code is demonstrating the X2Cscope functionalities.

  @Description
 The code is generating a sawtooth signal and a sinus signal. The code is
 toggling the LED1 with the frequency of the sawtooth signal. 
 X2Cscope can read the status of the SW1 button and can control the LED2.
 The demo is using custom hardware abstraction layer to show an example
 how to integrate X2Cscope without MCC or Harmony configurator tool.
 
 Microchip LVMC development board is used for this demo. 
*/

/**
  Section: Included Files
*/
#include "hal.h"
#include "app.h"
#include "X2CScope/X2CScope.h"
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    initHardware();
    myAppInit();
    X2CScope_Init();
    __builtin_enable_interrupts();
    
    while (1)
    {
       
        myAppTask(); //Low priority task in the idle loop
        X2CScope_Communicate(); //Handle the communication woith X2Cscope GUI
    }
    return 1; 
}


/**
 End of File
*/

