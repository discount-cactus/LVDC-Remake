# LVDC-Remake
Goal: Build an equivalent of the flight computer to the Saturn V rocket from the 1960's.

From: October 9th, 2022 - Present

<em>DISCLAIMER: This repo does NOT include schematics, board layouts or fabrication files for any of the boards that make up the project. The purpose of this repo is to share a breif insight to the progress of the project. Some small pieces of the project are provided, but are merely for educational purposes.</em>

### Input Interface

![IMG_6119](https://user-images.githubusercontent.com/113632274/216847426-f2627f55-7505-462d-9c02-9a6e551deaf4.jpg)

The input interface was built to program, supply power to and run the master clock for the subsequent PCB's that make up the project. From a wall outlet-to-24V power supply, the power is stepped down to 20V, 12V 6V and 3V to accompany the original supply voltages across the LVDC. To program the boards that will make up the project, an Arduino Mega Pro is used to send programs to boards on a 28-bit bus - each bit being denoted by lighting an LED on the board when set to 1. For selecting a master clock for the boards, one simply bridges the one of the six pairs of header pins on the board - each clock running at a different speed.

### Memory Element

<img width="900" alt="Screen Shot 2023-02-26 at 11 30 07 AM" src="https://user-images.githubusercontent.com/113632274/222040516-715f9d4e-cc2d-4146-80f1-501ff87f04a2.png">

The Memory Element is composed of the memory and circuitry that manages the memory structure itself and stores all data for the LVDC. The original memory element stored information in a 128x64x28 array of ferrite cores that were magnetized in a certain direction to store a 1 or 0. For this project, and due to the complexity of constructing such an array of tiny ferrite cores, an Arduino Mega Pro was used to emulate this array - which further led to several modifications to circuitry directly interacting with the would-be ferrite core array.
