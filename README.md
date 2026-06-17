# Temperature Monitoring and FPGA Control using ESP8266 and ET1035 RISC-V FPGA

## Overview

This project implements a temperature monitoring and FPGA control system using an ESP8266 microcontroller and an ET1035 RISC-V processor running on the Arty A7 FPGA platform. A thermistor-based analog temperature signal is acquired using the ESP8266 ADC, converted into a 4-bit digital representation, and transmitted to the FPGA through GPIO lines. The FPGA reconstructs the received value and performs threshold-based LED control.

## Hardware Components

* ESP8266 NodeMCU
* Arty A7 FPGA Development Board
* ET1035 RISC-V Processor
* Thermistor
* Fixed Resistor (Voltage Divider)
* LEDs
* Jumper Wires

## Features

* Real-time temperature acquisition using ESP8266 ADC
* Analog-to-digital scaling from 10-bit ADC to 4-bit representation
* GPIO-based communication between ESP8266 and FPGA
* ET1035 RISC-V based data processing
* Threshold-based LED control
* UART monitoring and debugging

## System Architecture

Thermistor → ESP8266 ADC → 4-bit Scaling → GPIO Interface → ET1035 RISC-V Processor → LED Control

## GPIO Interface

| ESP8266 Pin | FPGA Pin |
| ----------- | -------- |
| GPIO5       | PIN_1    |
| GPIO4       | PIN_2    |
| GPIO14      | PIN_3    |
| GPIO12      | PIN_4    |

## Working Principle

1. A thermistor voltage divider generates an analog voltage proportional to temperature.
2. ESP8266 samples the voltage using its internal ADC.
3. The 10-bit ADC value (0–1023) is scaled to a 4-bit value (0–15).
4. The 4-bit data is transmitted through GPIO lines GPIO5, GPIO4, GPIO14, and GPIO12.
5. The ET1035 RISC-V processor reads the GPIO inputs and reconstructs the original 4-bit value.
6. If the received value exceeds a predefined threshold (13), the FPGA activates the LED connected to PIN_8.
7. UART output continuously displays the received value for debugging and verification.

## Software Implementation

### ESP8266

* ADC acquisition
* 10-bit to 4-bit scaling
* GPIO transmission
* Serial debugging

### ET1035 RISC-V Processor

* GPIO data reception
* Binary reconstruction
* Threshold comparison
* LED control
* UART status reporting

## Technologies Used

* Embedded C
* ESP8266
* ET1035 RISC-V Processor
* Arty A7 FPGA
* UART Communication
* GPIO Interfacing
* ADC Signal Acquisition

## Results

The system successfully demonstrated reliable temperature acquisition, GPIO-based communication between ESP8266 and FPGA, and threshold-based LED control using the ET1035 RISC-V processor.

## Demonstration

Please refer to the Hardware_Implementation_Video.mp4 file in the Results folder for a complete working demonstration of the system.

## Author

Sharthak Raj
