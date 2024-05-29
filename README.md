# Morse Code Decoder using VSDSquadron

## Introduction

This project demonstrates the design and implementation of a Morse Code Decoder using the VSDSquadron mini microcontroller. Morse code signals are input via a single-button interface, with short and long presses representing dots and dashes. The CH32V003F4U6 microcontroller processes these signals in real-time and displays the decoded text on an OLED screen using I2C communication. This system showcases the efficient use of minimal hardware resources to achieve accurate and reliable digital communication through advanced signal processing techniques.

## Overview

The project aims to develop a digital Morse Code Decoder using the VSDSquadron mini microcontroller. It decodes Morse code signals input via a single-button interface and displays the text on an OLED screen. The CH32V003F4U6 microcontroller leverages its GPIO capabilities for signal detection and I2C interface for OLED communication. By differentiating between short and long presses, the system accurately interprets Morse code in real-time. This implementation highlights the efficient use of minimal hardware for effective signal processing and communication.


## Components Required (Bill of Materials)
• CH32V003F4U6 Microcontroller (on VSDSquadron Mini RISC-V development board)

• Push Button Switch 2x

• 0.96" (128*64 pixels) I2C OLED Display

• Connecting wires

• Breadboard (optional)

# Circuit Connection Diagram
![Circuit_Diagram](https://github.com/shreyash-patukale/team_ayodhya/assets/157274443/5615e4f9-749e-4119-aad7-df8a883f5b76)
# Table for Pin Connection
| 0.96" I2C OLED Display | VSD Squadron Mini |
| --- | --- |
| SCK | PC1 |
| SDA | PC2 |
| VCC | 3.3V |
| GND | GND |

| Push Button | VSD Squadron Mini |
| --- | --- |
| SW1 | PD2 |
| GND | GND |
| SW2 | PD3 |
| GND | GND |
