// the cpp file for dual MC33926 motor driver that only two motors, motor 1 and motor 2
// include DualMC33926 header file
#include "dualMC33926_motorDriver1.h"


// Constructors ////////////////////////////////////////////////////////////////

// default pins for the library, and for the time being this library only supports default pins connections
dualMC33926_motorDriver1::dualMC33926_motorDriver1()
{
  // DEFAULT PIN MAP FOR MOTOR SHIELD 1
  _M1IN1 = 2;
  _M1IN2 = 3;
  _M1PWM_D2 = 9;
  _M1_D1 = 7;
  _M1SF = 12;	// optional if wants to read status flag
  _M1FB = A0;	// optional if wants to read current
  // EN pin is connected to the 5V supply
  _M2IN1 = 4;
  _M2IN2 = 5;
  _M2PWM_D2 = 10;
  _M2_D1 = 8;
  _M2SF = 11;	// optional if wants to read status flag
  _M2FB = A1;	// optional if wants to read current
}

// Public Methods //////////////////////////////////////////////////////////////
void dualMC33926_motorDriver1::init()
{
// Define pinMode for the pins and set the frequency for timer1.
	// intialization for motor shield 1
  pinMode(_M1IN1, OUTPUT);
  pinMode(_M1IN2, OUTPUT);
  pinMode(_M1PWM_D2, OUTPUT);
  pinMode(_M1_D1, OUTPUT); digitalWrite(_M1_D1, LOW);
  pinMode(_M1SF, INPUT);
  pinMode(_M1FB, INPUT);

  pinMode(_M2IN1, OUTPUT);
  pinMode(_M2IN2, OUTPUT);
  pinMode(_M2PWM_D2, OUTPUT);
  pinMode(_M2_D1, OUTPUT); digitalWrite(_M2_D1, LOW);
  pinMode(_M2SF, INPUT);
  pinMode(_M2FB, INPUT);
} // end of public methods


/***** Setting up the speed for each motors *****/
// Set speed for motor 1, speed is a number betwenn -400 and 400
void dualMC33926_motorDriver1::setM1Speed(int speed)
{
  unsigned char reverse = 0;

  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;

  digitalWrite(_M1PWM_D2, speed);

  if (reverse){
	digitalWrite(_M1IN1, LOW);
	digitalWrite(_M1IN2, HIGH);
  }

  else if(speed == 0){
	  digitalWrite(_M1IN1, LOW);
	  digitalWrite(_M1IN2, LOW);
  }
  else{
    digitalWrite(_M1IN1, HIGH);
	digitalWrite(_M1IN2, LOW);
  }
} // end of setM1Speed

// Set speed for motor 2, speed is a number betwenn -400 and 400
void dualMC33926_motorDriver1::setM2Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;

	digitalWrite(_M2PWM_D2, speed);

	if (reverse) {
		digitalWrite(_M2IN1, LOW);
		digitalWrite(_M2IN2, HIGH);
	}

	else if (speed == 0) {
		digitalWrite(_M2IN1, LOW);
		digitalWrite(_M2IN2, LOW);
	}
	else {
		digitalWrite(_M2IN1, HIGH);
		digitalWrite(_M2IN2, LOW);
	}
} // end of setM2Speed

void dualMC33926_motorDriver1::setSpeeds(int speedM1, int speedM2) {
	setM1Speed(speedM1);
	setM2Speed(speedM2);
} // end of setting motor speeds

// ************** END OF SETTING MOTOR SPEED ************** //

// ************** SETTING MOTOR BRAKE ************** //
void dualMC33926_motorDriver1::setM1Brake(int brake) {
	// normalize brake
	if (brake < 0)
	{
		brake = -brake;
	}
	if (brake > 400)  // Max brake
		brake = 400;
	digitalWrite(_M1IN1, LOW);
	digitalWrite(_M1IN2, LOW);
	digitalWrite(_M1PWM_D2, brake);
} // end of setting brake for motor 1

void dualMC33926_motorDriver1::setM2Brake(int brake) {
	// normalize brake
	if (brake < 0)
	{
		brake = -brake;
	}
	if (brake > 400)  // Max brake
		brake = 400;
	digitalWrite(_M2IN1, LOW);
	digitalWrite(_M2IN2, LOW);
	digitalWrite(_M2PWM_D2, brake);
} // end of setting brake for motor 2

void dualMC33926_motorDriver1::setBrakes(int brake1,int brake2) {
	setM1Brake(brake1);
	setM2Brake(brake2);
} // end setting brake for both motors
// ************** END OF SETTING MOTOR BRAKE ************** //
// ************** END OF SETTING MOTOR BRAKE ************** //
