
// this is the header file for the Dual MC33926 Motor Sheild to incorporate 3 motor drivers on Arduino Mega for RASM project. This header file is built from [link below] as the reference
#pragma once

#ifndef dualMC33926_motorDriver1_h
#define dualMC33926_motorDriver1_h

#include <Arduino.h>

class dualMC33926_motorDriver1
{
	public:
		// CONSTRUCTORS
		 // Default pin selection.
		dualMC33926_motorDriver1();

		// PUBLIC METHODS
		void init(); // Initialize TIMER 1, set the PWM to 20kHZ.
		void setM1Speed(int speed); // Set speed for M1.
		void setM2Speed(int speed); // Set speed for M2.
		void setSpeeds(int speedM1, int speedM2); // Set speed for both M1 and M2.
		void setM1Brake(int brake);
		void setM2Brake(int brake);
		void setBrakes(int brake1, int brake2);
		//unsigned int getM1CurrentMilliamps(); // Get current reading for M1.
		//unsigned int getM2CurrentMilliamps(); // Get current reading for M2.
		//unsigned char getM1Fault(); // Get fault reading.

	private:
		// for motor 1
		unsigned char _M1IN1;
		unsigned char _M1IN2;
		unsigned char _M1PWM_D2;
		unsigned char _M1_D1;
		static const unsigned char _PWM1_TIMER1_PIN = 9;
		unsigned char _M1SF;
		unsigned char _M1FB;

		// for motor 2
		unsigned char _M2IN1;
		unsigned char _M2IN2;
		unsigned char _M2PWM_D2;
		unsigned char _M2_D1;
		static const unsigned char _PWM2_TIMER1_PIN = 10;
		unsigned char _M2SF;
		unsigned char _M2FB;

}; //end of class
#endif
