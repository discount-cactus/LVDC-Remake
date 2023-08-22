# LVDC-Remake
Goal: Build an equivalent of the flight computer to the Saturn V rocket from the 1960's.

From: October 9th, 2022 - Present

<em>DISCLAIMER: This repo does NOT include schematics, board layouts or fabrication files for any of the boards that make up the project. The purpose of this repo is to share a breif insight to the progress of the project. Some small pieces of the project are provided, but are merely for educational purposes.</em>

### Input Interface

![IMG_6119](https://user-images.githubusercontent.com/113632274/216847426-f2627f55-7505-462d-9c02-9a6e551deaf4.jpg)

The input interface was built to program, supply power to and run the master clock for the subsequent PCB's that make up the project. From a wall outlet-to-24V power supply, the power is stepped down to 20V, 12V 6V and 3V to accompany the original supply voltages across the LVDC. To program the boards that will make up the project, an Arduino Mega Pro is used to send programs to boards on a 28-bit bus - each bit being denoted by lighting an LED on the board when set to 1. For selecting a master clock for the boards, one simply bridges the one of the six pairs of header pins on the board - each clock running at a different speed.

### Oscillator Circuit

![A2721D0C-8056-42A7-A91B-A5EB6A01F983](https://user-images.githubusercontent.com/113632274/222984666-3fa7818a-9606-4216-9359-1ebf27127a7b.PNG)

The original LVDC ran the master clock at a speed of 2.048MHz to drive timing and sequencing logic throughout the computer. While other clocks nested on the input interface can be used to run the master clock, a standalone circuit was built to enable running the projects boards at the speed of the original computer.

### Memory Element

![IMG_6613](https://user-images.githubusercontent.com/113632274/230699162-63b6d666-30f4-4b52-b037-1b50e7f714fa.JPG)

The Memory Element is composed of the memory and circuitry that manages the memory structure itself and stores all data for the LVDC. The original memory element stored information in a 128x64x14 array of ferrite cores that were magnetized in a certain direction to store a 1 or 0. For this project, and due to the complexity of constructing such an array of tiny ferrite cores, an Arduino Mega Pro was used to emulate this array - which further led to several modifications to circuitry directly interacting with the would-be ferrite core array.

### Memory Control Element

![IMG_7375](https://github.com/discount-cactus/LVDC-Remake/assets/113632274/76904940-fd68-42c7-a28c-d6afd428e831)

The Memory Control Element acts as the bridge between the memory and the rest of the computer by taking in commands and other addressing signals to be sent to the memory element to read and write to/from the memory. During read instructions, the memory control element configures the memory element to be ready to be read from - and likewise during write instructions configures the memory element to be written to.

### Data Control Element

![IMG_7374](https://github.com/discount-cactus/LVDC-Remake/assets/113632274/eb478e19-3e44-4d2a-b6b2-31c3ee7432b1)

The Data control Element provides the main register responsible for transferring data to locations all over the computer.

### Program Control Element

<img width="832" alt="Screen Shot 2023-08-14 at 1 31 21 PM" src="https://github.com/discount-cactus/LVDC-Remake/assets/113632274/9fbe37ed-6592-4d57-b917-d3139101a5ca">

The Program Control Element manages the starting and stopping of programs, conditioning memory address decoders to select instructions, selecting data and instruction memory sectors, selecting instruction addresses within memory sectors, storing and decoding op codes, interrupting programs to perform subroutines and generating HOP constants to resume programs. 
