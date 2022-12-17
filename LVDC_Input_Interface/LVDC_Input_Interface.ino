//LVDC Input Interface
//Used to send individual commands to the LVDC

const int writePin[28] = {22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
const int data[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() {
  //Sets the pins as outputs
  for(int i=0; i < 28; i++){
    pinMode(writePin[i],OUTPUT);
  }

  //Writes the output to the bus
  for(int i=0; i < 28; i++){
    if (data[i] == 1){
      digitalWrite(writePin[i],HIGH);
    }else{
      digitalWrite(writePin[i],LOW);
    }
  }
}

void loop(){}
