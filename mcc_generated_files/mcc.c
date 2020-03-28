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


void SYSTEM_Initialize(void)
{

    PIN_MANAGER_Initialize();
    OSCILLATOR_Initialize();
    WDT_Initialize();
    TMR2_Initialize();
    PWM2_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // LFIOFR 31.25KHz_osc_not_ready; HFIOFS unstable; HFIOFR 16MHz_osc_not_ready; IRCF 8MHz; 
    OSCCON = 0x60;
    // CLKROE disabled; 
    CLKRCON = 0x00;
    // SBOREN disabled; BORFS disabled; BORRDY BOR Circuit is inactive; 
    BORCON = 0x00;
}

void WDT_Initialize(void)
{
    // WDTPS 1:65536; SWDTEN OFF; 
    WDTCON = 0x16;
}

/**
 End of File
*/
