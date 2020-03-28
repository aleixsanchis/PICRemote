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

#include "mcc.h"
#include "ir_transmitter.h"
#include "pin_manager.h"

/*
                         Main application
 */
void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    //INTERRUPT_GlobalInterruptDisable();
    //INTERRUPT_PeripheralInterruptDisable();



    while (1) {
        // LOAD INPUTS TO SHIFT REGISTER
        SHIFT_REG_SH_NLD = 0;
        SHIFT_REG_CLK = 0;
        // SHIFT EACH INPUT ONE BY ONE
        for (uint8_t i = 0; i < 8; i++) {
            // CHECK IF ANY INPUT IS PRESSED
            uint8_t input = SHIFT_REG_INPUT;

            // IF PRESSED (PULLED TO LOW) SEND TO IR EMITTER
            if (input == LOW) {
                ir_emit(i);
            }
            // ENABLE SHIFTING
            SHIFT_REG_SH_NLD = 1;
            // MAKE SURE THE SHIFT IS ENABLED
            __delay_us(1);
            // RISE CLK
            SHIFT_REG_CLK = 1;
            // MAKE SURE THAT CLK STAYS LOW ENOUGH TIME
            __delay_us(1);
            SHIFT_REG_CLK = 0;
        }
    }
}
/**
 End of File
 */
