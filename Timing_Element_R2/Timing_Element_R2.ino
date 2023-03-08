//Timing Element R2
//A single-component substitution to the Timing Element R1 board
#include "LVDC.h"

int bit_time = 1; // 1-14
int phase = 0;    // 0=A, 1=B, 2=C

TimingElementR2 Timer;

void setup() {
  Serial.begin(9600);
  Timer.setClockSpeed_MHz(2.048);
  Serial.print(Timer.clockDelay);
  Timer.map_timing_logic_pins(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
  Timer.map_clock_generator_pins(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
  Timer.map_timing_element_output_pins(1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
}

void loop() {
  bit_time++;             //Increments the bit time and phases
  if (bit_time == 15){
    bit_time = 1;
    phase++;
    if (phase == 3){
      phase = 0;
    }
  }
  Timer.map_outputs(bit_time,phase);
  
  delayMicroseconds(Timer.clockDelay);
}
