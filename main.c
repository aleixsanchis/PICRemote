/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "ir_transmitter.h"
#include "pin_definitions.h"
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    //INTERRUPT_GlobalInterruptDisable();
    //INTERRUPT_PeripheralInterruptDisable();
    
    

    while (1)
    {
        // LOAD INPUTS TO SHIFT REGISTER
        
        SHIFT_REG_CLK_INH = 0;
        SHIFT_REG_CLK = 0;
        SHIFT_REG_SH_NLD = 0;
        // SHIFT EACH INPUT ONE BY ONE
        for(uint8_t i=0; i<8; i++) {
            // CHECK IF ANY INPUT IS PRESSED
            uint8_t input = SHIFT_REG_INPUT;
            
            
            // IF PRESSED SEND TO IR EMITTER
            if(input == HIGH) {
                // DISABLE CLOCK
                SHIFT_REG_CLK_INH = 0;
                ir_emit(i);
            }
            
            // SHIFT REGISTER
            SHIFT_REG_CLK_INH = 1;
            SHIFT_REG_SH_NLD = 1;
            SHIFT_REG_CLK = 1;
        }
        
        
    }
}   
/**
 End of File
*/
