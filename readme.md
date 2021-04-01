# MPLAB X Project: X2Cscope_blinky_dsPIC33CK_LVMC_customHAL

This is a X2Cscope demo project for [Low Voltage Motor Control (LVMC)](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM330031) development board and [dsPIC33CK256MP508](https://www.microchip.com/wwwproducts/en/dsPIC33CK256MP508) microcontroller that is available as a PIM (Plug in Module). 

The purpose is to demonstrate how to integrate X2Cscope ot a custom/bare application.

* X2Cscope documentation: [https://x2cscope.github.io/](https://x2cscope.github.io/)
* X2Cscope training: [Microchip University](https://mu.microchip.com/page/all-courses)

The code functionality is minimalistic in order to avoid unneceseary confusion. The firmware generates a digital sawtooth and a sine signal. There is LED1 that is blinking with the sawtooth signal's period. The LED2 can be controlled manually by the [X2Cscope run-time debugger tool](https://x2cscope.github.io/). The state of the SW1 can be read out by X2Cscope.

![HW setup](doc/LVMC_Blinky_Connectors.gif)
![X2Cscope](doc/Scope_Animated.gif)

## Getting Started

The demo is ready to use with the [listed hardwares below](#hardware).

1. Clone or Download zipped project.
2. [Connect Hardware](#connectors-used).
3. Open project with MPLAB X
4. Build project
5. Program the Hardware (HW) with the PICkit on board
6. Verify LED1 is blinking

## Use X2Cscope

The X2Cscope tool uses the UART to transfer data from and to the HW. To use this feature follow the steps:

1. Verify if X2Cscope plug-in is installed within MPLAB X. Detailed user guide: https://x2cscope.github.io/
2. Open X2Cscope 

![Open X2Cscope](doc/open_X2Cscope.png)

3. Verify UART settings at the Connection Setup tab and also check the COM port number on the PC. (device manager)

4. Connect to the HW with clicking on the connect sign:

![Open Button](doc/Connect_X2Cscope.png)

6. Use the Watch and Scope data views (available on the Data Views tab).

## Hardware

* **LVMC dev board:** [DM330031](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM330031) Low voltage motor control development board with [dsPIC33CK256MP508] (https://www.microchip.com/wwwproducts/en/dsPIC33CK256MP508) MCU populated on board

### Connectors used:

![Block Diagram](doc/BlockDiagram_HW_Setup.png)

* **J1/J2:** 24V Power supply
* **J13 USB:** PICkit on board 4 (PKOB4) programmer debugger
* **J6 USB-UART:** Used to connect UART to computer 

### Configuration

LVMC board is used in the default configuration. 

The LVMC board is capable to configure different signal routing modes by zero Ohm jumper resistors. For details see the [LVMC user guide](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM330031). 

* **UART:** J6 MCP2200 USB-UART chip is used for X2Cscope run-time debugging 
## Peripheral settings and I/O connections: 

**UART:**
   * Baud rate: 115200
   * Parity: None
   * Data bits: 8
   * Stop bits: 1
   * Flow control: no

**TIMER1:**
   * 1ms period
   * interrupt enabled

**IO**

| PIN | PORT   | Function |
| ----|--------|----------|
|  14 | RD13   | UART1 TX |
|  13 | RD14   | UART1 RX |
|  37 | RE6    | IO_LED1  |
|  39 | RE7    | IO_LED2  |
|  59 | RE11   | IO_SW1   |
|  62 | RE12   | IO_SW2   |

   Peripherals are configured manually in the HAL.c and X2Cscope.c files.

## Software

To use the demo only the MPLAB X IDE and XC16 compiler is required. 

* [MPLAB X](https://www.microchip.com/mplab/mplab-x-ide) Integrated Development Environment. 
* [XC16 Compiler:](https://www.microchip.com/mplab/compilers) Compiler for the Microchip 16bit MCUs
## Built With

* [XC16 v1.60](https://www.microchip.com/mplab/compilers) - Microchip C compiler for 16bit micros
low levev drivers
* [X2Cscope v0.6](https://x2cscope.github.io/) - Run-time firmware based debugger tool
