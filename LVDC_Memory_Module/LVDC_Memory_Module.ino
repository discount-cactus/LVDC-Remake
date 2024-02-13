//LVDC Memory Module
//Module to simulate a single memory module within the LVDC
#include <LVDC.h>
#include "Adafruit_FRAM_I2C.h"

#define FRAM_A1 4
#define FRAM_A2 5
#define SyllableSelect 6
#define MemoryModuleSelect 7
#define write_read 14
#define dataSig 15
#define ED_detect_Y 16
#define ED_detect_X 17

const int dataPin[14] = {A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13};
const int sectorSelect[4] = {36,37,38,39};

const int Lo_Y[3] = {22,23,24};
const int Hi_Y[3] = {25,26,27};
const int Lo_X[3] = {28,29,30};
const int Hi_X[4] = {32,33,34,35};

const int Lo_Y_answer[3] = {0,1,0};
const int Hi_Y_answer[3] = {0,1,0};
const int Lo_X_answer[3] = {0,1,0};
const int Hi_X_answer[4] = {0,0,1,0};

byte memory[64][64];
int syllable;
//int sector = 0;
int x_coordinate = 0;
int y_coordinate = 0;

int analogWriteVal = 255; // from 0-255

MemoryModule MM;
Adafruit_FRAM_I2C FRAM = Adafruit_FRAM_I2C(); //MB85RC256V FRAM chip

void setup() {
  Serial.begin(9600);
  while(!Serial){}
  FRAM.begin();                               //Default address is 0x50
  
  initialize_memory();                        //Initializes the memory
  //initialize_memory_with_random_data();
  
  for(int i=0; i < 14; i++){                  //Sets the address pins as inputs
    pinMode(dataPin[i],INPUT);
  }
  for(int i=0; i < 4; i++){                  //Sets the sector select pins as inputs
    pinMode(sectorSelect[i],INPUT);
  }
  for(int i=0; i < 3; i++){                   //Sets the y-coordinate select pins as inputs
    pinMode(Lo_Y[i],INPUT);
    pinMode(Hi_Y[i],INPUT);
    pinMode(Lo_X[i],INPUT);
  }
  for(int i=0; i < 4; i++){                   //Sets the x-coordinate select pins as inputs
    pinMode(Hi_X[i],INPUT);
  }
  pinMode(MemoryModuleSelect,INPUT);
  pinMode(SyllableSelect,INPUT);
  pinMode(write_read,INPUT);
  
  pinMode(ED_detect_Y,OUTPUT);
  pinMode(ED_detect_X,OUTPUT);
  pinMode(dataSig,OUTPUT);

  Serial.println("Entering loop"); delay(1000);
}

void loop() {
  //Functions only when the module is selected
  if (digitalRead(MemoryModuleSelect) == HIGH){

    update_data_location();
    
    if (digitalRead(write_read) == HIGH){         //Determines reading or writing, 0 = read, 1 = write
      readData(syllable, x_coordinate, y_coordinate);
    }else{
      writeData(syllable, x_coordinate, y_coordinate);
    }
  }
}





void initialize_memory(){
  for(int i=0; i < 64; i++){
    for(int ii=0; i < 64; ii++){
      memory[i][ii] = MM.location_empty; //0b00000000000000
    }
  }
}

/*void initialize_memory_with_random_data(){
  int num;
  for(int i=0; i < 64; i++){
    for(int ii=0; i < 64; ii++){
      byte tempData = 0b00000000000000;
      for(int i=0; i < 14; i++){
        num = random(0,10);
        if(num > 5){
          bitWrite(tempData,i,1);
        }else{
          bitWrite(tempData,i,0);
        }
      }
      memory[i][ii] = tempData;
    }
  }
}*/

