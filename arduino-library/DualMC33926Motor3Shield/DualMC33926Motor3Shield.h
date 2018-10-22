// this is the header file for the Dual MC33926 Motor Sheild to incorporate 3 motor drivers on Arduino Mega for RASM project. This header file is built from [link below] as the reference
#pragma once
#ifndef DualMC33926Motor3Shield_h
#define DualMC33926Motor3Shield_h

#include <Arduino.h>

class DualMC33926Motor3Shield
{
	public:
		// CONSTRUCTORS
		 // Default pin selection.
		DualMC33926Motor3Shield();

		// PUBLIC METHODS
		void init(); // Initialize TIMER 1, set the PWM to 20kHZ.
		void setM1Speed(int speed); // Set speed for M1.
		void setM2Speed(int speed); // Set speed for M2.
		void setM3Speed(int speed);
		void setM4Speed(int speed);
		void setM5Speed(int speed);
		void setM6Speed(int speed);
		void setSpeeds(int m1Speed, int m2Speed, int M3Speed, int M4Speed, int M5Speed, int M6Speed); // Set speed for both M1 and M2.

		void setM1Brake(int brake);
		void setM2Brake(int brake);
		void setM3Brake(int brake);
		void setM4Brake(int brake);
		void setM5Brake(int brake);
		void setM6Brake(int brake);
		void setBrakes(int brakeM1, int brakeM2, int brakeM3, int brakeM4, int brakeM5, int brakeM6);
		//unsigned int getM1CurrentMilliamps(); // Get current reading for M1.
		//unsigned int getM2CurrentMilliamps(); // Get current reading for M2.
		//unsigned int getM3CurrentMilliamps(); // Get current reading for M3
		//unsigned int getM4CurrentMilliamps(); // Get current reading for M4
		//unsigned int getM5CurrentMilliamps(); // Get current reading for M5
		//unsigned int getM6CurrentMilliamps(); // Get current reading for M6

//		unsigned char getFault(); // Get fault reading.

	private:
		// for motor 1
		unsigned char _M1IN1;
		unsigned char _M1IN2;
		unsigned char _M1PWM_D2;
		unsigned char _M1_D1;
		unsigned char _M1SF;
		unsigned char _M1FB;

		// for motor 2
		unsigned char _M2IN1;
		unsigned char _M2IN2;
		unsigned char _M2PWM_D2;
		unsigned char _M2_D1;
		unsigned char _M2SF;
		unsigned char _M2FB;

		//for motor 3
		unsigned char _M3IN1;
		unsigned char _M3IN2;
		unsigned char _M3PWM_D2;
		unsigned char _M3_D1;
		unsigned char _M3SF;
		unsigned char _M3FB;

		//for motor 4
		unsigned char _M4IN1;
		unsigned char _M4IN2;
		unsigned char _M4PWM_D2;
		unsigned char _M4_D1;
		unsigned char _M4SF;
		unsigned char _M4FB;

		// for motor 5
		unsigned char _M5IN1;
		unsigned char _M5IN2;
		unsigned char _M5PWM_D2;
		unsigned char _M5_D1;
		//static const unsigned char _PWM2_TIMER1_PIN = 10;
		unsigned char _M5SF;
		unsigned char _M5FB;

		// for motor 6
		unsigned char _M6IN1;
		unsigned char _M6IN2;
		unsigned char _M6PWM_D2;
		unsigned char _M6_D1;
		//static const unsigned char _PWM2_TIMER1_PIN = 10;
		unsigned char _M6SF;
		unsigned char _M6FB;
}; //end of class
#endif
