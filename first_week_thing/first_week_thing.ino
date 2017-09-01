
#include<Servo.h>

//declare all of my consts
const int topInput = 5; // top means the top wire thats cominng out of the switch
const int botInput =7; // the bottom one (the one that doesn't stay)
const int ledOut = 13;
const int servoOut = 16;

const int degPerAdvance = 10;

//the number of times the servo has been advanced
int timesAdvanced = 0;

//so it only advances once for everythrown switch
bool switchWasInMiddle = true;

Servo servo;


void setup() {
  // initialize serial communication at 9600 bits per second: so i can print ln
  Serial.begin(9600);

  //initalize pins
  pinMode(topInput, INPUT);
  pinMode(botInput, INPUT);
  pinMode(ledOut, OUTPUT);
  pinMode(servoOut, OUTPUT);
}


void loop() {
  if((digitalRead(topInput) == HIGH) && switchWasInMiddle == true){
    //runs the advance method
    Serial.println("Advancing");
    switchWasInMiddle = false;
    advance();
  }else if((digitalRead(botInput) == HIGH)&& switchWasInMiddle == true){
    //resets if switch is pushed up
    Serial.println("Reseting");
    switchWasInMiddle = false;
    reset();
  }else if( digitalRead(topInput) == LOW && digitalRead(botInput) == LOW){
    //if switch is in middle
    switchWasInMiddle = true;
  }
 
}
//this method runs when the switch is moved the the advance pos.
void advance(){
  timesAdvanced++;
  if(timesAdvanced>=(180/degPerAdvance)){
    timesAdvanced = -(180/degPerAdvance);
    Serial.println("Wrapping Around");
  }
  //moves the servo  
  servo.write(timesAdvanced*degPerAdvance);

  //blinkes the led the same number of times as abs(180/degPerAdvance) i think.  idk it just changes each time till 
  for(int i = 0; i<abs(timesAdvanced) ; i++){
    //this delay might be to fast idk.
    digitalWrite(ledOut,HIGH);
    delay(100);
    digitalWrite(ledOut,LOW);
    delay(100);
  }
}

//this method resets the servo.  the led is for a second or so.
void reset(){
  timesAdvanced = 0;
  digitalWrite(ledOut,HIGH);
  //reset servo below
  servo.write(0);
  delay (1000);
  digitalWrite(ledOut,LOW);
}

