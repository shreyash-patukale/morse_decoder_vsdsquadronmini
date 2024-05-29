# Morse Code Decoder using VSDSquadron

## Introduction

This project presents the design and implementation of an efficient Morse Code Decoder utilizing the VSDSquadron mini microcontroller. The system interprets Morse code signals through a single-button interface, employing precise timing analysis to differentiate between short presses (representing dots) and long presses (representing dashes). The decoded Morse code is then processed in real-time and displayed on an OLED screen using I2C serial communication. This implementation underscores the potential of integrating minimal hardware components with advanced signal processing algorithms to facilitate reliable and effective digital communication.

## Overview

The project aims to develop a digital system that decodes Morse code signals input through a single-button interface and displays the corresponding text on an OLED display. This project leverages the capabilities of the CH32V003F4U6 microcontroller, utilizing its GPIO functionalities for signal input detection and its I2C interface for communication with the OLED display. The system differentiates between short and long presses to accurately interpret Morse code sequences in real-time, demonstrating efficient use of minimal hardware resources for effective signal processing and digital communication.



## Components Required (Bill of Materials)


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
