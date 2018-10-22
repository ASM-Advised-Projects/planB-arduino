/****************************************************************
 *    Author Name: Far Zainal
 *    Date:   10/7/2018 
 *    Sketch Name: RASM_arduino wrist
 *    Sketch Description:  
 *    
 *
 *    Pin Usage:      Pin type/number    Hardware 
 *                    ----------------   ----------------
 *                    
 *****************************************************************/
 
/****************************
 ** #defines and #includes **
 ****************************/ 
 #include "DualMC33926Motor3Shield.h";
 DualMC33926Motor3Shield md;

 
/***********************
 ** Global Variables ***
 ***********************/
// *** Declare & Initialize ANALOG Pins ***

// *** Declare & Initialize DIGITAL Pins ***
  
// *** Declare & Initialize Program Variables ***

  
/********************
 ** Setup Function **
 ********************/  
void setup(void){
  // PUT YOUR SETUP CODE HERE, TO RUN ONCE:

  // *** Configure Digital Pins & Attach Servos ***
      md.init(); // intialize the motors pin;

  // *** Initialize Serial Communication ***
     Serial.begin(9600);     
     Serial.println("Dual MC 339256 shields program is starting;");
     
  // *** Take Initial Readings ***  
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(void){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  int i = 0;
  /*while(i<4){
    if (i == 0){
      Serial.println("Testing shield 1, motor 1;");
      testMotor1();
    }
    if (i == 1){
      Serial.println("Testing shield 1, motor 2;");
      testMotor2();    
    }
    if (i == 2){
      Serial.println("Testing shield 2, motor 1;");
      testMotor3();
    }
    if (i == 3){
      Serial.println("Testing shield 2, motor 2;");
      testMotor4();
    }    
    if (i == 4){
      Serial.println("Testing shield 3, motor 1;");
      testMotor5();
    }
    delay(500);   
    i = i+1; // increment i step
  }
  Serial.println("program has ended");*/

  testMotor5();
  Serial.println("motor 1 is driving");
  delay(1000);  //delay 2 seconds
  testMotor6();
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc.
 void testMotor1(){ // for testing motor 1
  md.setM1Speed(400); // max value 400;
  delay(2000);
  md.setM1Speed(0);
  delay(1000);
  md.setM1Speed(-400); // max value 400;
  delay(2000);
  md.setM1Speed(0);
  delay(1000);
 } // end of testing motor 1

  void testMotor2(){ //for testing motor 2
  md.setM2Speed(255); // max value 400;
  delay(2000);
  md.setM2Speed(0); // stop the motor
  delay(1000);
  md.setM2Speed(-255); // max value 400;
  delay(2000);
  md.setM2Speed(0); // stop the motor
  delay(1000);
 } // end of testing motor 2

  void testMotor3(){ //for testing motor 3
  md.setM3Speed(400); // max value 400;
  delay(2000);
  md.setM3Speed(0);
  delay(1000);
  md.setM3Speed(-400); // max value 400;
  delay(2000);
  md.setM3Speed(0);
  delay(1000);
 } // end of testing motor 3

   void testMotor4(){ //for testing motor 4
  md.setM4Speed(400); // max value 400;
  delay(2000);
  md.setM4Speed(0); // stop the motor
  delay(1000);
  md.setM4Speed(-400); // max value 400;
  delay(2000);
  md.setM4Speed(0); // stop the motor
  delay(1000);
 } // end of testing motor 2

  void testMotor5(){ //for testing motor 5
  md.setM5Speed(400); // max value 400;
  delay(2000);
  md.setM5Speed(0); // stop the motor
  delay(1000);
  md.setM5Speed(-400); // max value 400;
  delay(2000);
  md.setM5Speed(0); // stop the motor
  delay(1000);
 } // end of testing motor 3

   void testMotor6(){ //for testing motor 5
  md.setM6Speed(400); // max value 400;
  delay(2000);
  md.setM6Speed(0); // stop the motor
  delay(1000);
  md.setM6Speed(-400); // max value 400;
  delay(2000);
  md.setM6Speed(0); // stop the motor
  delay(1000);
 } // end of testing motor 3

