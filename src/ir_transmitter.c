#include "ir_transmitter.h"
#include "pin_manager.h"
#include "device_config.h"
#include "pwm2.h"
#include "tmr2.h"
#define RECEIVER_ADDRESS 0

uint8_t last_command_sent = 0xFF;

static void send_pwm_burst() {
    TMR2 = 0x00;
    // PWM IS ENABLED BY SETTING RA0 back to an output
    TRISAbits.TRISA0 = 0;
    TMR2_StartTimer();
}

static inline void stop_pwm_burst() {
    TMR2_StopTimer();
    // BY SETTING RA0 to input, PWM is disabled
    TRISAbits.TRISA0 = 1;
}

static void nec_send_header() {
    send_pwm_burst();
    __delay_us(9000);
    stop_pwm_burst();
    __delay_us(4500);
}

static void nec_send_value(uint8_t value) {
    for (uint8_t i = 0; i < 8; i++) {
        if (value & 0x1) {
            send_pwm_burst();
            __delay_us(562.5);
            stop_pwm_burst();
            __delay_us(1687.5);
        } else {
            send_pwm_burst();
            __delay_us(562.5);
            stop_pwm_burst();
            __delay_us(562.5);
        }
        value = value >> 1;
    }
}

static void nec_send_frame(uint8_t address, uint8_t command) {
    // HEADER: 9 mS PULSE
    nec_send_header();
    // ADDRESS
    nec_send_value(address);
    // !ADDRESS
    nec_send_value(~address);
    // COMMAND
    nec_send_value(command);
    // !COMMAND
    nec_send_value(~command);
    // FINAL PAUSE
    stop_pwm_burst();
    __delay_us(562.5);
}

void ir_emit(uint8_t data) {
    if (1) {
        nec_send_frame(RECEIVER_ADDRESS, data);
        last_command_sent = data;
    } else {
        // SEND REPEAT CODE
    }
}

