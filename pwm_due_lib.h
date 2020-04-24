/* --------------------------------------------------------------------------------------
 * PWM_DUE_LIB library
 * --------------------------------------------------------------------------------------
 * Copyright (c) 2018 -
 * Nuno Vilhena 
 * https://github.com/nunovilhena/PWMArduinoDue
 * 
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see: <http://www.gnu.org/licenses/>.
 *
 * Description: This file includes classes and objects for using with Arduino
 * 				DUE's ATMEL ATSAM3X8E micro-controller PWM modules.
 *        PWM channels that can be used: PWMx0 (D34 & D35), PWMx1 (D36 & D37), PWMx2 (D38 & D39), PWMx3 (D40 & D41)
 * 18/01/2018 v1.00 First development version.
 * 03/03/2018 v2.00 Functions START_PWM and STOP_PWM were added.
 * 15/09/2018 v2.10 When function STOP_PWM is called, the dutycycle is also set to zero.
 * 
 * Microcontroller DataSheet: <atmel-11057-32-bit-cortex-m3-microcontroller-sam3x-sam3a_datasheet.pdf>
 *
 * Other similar projects that can help you:
 * <https://github.com/collin80/DueMotorCtrl>
 * <https://github.com/antodom/pwm_lib>
 * --------------------------------------------------------------------------------------
 * Main Directory:	<C:*\ArduinoData\packages\arduino\hardware\sam\1.6.11>
 * Variants:		<C:*\ArduinoData\packages\arduino\hardware\sam\1.6.11\variants\arduino_due_x>
 * Components: 		<C:*\ArduinoData\packages\arduino\hardware\sam\1.6.11\system\CMSIS\Device\ATMEL\sam3xa>
 * Libraries:		<C:*\ArduinoData\packages\arduino\hardware\sam\1.6.11\system\libsam>
 * 
-----------------------------------------------------------------------------------------**/

#ifndef PWM_DUE_LIB_H
#define PWM_DUE_LIB_H
#include <Arduino.h>

#define PWM_DC_RES (0x1u << 12); //12 bits
#define PWM__CENTRE_ALIGNED	PWM_CMR_CALG		// centre aligned ; 0 - left aligned
#define PWM__LEFT_ALIGNED	0		// centre aligned
#define PWM_DTE_ENABLED PWM_CMR_DTE //dead time enabled
#define PWM_DTE_DISABLED 0 //dead time enabled
#define PWM_COUNTER 2
#define PWM_FREQ_MULTIPLIER 2	//if the aligned is defined do cetre, this value should be 2

typedef struct _PinDescription_Due_Lib
{
  Pio* pPort ;
  uint32_t ulPin ;
  uint32_t uhPin ;
  uint32_t uPeripheralId ;
  EPioType uPinType ;
  uint32_t uPinConfiguration ;
  uint32_t uPinAttribute ;
  EPWMChannel uPWMChannel ;
} PinDescription_Due_Lib ;



/* Pins table to be instanciated into variant.cpp */
extern const PinDescription_Due_Lib pwm_PinDescription[] ;



unsigned int setup_pwm(unsigned int pwm2activate, unsigned int pwm_sync, unsigned int frequency);
void disable_comp(unsigned int pwm_port);
void start_pwm(void);
void start_pwm(uint32_t ch);
void stop_pwm(void);
void stop_pwm(uint32_t ch);

void updatePWM(unsigned int pwm_port, unsigned int dc_value);
void update_SyncPWM(unsigned int dc_1, unsigned int dc_2);
void update_SyncPWM(unsigned int dc_1, unsigned int dc_2, unsigned int dc_3);
void update_SyncPWM(unsigned int dc_1, unsigned int dc_2, unsigned int dc_3, unsigned int dc_4);

#endif
