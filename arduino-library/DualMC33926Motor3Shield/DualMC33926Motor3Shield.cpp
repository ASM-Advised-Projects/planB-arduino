/* This is the motor shield library that will be used on RASM. The library is for Pololu Dual MC 33926 motor shield. The RASM will use 3 motor shields, that will connect to 5 DC motors*/

// include DualMC33926 header file
//#include "Arduino.h"
#include "DualMC33926Motor3Shield.h"


// Constructors ////////////////////////////////////////////////////////////////

// default pins for the library, and for the time being this library only supports default pins connections
DualMC33926Motor3Shield::DualMC33926Motor3Shield()
{
  //Default Pin Map for motor shield 1
  _M1IN1 = 30;
  _M1IN2 = 31;
  _M1PWM_D2 = 4;
  _M1_D1 = 34;
//  _M1SF = ;	// optional if wants to read status flag
//  _M1FB = ;	// optional if wants to read current
  // EN pin is connected to the 5V supply
  _M2IN1 = 32;
  _M2IN2 = 33;
  _M2PWM_D2 = 5;
  _M2_D1 = 35;
//  _M2SF = ;	// optional if wants to read status flag
//  _M2FB = ;	// optional if wants to read current

  //Default Pin map for motor shield 2
  _M3IN1 = 36;
  _M3IN2 = 37;
  _M3PWM_D2 = 6;
  _M3_D1 = 40;
//  _M3SF = ;	// optional if wants to read status flag
//  _M3FB = ;	// optional if wants to read current
  // EN pin is connected to the 5V supply
  _M4IN1 = 38;
  _M4IN2 = 39;
  _M4PWM_D2 = 7;
  _M4_D1 = 41;
//  _M4SF = ;	// optional if wants to read status flag
//  _M4FB = ;	// optional if wants to read current

  //Default Pin map for motor shield 3
  _M5IN1 = 42;
  _M5IN2 = 43;
  _M5PWM_D2 = 8;
  _M5_D1 = 46;
  //_M5SF = ;	// optional if wants to read status flag
  //_M5FB = ;	// optional if wants to read current
  // EN pin is connected to the 5V supply
  _M6IN1 = 44;
  _M6IN2 = 45;
  _M6PWM_D2 = 9;
  _M6_D1 = 47;
  //_M6SF = ;	// optional if wants to read status flag
  //_M6FB = ;	// optional if wants to read current

}

// Public Methods //////////////////////////////////////////////////////////////
void DualMC33926Motor3Shield::init()
{
// Define pinMode for the pins and set the frequency for timer1.
	// intialization for motor shield 1
  pinMode(_M1IN1, OUTPUT);
  pinMode(_M1IN2, OUTPUT);
  pinMode(_M1PWM_D2, OUTPUT);
  pinMode(_M1_D1, OUTPUT); digitalWrite(_M1_D1, LOW);
//  pinMode(_M1SF, INPUT);
//  pinMode(_M1FB, INPUT);

  pinMode(_M2IN1, OUTPUT);
  pinMode(_M2IN2, OUTPUT);
  pinMode(_M2PWM_D2, OUTPUT);
  pinMode(_M2_D1, OUTPUT); digitalWrite(_M2_D1, LOW);
//  pinMode(_M2SF, INPUT);
//  pinMode(_M2FB, INPUT);

// intialization for motor shield 2
pinMode(_M3IN1, OUTPUT);
pinMode(_M3IN2, OUTPUT);
pinMode(_M3PWM_D2, OUTPUT);
pinMode(_M3_D1, OUTPUT); digitalWrite(_M3_D1, LOW);
//  pinMode(_M3SF, INPUT);
//  pinMode(_M3FB, INPUT);

pinMode(_M4IN1, OUTPUT);
pinMode(_M4IN2, OUTPUT);
pinMode(_M4PWM_D2, OUTPUT);
pinMode(_M4_D1, OUTPUT); digitalWrite(_M4_D1, LOW);
//  pinMode(_M4SF, INPUT);
//  pinMode(_M4FB, INPUT);

// intialization for motor shield 3
pinMode(_M5IN1, OUTPUT);
pinMode(_M5IN2, OUTPUT);
pinMode(_M5PWM_D2, OUTPUT);
pinMode(_M5_D1, OUTPUT); digitalWrite(_M5_D1, LOW);
//  pinMode(_M5SF, INPUT);
//  pinMode(_M5FB, INPUT);

pinMode(_M6IN1, OUTPUT);
pinMode(_M6IN2, OUTPUT);
pinMode(_M6PWM_D2, OUTPUT);
pinMode(_M6_D1, OUTPUT); digitalWrite(_M6_D1, LOW);
//  pinMode(_M6SF, INPUT);
//  pinMode(_M6FB, INPUT);

} // end of public methods

/***** Setting up the speed for each motors *****/
// Set speed for motor 1, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM1Speed(int speed)
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
void DualMC33926Motor3Shield::setM2Speed(int speed)
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
}//end for setM2Speed

// Set speed for motor 3, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM3Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;

  digitalWrite(_M3PWM_D2, speed);

	if (reverse) {
		digitalWrite(_M3IN1, LOW);
		digitalWrite(_M3IN2, HIGH);
	}

	else if (speed == 0) {
		digitalWrite(_M3IN1, LOW);
		digitalWrite(_M3IN2, LOW);
	}
	else {
		digitalWrite(_M3IN1, HIGH);
		digitalWrite(_M3IN2, LOW);
	}
}//end for setM3peed

// Set speed for motor 4, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM4Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;

  digitalWrite(_M4PWM_D2, speed);

	if (reverse) {
		digitalWrite(_M4IN1, LOW);
		digitalWrite(_M4IN2, HIGH);
	}

	else if (speed == 0) {
		digitalWrite(_M4IN1, LOW);
		digitalWrite(_M4IN2, LOW);
	}
	else {
		digitalWrite(_M4IN1, HIGH);
		digitalWrite(_M4IN2, LOW);
	}
}//end for setM4peed

// Set speed for motor 5, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM5Speed(int speed)
{
	unsigned char reverse = 0;
	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;

  digitalWrite(_M5PWM_D2, speed);

	if (reverse) {
		digitalWrite(_M5IN1, LOW);
		digitalWrite(_M5IN2, HIGH);
	}

	else if (speed == 0) {
		digitalWrite(_M5IN1, LOW);
		digitalWrite(_M5IN2, LOW);
	}
	else {
		digitalWrite(_M5IN1, HIGH);
		digitalWrite(_M5IN2, LOW);
	}
}//end for setM5speed

// Set speed for motor 6, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM6Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;

  digitalWrite(_M6PWM_D2, speed);

	if (reverse) {
		digitalWrite(_M6IN1, LOW);
		digitalWrite(_M6IN2, HIGH);
	}

	else if (speed == 0) {
		digitalWrite(_M6IN1, LOW);
		digitalWrite(_M6IN2, LOW);
	}
	else {
		digitalWrite(_M6IN1, HIGH);
		digitalWrite(_M6IN2, LOW);
	}
}//end for setM6speed

/////////////
// Set speed for motor 1, 2, 3, 4, 5, and 6
void DualMC33926Motor3Shield::setSpeeds(int m1Speed, int m2Speed, int m3Speed, int m4Speed, int m5Speed, int m6Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
  setM3Speed(m3Speed);
  setM4Speed(m4Speed);
  setM5Speed(m5Speed);
  setM6Speed(m6Speed);
} //end of set speeds

// ******* END OF SETTING SPEEDS ******* //
