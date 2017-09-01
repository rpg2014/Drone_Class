/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/
#include<Servo.h>

// digital pin 2 has a pushbutton attached to it. Give it a name:
const int topInput = 5;
const int botInput =7;
const int ledOut = 13;
const int servoOut = 15;
int timesAdvanced = 0;

Servo servo;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  pinMode(topInput, INPUT);
  pinMode(botInput, INPUT);
  pinMode(ledOut, OUTPUT);
  pinMode(servoOut, OUTPUT);
}


void loop() {
  if(digitalRead(topInput == HIGH){
    advance();
  }else if(digitalRead(botInput == HIGH){
    reset();
  }
 
}

void advance(){
  timesAdvanced++;
  servo.blah(timesAdvanced*10)
  for(int i = 0; i<timesAdvanced ; i++){
    digitalWrite(ledOut,HIGH);
    delay(200);
    digitalWrite(ledOut(LOW);
    delay(200);
  }
}
void reset(){
  timesAdvanced = 0;
  //reset servo
}

