/*this is the arduino file for RASM JUST encoder reading
*
* Encoder Pin Connnection;
* Vin = 5V
* GND = ground
* Vout = Analog pin 0
* ** ensure that the Arduino and the encoder has the common ground
*/

unsigned char myEnc = A0;
int encRead = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(myEnc,INPUT);

  Serial.begin(9600);
  Serial.println("Program is running\n.\n.\n.\n.\nOKay, let's run\n");
} // end of setup function

void loop() {
  // put your main code here, to run repeatedly:
  encoderRead();
  delay(50);
} // end of loop function

// USER DEFINED FUNCTION
void encoderRead(){
  encRead = analogRead(myEnc);
  Serial.print("Encoder reading is: ");
  Serial.println(encRead);
}// end of encoderRead

