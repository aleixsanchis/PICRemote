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

#ifndef PWM2_H
#define PWM2_H

/**
  Section: Included Files
 */

#include <xc.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

    /**
      Section: Macro Declarations
     */

#define PWM2_INITIALIZE_DUTY_VALUE    25

    /**
      Section: PWM Module APIs
     */

    /**
      @Summary
        Initializes the PWM2

      @Description
        This routine initializes the EPWM2_Initialize
        This routine must be called before any other PWM2 routine is called.
        This routine should only be called once during system initialization.

      @Preconditions
        None

      @Param
        None

      @Returns
        None

      @Comment
     

     @Example
        <code>
        uint16_t dutycycle;

        PWM2_Initialize();
        PWM2_LoadDutyValue(dutycycle);
        </code>
     */
    void PWM2_Initialize(void);

    /**
      @Summary
        Loads 16-bit duty cycle.

      @Description
        This routine loads the 16 bit duty cycle value.

      @Preconditions
        PWM2_Initialize() function should have been called 
            before calling this function.

      @Param
        Pass 16bit duty cycle value.

      @Returns
        None

      @Example
        <code>
        uint16_t dutycycle;

        PWM2_Initialize();
        PWM2_LoadDutyValue(dutycycle);
        </code>
     */
    void PWM2_LoadDutyValue(uint16_t dutyValue);


#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif

#endif	//PWM2_H
/**
 End of File
 */