/*  This file is part of PICRemote.

    PICRemote is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PICRemote is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PICRemote.  If not, see <https://www.gnu.org/licenses/>.
 */

 #include <xc.h>
 #include "pwm2.h"

 /**
   Section: PWM Module APIs
 */

 void PWM2_Initialize(void)
 {
    // Set the PWM to the options selected in the PIC10 / PIC12 / PIC16 / PIC18 MCUs.
    // PWM2POL active_hi; PWM2OE disabled; PWM2EN enabled; 
    PWM2CON = 0x80;   
    
    PWM2CONbits.PWM2OE = 1;

    // PWM2DCH 6; 
    PWM2DCH = 0x06;   

    // PWM2DCL 1; 
    PWM2DCL = 0x40;   
    

 }

 void PWM2_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM2DCH = (dutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM2DCL = (dutyValue & 0x0003)<<6;
 }
 /**
  End of File
 */
