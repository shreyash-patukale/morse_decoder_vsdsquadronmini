# Morse Code Decoder using VSDSquadron

## Introduction

This project demonstrates a simple Morse Code Decoder, transforming the timeless language of dots and dashes into readable text. Utilizing the compact and efficient VSDSquadron mini development board, featuring the CH32V003F4U6 microcontroller, this system allows for seamless input of Morse Code using a single-button interface. Another button is used to mark the completion of every letter. The microcontroller decodes these inputs sequentially and displays the translated text on an OLED screen. This project showcases simplicity and sophistication, demonstrating how minimal hardware can be used to achieve precise decoding of morse code.

## Overview

The project aims to develop a Morse Code Decoder using the VSDSquadron mini development board, which features the CH32V003F4U6 microcontroller. It decodes Morse code signals and displays the decoded text on an OLED screen. The system includes a single-button interface for Morse code input, where short and long presses represent dots and dashes, respectively. Additionally, a second button is used to signal the completion of a letter.  The CH32V003F4U6 microcontroller leverages its GPIO capabilities for signal detection and I2C interface for OLED communication. By differentiating between short and long presses, the system accurately interprets Morse code in real-time. This implementation highlights the efficient use of minimal hardware for effective signal processing and communication.


## Components Required
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
| SW3 | PD4 (optional) |
| GND | GND |




## WORKING OF PROJECT:






https://github.com/shreyash-patukale/team_ayodhya/assets/135097306/04a92d0c-3605-4887-9552-f861fea6dd46















