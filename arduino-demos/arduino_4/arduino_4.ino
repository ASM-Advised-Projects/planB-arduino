/****************************************************************
 *    Author Name: Far Zainal
 *    Date:   10/7/2018 
 *    Sketch Name: RASM_arduino wrist
 *    Sketch Description:  
 *                    
 *****************************************************************/
 
/****************************
 ** #defines and #includes **
 ****************************/ 
 #include "dualMC33926_motorDriver1.h"; 
 dualMC33926_motorDriver1 md;
 
/***********************
 ** Global Variables ***
 ***********************/
 char comm ='a'; //command to run == "r" 
 char c;
 int myEnc1; // the reading value of shoulder encoder
 int myEnc2; // the reading value of the elbow encoder
 int enc1 = A0; 
 int enc2 = A2;

 // variables for controls
 int desAngle_shoulder;
 int angleDes;
String inString = "";
  unsigned long t = micros();
/********************
 ** Setup Function **
 ********************/  
void setup(void){  
  // *** Configure Digital Pins & Attach Servos ***
      md.init(); // intialize the motors pin;
      pinMode(enc1, INPUT);
      pinMode(enc2, INPUT);
      
  // *** Initialize Serial Communication ***
     Serial.begin(9600);          
     
  // *** Take Initial Readings ***  
      Serial.println("Program is running");
      Serial.print("Command; \ns to run test motor 1\nw to run test motor 2\n");
      encoderRead(); // read the encoders initial value
      Serial.println("please enter r");
      while(comm!='r'){        
        comm = Serial.read();
        if(comm == 'r'){
          break;
        }
      }
      
      Serial.println();
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  
  readCommand();
  
  // for COMMAND 3; just encoder reading
   if(c == '3'){
    while(c == '3'){
      encoderRead();
      delay(50);
      c = Serial.read();
    }  
   }// end if c = 3;

   if(c == '4'){
    Serial.println("running c 4");
    int i = 0;
    while(i<50){
      md.setM1Speed(180);
      md.setM2Brake(400);
      encoderRead();
      i = i+ 1;
    }
    md.setM1Speed(0);
    c == '5';
    Serial.println("Done");
   }// end for c = 4
   delay(10);
   encoderRead();
     
 

} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/

 void testMotor1(){ // for testing motor 1
  md.setM1Speed(255); // max value 400;
  md.setM2Brake(400);
  delay(500);
  md.setM1Brake(400);
  delay(1000);
  md.setM1Speed(-255); // max value 400;
  md.setM2Brake(400);
  delay(500);
  md.setM1Brake(400);
  md.setM1Speed(0);
  delay(500);
 } // end of testing motor 1

  void testMotor2(){ //for testing motor 2
  md.setM2Speed(255); // max value 400;
  md.setM1Brake(400);
  delay(500);
  md.setM2Brake(400); // stop the motor
  delay(1000);
  md.setM2Speed(-255); // max value 400;
  md.setM1Brake(400);
  delay(500);
  md.setM2Speed(0); // stop the motor
  delay(500);
 } // end of testing motor 2

  void readCommand(){
    if(Serial.available() >0){
      c = Serial.read();
      Serial.flush();
    }
  } // end of read command

  void encoderRead(){
    myEnc1 = analogRead(enc1);
    myEnc2 = analogRead(enc2);
    Serial.print("Encoder 1: ");
    Serial.print(myEnc1);
    Serial.print("\tEncoder 2: ");
    Serial.println(myEnc2);
  } // end of encoder read

  void angleInput(){
    Serial.println("Please enter the desired angle: ");
      while (Serial.available() > 0) {
      int inChar = Serial.read();
      if (isDigit(inChar)) {
        // convert the incoming byte to a char and add it to the string:
        inString += (char)inChar;
      }
      // if you get a newline, print the string, then the string's value:
      if (inChar == '\n') {
        Serial.print("Angle entered:");
        angleDes = inString.toInt();
        Serial.println(angleDes);
        // clear the string for new input:
        inString = "";
      }
    }
} // end of angleInput();
