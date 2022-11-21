//LVDC Input Interface
//Used to send individual commands to the LVDC

const int writePin[28] = {};

void setup() {
  for(int i=0; i < 28; i++){
    pinMode(writePin[i],OUTPUT);
  }
}

void loop() {}
