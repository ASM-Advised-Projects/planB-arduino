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
    //_M1PWM_D2 to 5V;
    //_D1 to GND;
    //_M1SF ; no connection;
    //_M1FB ; no connection
    //_encoder = A1;

      pinMode(_M1IN1, OUTPUT);
      pinMode(_M1IN2, OUTPUT);     
     Serial.begin(9600);     
     Serial.println("Dual MC 339256 shields program is starting;");
    
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(void){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  int i = 0;
 while(i<255){
   setM1aSpeed(i);
   delay(100);
   i++;
 }
 setM1aSpeed(0);
 Serial.println("stopped");
 delay(1000);
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/

void setM1aSpeed(int sp){
  unsigned char reverse = 0;
  if (sp < 0)  {
    sp = -sp;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
    Serial.println ("reverse speed is set");
  }
  if (sp > 400)  // Max PWM dutycycle
    sp = 400;
      
  if (reverse){
  digitalWrite(_M1IN1, LOW);
  analogWrite(_M1IN2, sp);
  Serial.println("reverse direction is set");
  }
    
  else if(sp == 0){
    digitalWrite(_M1IN1, LOW);
    digitalWrite(_M1IN2, LOW);
  }
  else{
    analogWrite(_M1IN1, sp);
    digitalWrite(_M1IN2, LOW);

  }
} // end of setM1Speed
