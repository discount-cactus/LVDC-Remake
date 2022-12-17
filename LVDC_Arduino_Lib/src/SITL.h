/*
Name:     LVDC.h
Created:  12/16/2022 10:49:16 PM
Author:   Brandon
*/

#ifndef LVDC_h
#define LVDC_h

#include "Arduino.h"

class Sensor{
  // user-accessible "public" interface
  public:
    Sensor();
    void increment();

    float simAccelX;
    float curve_x[]; //Undefined-length arrays are defined last

  // library-accessible "private" interface
  private:
};

#endif
