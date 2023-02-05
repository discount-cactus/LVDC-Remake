//LVDC Input Interface
//Used to send individual commands to the LVDC

#include "LVDC.h"

const int address[28] = {22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
int instruction[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int n = 0;

LVDC lvdc;

void setup(){
  lvdc.setAddress(address); //Sets the pins as outputs
  lvdc.writeToAddress(instruction); //Writes the output to the bus
}

void loop(){
  //test_random_pins(); delay(1000);
  test_sweep();
  //clock_pulse_2_048_MHZ()
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

void test_sweep(){
  n++;
  if (n == 28){
    n = 0;
  }
  for(int i=0; i < 28; i++){
    if (i <= n){
      digitalWrite(address[i],HIGH);
    }else{
      digitalWrite(address[i],LOW);
    }
  }
  delay(100);
}

void clock_pulse_2_048_MHZ(){
  delayMicroseconds(1);
}
