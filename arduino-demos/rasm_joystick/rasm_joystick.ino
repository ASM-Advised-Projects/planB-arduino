//****************** GLOBAL VARS **************//
unsigned char homeButton = 3;   // button for stage 0
unsigned char button1 = 4;      // button for stage 1
unsigned char button2 = 5 ;      // button for stage 2
unsigned char button3 = 6;      // button for stage 3
unsigned char led0 = 8;   // light indicator for homebutton
unsigned char led1 = 11;   // light indicator for stage 1
unsigned char led2 = 10;   // light indicator for stage 2
unsigned char led3 = 9;   // light indicator for stage 3
unsigned char xJoy = A0;  // analogPin for the joystick x-value
unsigned char yJoy = A1;  // analog pin for the joystick y-value
int stage = 0; // description for the stages are as follow;
      // stage = 0; home 
      // stage = 1; shoulder, elbow
      // stage = 2; linear act, yaw
      // stage = 3; pitch, roll
int xMiddle = 0;    // the analog reading value from 0 - 1023, this is when the value is in the middle
int yMiddle = 0;    // the analog reading value from 0 - 1023, this is when the value is the middle

/////////////////////////////////////////////
//****************** SETTUPP **************//
/////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  pinMode(homeButton, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(xJoy,INPUT);
  pinMode(yJoy,INPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  xMiddle = analogRead(xJoy);
  yMiddle = analogRead(yJoy);
  Serial.begin(9600);
  Serial.println("Program is starting soon... \n\n\n\n\n\n\n\n\n");
  Serial.println("***********************************************\n");
  delay(1000);
 } // end of setup function

/////////////////////////////////////////////
//****************** LOOOOOP **************//
/////////////////////////////////////////////
void loop() {
  //****************** STAGE 0 **************//
  while(stage == 0){
    readLevelButton();  
    ledStage0();
    stopAllMotors();    
  }// end stage = 0

  //****************** STAGE 1 **************//
  while(stage == 1){
    readLevelButton();
    ledStage1();
    int speed = 0;
    int xRead = analogRead(xJoy);
    int yRead = analogRead(yJoy);
    int xValJoy = abs(xRead - xMiddle);
    int yValJoy = abs(yRead - yMiddle);

    if(xValJoy > 300 && xValJoy > yValJoy){
      while(xRead > 600){
          speed = speed + 1;
          if(speed > 125){
            speed = 125;
          }
          Serial.print(speed);
          Serial.println("\tx positive"); 
          xRead = analogRead(xJoy);
          if(xRead < 600){
            while(speed > 0){
              speed = speed-10;
              if(speed <= 0){
                speed = 0;
              }
              Serial.print(speed); Serial.println(" stopping");
            }
          }
      }
      while(xRead < 400){
          speed = speed + 1;
          if(speed > 125){
            speed = 125;
          }
          Serial.print(speed);
          Serial.println("\tx negative"); 
          xRead = analogRead(xJoy);
          if(xRead > 400){
            while(speed > 0){
              speed = speed-10;
              if(speed <= 0){
                speed = 0;
              }
              Serial.print(speed); Serial.println(" stopping");
            }
          }
      }
      
    }else if(yValJoy > 300 && yValJoy > xValJoy){
      while(yRead > 600){
          speed = speed + 1;
          if(speed > 125){
            speed = 125;
          }
          Serial.print(speed);
          Serial.println("\ty positive"); 
          yRead = analogRead(yJoy);
      }
      while(yRead < 400){
          speed = speed + 1;
          if(speed > 125){
            speed = 125;
          }
          Serial.print(speed);
          Serial.println("\ty negative"); 
          yRead = analogRead(yJoy);
      }
    }   
  } // end stage = 1

  //****************** STAGE 2 **************//
  while(stage == 2){  
    readLevelButton();
    ledStage2();
    int xValJoy = analogRead(xJoy);
    int yValJoy = analogRead(yJoy);
    Serial.print("linear motor: ");
    Serial.print(xValJoy);
    Serial.print("\tyaw motor: ");
    Serial.println(yValJoy);  
  } // end stage = 2

  //****************** STAGE 3 **************//
  while(stage == 3){
    readLevelButton();
    ledStage3();
    int xValJoy = analogRead(xJoy);
    int yValJoy = analogRead(yJoy);
    Serial.print("roll motor: ");
    Serial.print(xValJoy);
    Serial.print("\tpitch motor: ");
    Serial.println(yValJoy);  
  } // end stage = 3
  
} // end of loop

//****************** USER DEFINED FUNCTION **************//
void readLevelButton(){
  int val = digitalRead(homeButton);
  if(val == 1){
    stage = 0;
    return;
  }
  int val1 = digitalRead(button1);
  if(val1 == 1){
    stage = 1;
    return;
  }
  int val2 = digitalRead(button2);
  if(val2 == 1){
    stage = 2;
    return;
  }
  int val3 = digitalRead(button3);
  if(val3 == 1){
    stage = 3;
    return;
  }
} // END OF readLevelButton; 

void ledStage0(){
    digitalWrite(led0, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW);
} // END of led stage 0

void ledStage1(){
    digitalWrite(led0, LOW);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
} // END of led stage 1

void ledStage2(){
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW); 
} // END of led stage 2

void ledStage3(){
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);   
} // END of led stage 3

void stopAllMotors(){
  // will have the digitalwrite for the motors
  /*md.setM1Speed(0);
  md.setM2Speed(0);
  md.setM3Speed(0);
  md.setM4Speed(0);
  md.setM5Speed(0);
  md.setM6Speed(0);
  */
}// END of stop all motors

