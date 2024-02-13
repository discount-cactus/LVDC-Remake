//Timing Element Simulator
//A single-component substitution to the Timing Element R1 board
#include "LVDC.h"

#define INPUT_A_pin 0
#define SHIFT_IN_pin 1
#define SHIFT_OUT_pin 2
#define CLK_pin 3
#define CLR_pin 4

int a = 0;
int aa = 0;

TimingElementSimulator Timer;

void setup() {
  Serial.begin(9600);
  //Timer.setClockSpeed_MHz(2.048);
  //Serial.print(Timer.clockDelay);

  pinMode(INPUT_A_pin,OUTPUT);
  pinMode(SHIFT_IN_pin,INPUT);
  pinMode(SHIFT_OUT_pin,OUTPUT);
  pinMode(CLK_pin,OUTPUT);
  pinMode(CLR_pin,OUTPUT);

  digitalWrite(CLR_pin,HIGH);
}

void loop() {
  digitalWrite(INPUT_A_pin,LOW);
  a++;
  aa++;

  //Timing Logic Outputs
  if(a == 42){
    a = 0;
  }
  for(int i=23; i > -1; i--){
    if(Timer.timing_logic_map[a][i] == 1){
      digitalWrite(CLK_pin,HIGH);
      digitalWrite(SHIFT_IN_pin,HIGH);
    }else{
      digitalWrite(SHIFT_IN_pin,LOW);
    }
    digitalWrite(CLK_pin,HIGH);
  }

  //Clock Generator Outputs
  if(aa == 17){
    aa = 0;
  }
  for(int i=46; i > -1; i--){
    if(Timer.clock_generator_map[aa][i] == 1){
      digitalWrite(CLK_pin,HIGH);
      digitalWrite(SHIFT_IN_pin,HIGH);
    }else{
      digitalWrite(SHIFT_IN_pin,LOW);
    }
    digitalWrite(CLK_pin,HIGH);
  }

  digitalWrite(INPUT_A_pin,HIGH);
  delay(1000);    //delayMicroseconds(Timer.clockDelay/2);
}
