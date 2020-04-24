# PWMArduinoDue
A PWM library for Arduino Due (SAM3X).

With this library, it is possible to control the PWM ports with the following functionalities:
 * 		Activate or deactivate complementary PWM channels.
 * 		Synchronized or asynchronized PWM channels.

PWM channels that can be used (Main Channel & Complementary Channel):
 * 		PWMx0 (D34 & D35)
        PWMx1 (D36 & D37)
        PWMx2 (D38 & D39)
        PWMx3 (D40 & D41)
 
 DUE's ATMEL ATSAM3X8E micro-controller PWM modules.
 
 http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-11057-32-bit-Cortex-M3-Microcontroller-SAM3X-SAM3A_Datasheet.pdf
 
 Up to 8-channel 16-bit PWM (PWMC) with Complementary Output, Fault Input, 12-bit Dead Time Generator Counter for Motor Control.
 
 In this library only 4 channels are used, due to their locations on the Arduino board, however more channels can be added.
