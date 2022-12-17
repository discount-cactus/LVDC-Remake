//LVDC Memory Module
//Module to simulate each of eight different memory modules within the LVDC

//To-Do's:
//Module address
//Sector address
//Octal to decimal function

#define memoryLocations 256

const int dataPin[28] = {};
const int addressPin[5] = {};
int address[memoryLocations][28] = {};



void setup() {
  //Sets the data pins as inputs
  for(int i=0; i < 28; i++){
    pinMode(dataPin[i],INPUT);
  }

  //Sets the address pins as inputs
  for(int i=0; i < 5; i++){
    pinMode(addressPin[i],INPUT);
  }

  //Initializes and clears the memory
  for(int i=0; i < memoryLocations; i++){
    for(int ii=0; ii < 28; ii++){
      address[i][ii] = 0;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}





void address_sweep(){
  for(int i=0; i < memoryLocations; i++){
    for(int ii=0; ii < 28; ii++){
      if(address[i][ii] == 1){
        digitalWrite(address[i][ii],HIGH);
      }else{
        digitalWrite(address[i][ii],LOW);
      }
    }
  }
  delay(500);
}
