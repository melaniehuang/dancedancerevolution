#include <Keyboard.h>

/* Testing dance machine buttons to communicate to Processing via keystrokes 
Default Stepmania keys
Up, Right, Down, Left, Select, SelectRight, SelectLeft

Player 1
KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, ENTER, KEY_RIGHT_ARROW, KEY_LEFT_ARROW
Player 2
NUM8, NUM6, NUM2, NUM4, ENTER, NUM6, NUM4
*/

boolean twoPlayers = true;

const int buttonPin0 = 0;
const int buttonPin1 = 1;     // the number of the pushbutton pin
const int buttonPin2 = 2;
const int buttonPin3 = 3;

const int buttonPin4 = 4;
const int buttonPin5 = 5;     
const int buttonPin6 = 6;
const int buttonPin7 = 7;

const int blueSelect = A4;     // blue buttons
const int blueRight = A3;
const int blueLeft = A5;

const int redSelect = A1;     // red buttons
const int redRight = A0;
const int redLeft = A2;

const int ledPin =  13;      // the number of the LED pin
int buttonState0 = LOW; 
int buttonState1 = LOW;         
int buttonState2 = LOW;
int buttonState3 = LOW;
int buttonState4 = LOW; 
int buttonState5 = LOW;         
int buttonState6 = LOW;
int buttonState7 = LOW;

int blueSelectState = LOW; 
int blueRightState = LOW;         
int blueLeftState = LOW;

int redSelectState = LOW; 
int redRightState = LOW;         
int redLeftState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, LED_BUILTIN);
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  
  pinMode(blueSelect, INPUT_PULLUP);
  pinMode(blueRight, INPUT_PULLUP);
  pinMode(blueLeft, INPUT_PULLUP);
  pinMode(redSelect, INPUT_PULLUP);
  pinMode(redRight, INPUT_PULLUP);
  pinMode(redLeft, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  
  blueSelectState = digitalRead(blueSelect);
  blueRightState = digitalRead(blueRight);
  blueLeftState = digitalRead(blueLeft);
  
  redSelectState = digitalRead(redSelect);
  redRightState = digitalRead(redRight);
  redLeftState = digitalRead(redLeft);

  //If you don't have two prongs on your microswitch you may have to swap the low and high for the ledPin
  
  if (redSelectState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("1");
  } else if (redRightState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("0");
  } else if (redLeftState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("2");    
  } else if (blueSelectState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("4");
  } else if (blueRightState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("3");
  } else if (blueLeftState == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.write("5");
  } else {
    digitalWrite(ledPin, LOW); 
  }
  
  if (buttonState0 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write(KEY_UP_ARROW);
    Serial.write("U");
  } else if (buttonState1 == HIGH) {
    digitalWrite(ledPin, HIGH);
//    Keyboard.write(KEY_RIGHT_ARROW);
    Serial.write("R");
  } else if (buttonState2 == HIGH) {
    digitalWrite(ledPin, HIGH);
//    Keyboard.write(KEY_DOWN_ARROW);
    Serial.write("D");
  } else if (buttonState3 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("L");
//    Keyboard.write(KEY_LEFT_ARROW);
  } else {
    digitalWrite(ledPin, LOW);
  } 

  if (twoPlayers == true) {
     if (buttonState4 == HIGH) {
       digitalWrite(ledPin, HIGH);
  //   Keyboard.write(KEY_UP_ARROW);
       Serial.write("U2");
     } else if (buttonState5 == HIGH) {
       digitalWrite(ledPin, HIGH);
  //   Keyboard.write(KEY_RIGHT_ARROW);
       Serial.write("R2");
     } else if (buttonState6 == HIGH) {
       digitalWrite(ledPin, HIGH);
  //   Keyboard.write(KEY_DOWN_ARROW);
       Serial.write("D2");
     } else if (buttonState7 == HIGH) {
       digitalWrite(ledPin, HIGH);
       Serial.write("L2");
  //   Keyboard.write(KEY_LEFT_ARROW);
     } else {
       digitalWrite(ledPin, LOW);
     } 
  }


  delay(100);
}

