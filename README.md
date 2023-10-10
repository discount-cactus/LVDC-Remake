# LVDC-Remake
Goal: Build an equivalent of the flight computer to the Saturn V rocket from the 1960's.

From: October 9th, 2022 - Present

<em>DISCLAIMER: This repo does NOT include schematics, board layouts or fabrication files for any of the boards that make up the project. The purpose of this repo is to share a breif insight to the progress of the project. Some small pieces of the project are provided, but are merely for educational purposes.</em>

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

![IMG_8091](https://github.com/discount-cactus/LVDC-Remake/assets/113632274/33f172e7-dc60-4729-8b49-1f67608c539a)

The Program Control Element manages the starting and stopping of programs, conditioning memory address decoders to select instructions, selecting data and instruction memory sectors, selecting instruction addresses within memory sectors, storing and decoding op codes, interrupting programs to perform subroutines and generating HOP constants to resume programs. 

### Arithmetic Element / Multiply-Divide Element

![IMG_8206](https://github.com/discount-cactus/LVDC-Remake/assets/113632274/2973960f-8a55-4615-b597-c194c334616d)

The Arithmetic Element and the Multiply-Divide Element were combined into the same board given their similar functions. Together, they handle all mathematical computations on the computer. The arithmetic handles all addition and subtraction and similar operations while the multiply-divide element, given their complexity, are dedicated strictly to binary multiplication and division.
