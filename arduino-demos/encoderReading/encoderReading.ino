/*this is the arduino file for RASM JUST encoder reading
*
* Encoder Pin Connnection;
* Vin = 5V
* GND = ground
* Vout = Analog pin 0
* ** ensure that the Arduino and the encoder has the common ground
*/

unsigned char myEnc = A0;
unsigned char myEnc2 = A1;
int encRead = 0;
int encRead2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(myEnc,INPUT);
  pinMode(myEnc2, INPUT);
  Serial.begin(9600);
  Serial.println("Program is running\n.\n.\n.\n.\nOKay, let's run\n");
} // end of setup function

void loop() {
  // put your main code here, to run repeatedly:
  encoderRead();
  encoder2Read();
  delay(50);
} // end of loop function

// USER DEFINED FUNCTION
void encoderRead(){
  encRead = analogRead(myEnc);
  Serial.print("Encoder reading is: ");
  Serial.print(encRead);
}// end of encoderRead

void encoder2Read(){
  encRead2 = analogRead(myEnc2);
  Serial.print("\tEncoder 2 reading is: ");
  Serial.println(encRead2);
}// end of encoderRead
