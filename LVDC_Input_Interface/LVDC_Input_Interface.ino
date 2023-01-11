//LVDC Input Interface
//Used to send individual commands to the LVDC

#include "LVDC.h"

const int address[28] = {22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
int instruction[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

LVDC lvdc;

void setup(){
  lvdc.setAddress(address); //Sets the pins as outputs
  lvdc.writeToAddress(instruction); //Writes the output to the bus
}

void loop(){
  test_random_pins();
  delay(1000);
}

void test_random_pins(){
  for(int i=0; i < 28; i++){
    instruction[i] = random(0,2);
    if (instruction[i] == 1){
      digitalWrite(address[i],HIGH);
    }else{
      digitalWrite(address[i],LOW);
    }
  }
}