void update_data_location(){
  int ii = 0;
  
  //Determines syllable
  if (digitalRead(SyllableSelect) == HIGH){
    syllable = 1;
  }else{
    syllable = 0;
  }
  
  //Determines sector
  /*sector = 0;
  ii = 0;
  for(int i=4; i > 0; i--){
    sector += sectorSelect[i] * pow(2,ii);
    ii++;
  }*/

  //Finds the xy coordinates
  int Lo_Y_coord = 0;
  for(int i=2; i >= 0; i--){
      Lo_Y_coord += Lo_X_answer[i] * pow(2,ii);
      ii++;
  }
  Serial.print("Lo Y: ");Serial.print(Lo_Y_coord); Serial.print("   ");

  int Hi_Y_coord = 0;
  ii = 0;
  for(int i=2; i >= 0; i--){
      Hi_Y_coord += Hi_Y_answer[i] * pow(2,ii);
      ii++;
  }
  Serial.print("Hi Y: ");Serial.print(Hi_Y_coord); Serial.print("   ");

  int Lo_X_coord = 0;
  ii = 0;
  for(int i=2; i >= 0; i--){
    Lo_X_coord += Lo_X_answer[i] * pow(2,ii);
    ii++;
  }
  Serial.print("Lo X: ");Serial.print(Lo_X_coord); Serial.print("   ");

  int Hi_X_coord = 0;
  ii = 0;
  for(int i=3; i >= 0; i--){
    Hi_X_coord += Hi_X_answer[i] * pow(2,ii);
    ii++;
  }
  Serial.print("Hi X: ");Serial.print(Hi_X_coord); Serial.print("   ");Serial.println("");

  if ((Lo_Y_coord == Hi_Y_coord) && (Lo_X_coord == Hi_X_coord)){
    //location = (Hi_Y_coord * 10) + Hi_X_coord;
    x_coordinate = 0;(Hi_X_coord * 10) + Lo_X_coord;
    y_coordinate = 0;(Hi_Y_coord * 10) + Lo_Y_coord;
    digitalWrite(dataSig,HIGH);
    Serial.println("Coordinates found");
  }else{
    if (Lo_Y_coord != Hi_Y_coord){
      pinMode(ED_detect_Y,HIGH);
      Serial.println("ERROR: Y coordinates not found.");
    }
    if (Lo_X_coord != Hi_X_coord){
      pinMode(ED_detect_X,HIGH);
      Serial.println("ERROR: X coordinates not found.");
    }
  }
}

//Stores data to memory
void writeData(int syl, int xCoord, int yCoord){
  for(int i=0; i < 14; i++){
    if(digitalRead(dataPin[i]) == HIGH){
      bitWrite(memory[xCoord][yCoord],i,1);
    }else{
      bitWrite(memory[xCoord][yCoord],i,0);
    }
  }
}

//Writes data to the board
void readData(int syl, int xCoord, int yCoord){
  for(int i=0; i < 14; i++){
    if(bitRead(memory[xCoord][yCoord],i) == 1){
      digitalWrite(dataPin[i],HIGH);
    }else{
      digitalWrite(dataPin[i],LOW);
    }
  }
}

void printData(int syl, int xCoord, int yCoord){
  Serial.println(memory[xCoord][yCoord]);
}

void data_sweep(){
  //Prints all data in the memory to serial port
  Serial.println("Data in Memory:");
  for(int i=0; i < 64; i++){
    for(int ii=0; i < 64; ii++){
      Serial.print(memory[i][ii]);Serial.print(", ");
    }
  }
}

void FRAM_write(int address, int FRAMdata){
  FRAM.write(address,FRAMdata);
}

uint8_t FRAM_read(int address){
  uint8_t value = FRAM.read(address);
  return value;
}

void FRAM_dump(){
  // dump the entire 32K of memory!
  uint8_t value;
  for (uint16_t a=0; a < 32768; a++) {
    value = FRAM.read(a);
    if ((a % 32) == 0) {
      Serial.print("\n 0x"); Serial.print(a, HEX); Serial.print(": ");
    }
    Serial.print("0x"); 
    if (value < 0x1) 
      Serial.print('0');
    Serial.print(value, HEX); Serial.print(" ");
  }
}
