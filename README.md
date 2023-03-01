# LVDC-Remake
Reverse Engineering the LVDC flight computer to the Saturn V rocket from the 1960's.

From: October 9th, 2022 - Present

### Input Interface

![IMG_6119](https://user-images.githubusercontent.com/113632274/216847426-f2627f55-7505-462d-9c02-9a6e551deaf4.jpg)

The input interface was built to program, supply power to and run the master clock for the subsequent PCB's that make up the project.

### Memory Element

<img width="900" alt="Screen Shot 2023-02-26 at 11 30 07 AM" src="https://user-images.githubusercontent.com/113632274/222040516-715f9d4e-cc2d-4146-80f1-501ff87f04a2.png">

The Memory Element is composed of the memory and circuitry that manages the memory structure itself and stores all data for the LVDC. The original memory element stored information in a 128x64x28 array of ferrite cores that were magnetized in a certain direction to store a 1 or 0. For this project, and due to the complexity of constructing such an array of tiny ferrite cores, an Arduino Mega Pro was used to emulate this array - which further led to several modifications to circuitry directly interacting with the would-be ferrite core array.
