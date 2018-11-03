#include <Arduino.h>    
    unsigned char _M1IN1;
    unsigned char _M1IN2;
    unsigned char _M1PWM_D2;
    unsigned char _D1;
    static const unsigned char _PWM1_TIMER1_PIN = 9;
    unsigned char _M1SF;
    unsigned char _M1FB;
    //unsigned char _EN1;
    unsigned char _encoder;
  
/********************
 ** Setup Function **
 ********************/  
void setup(void){
  // PUT YOUR SETUP CODE HERE, TO RUN ONCE:
  
    _M1IN1 = 2;
    _M1IN2 = 3;
    _M1PWM_D2 = 9;
    _D1 = 7;
    _M1SF = 12;
    _M1FB = A0;
    _encoder = A1;

  pinMode(_M1IN1, OUTPUT);
  pinMode(_M1IN2, OUTPUT);  
  pinMode(_M1PWM_D2, OUTPUT);
  pinMode(_M1SF, INPUT);
  pinMode(_M1FB, INPUT);
  pinMode(_D1, OUTPUT); digitalWrite(_D1, LOW);
  pinMode(_encoder, INPUT);

    //#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    //if (_M1PWM_D1 == _M1PWM_TIMER1_PIN)
    #if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
    {
      // Timer 1 configuration
      // prescaler: clockI/O / 1
      // outputs enabled
      // phase-correct PWM
      // top of 400
      //
      // PWM frequency calculation
      // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
      TCCR1A = 0b10100000;
      TCCR1B = 0b00010001;
      ICR1 = 400;
    Serial.println("timer is availble");
    }
    #endif
    
     Serial.begin(9600);     
     Serial.println("Dual MC 339256 shields program is starting;");
    
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(void){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  /*
  //testMotor1();
  Serial.println("motor 1 is driving");
  setM1aSpeed(200);
  Serial.println(analogRead(_encoder));
  delay(500);  //delay 2 seconds
  setM1aSpeed(0);
  Serial.println(analogRead(_encoder));
  Serial.println("motor 1 is stop");
  delay(2000);  //delay 2 seconds
  setM1aSpeed(-200);
  Serial.println(analogRead(_encoder));
  delay(500);  //delay 2 seconds
  setM1aSpeed(0);
  Serial.println("motor 1 is stop");
  Serial.println(analogRead(_encoder));
  delay(2000);  //delay 2 seconds*/
  Serial.println(analogRead(_encoder));
  delay(200);
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/

void setM1aSpeed(int speed){
  unsigned char reverse = 0;
  if (speed < 0)  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
    Serial.println ("reverse speed is set");
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;

  /*//newer version
  #if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
    OCR1A = speed;
  #else
    analogWrite(_M1PWM_D1, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
  #endif
  
 /* #ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    if (_M1PWM_D1 == _M1PWM_TIMER1_PIN)
    {
      OCR1A = speed;
    }
    else
    {
      digitalWrite(_D2,LOW);
      digitalWrite(_M1PWM_D1,speed); // map 400 to 255
      
    }
  #else
    digitalWrite(_D2,LOW);
    digitalWrite(_M1PWM_D1,speed); // map 400 to 255
  #endif*/
  
  digitalWrite(_M1PWM_D2,speed); // map 400 to 255
  
  if (reverse){
  digitalWrite(_M1IN1, LOW);
  digitalWrite(_M1IN2, HIGH);
  Serial.println("reverse direction is set");
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
