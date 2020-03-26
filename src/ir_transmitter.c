#include "ir_transmitter.h"
#include "pin_definitions.h"
#include "device_config.h"
#include "pwm2.h"
#include "tmr2.h"
#include "tmr0.h"
#define RECEIVER_ADDRESS 0

enum sending_state last_sent;
static void send_pwm_burst(enum nec_timings timing){
    // SETUP TIMER BASED ON burst_time
    switch(timing) {
        case NEC_HEADER_US:
            break;
        case NEC_HEADER_SPACE_US:
            break;
        case NEC_BURST:
            break;
        case NEC_0_SPACE:
            break;
        case NEC_1_SPACE:
            break;
    }
    
    // ENABLE PWM OUTPUT
    PWM2CONbits.PWM2OE = 1;
    last_sent = LAST_HIGH;
    TMR2_StartTimer();
}

static void nec_send_header(){
    send_pwm_burst(NEC_HEADER_US);
}
static void nec_send_frame(uint8_t address, uint8_t command){
    // HEADER: 8 mS PULSE
    nec_send_header();
    
    // ADDRESS
    
    // !ADDRESS
    
    // COMMAND
    
    // !COMMAND
}

void ir_emit(uint8_t data){
    // TODO EMIT
    nec_send_frame(RECEIVER_ADDRESS, data);
}

