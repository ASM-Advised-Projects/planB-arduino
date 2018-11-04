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
 #include "dualMC33926_motorDriver1.h";
 dualMC33926_motorDriver1 md;
  
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
    for(int i = 0; i<100 ; i++){
      md.setM1Speed(i);
      delay(50);
    }
    md.setM1Brake();
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc.
 void testMotor1(){ // for testing motor 1
  md.setM1Speed(400); // max value 400;
  delay(1000);
  md.setM1Brake(400);
 } // end of testing motor 1

  void testMotor2(){ //for testing motor 2
  md.setM2Speed(400); // max value 400;
  delay(1500);
  md.setM2Brake(400);
 } // end of testing motor 2
 */

