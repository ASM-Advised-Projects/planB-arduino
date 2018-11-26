#pragma once

#ifndef RASM_joystick_h
#define RASM_joystick_h

#include <Arduino.h>

class RASM_joystick
{
  public:
    // constuctor.. default pin selection
    RASM_joystick();

    // public methods
    void _init(); // Initialize the pins
    void controllerRead();

  private:
    int rasm_state;    // this is the state, type integer
    unsigned char upLevelButton = ;
    unsigned char downLevelButton = ;
    unsigned char homeButton = ;
    unsigned char joystickY = ;
    unsigned char joystickX = ;
    int upLevelVal = 0;
    int downLevelVal = 0;
    int homeVal = 0;
    int yVal = 524;
    int xVal = 524;
}; // end class

#endif
