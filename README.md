# PICRemote
This project is meant to be used in conjunction with https://github.com/aleixsanchis/PICKeyboard.

It is an IR remote control using a PIC10F322 microcontroller. The key codes are transmitted using the [NEC Protocol](https://techdocs.altium.com/display/FPGA/NEC+Infrared+Transmission+Protocol)

The goal of the project was to control the media playing in my computer remotely from my bed when watching movies.
The commands will be received by [another device](https://github.com/aleixsanchis/PICKeyboard) and will be transmitted as USB HID Keycodes to the pc

A more in-depth explanation and tutorial can be found at https://aleixsanchis.github.io/2019/ir-emitter/
