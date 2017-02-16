#include <Keyboard.h>

/* Testing dance machine buttons to communicate to Processing via keystrokes */

const int buttonPin0 = 0;
const int buttonPin1 = 1;     // the number of the pushbutton pin
const int buttonPin2 = 2;
const int buttonPin3 = 3;
const int buttonPin4 = 4;
const int buttonPin5 = 5;     // the number of the pushbutton pin
const int buttonPin6 = 6;
const int buttonPin7 = 7;
const int ledPin =  13;      // the number of the LED pin
int buttonState0 = LOW; 
int buttonState1 = LOW;         
int buttonState2 = LOW;
int buttonState3 = LOW;
int buttonState4 = LOW; 
int buttonState5 = LOW;         
int buttonState6 = LOW;
int buttonState7 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
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
  
  
  if (buttonState0 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write(KEY_UP_ARROW);
    Serial.write("U");
  } else if (buttonState0 == LOW) {
    digitalWrite(ledPin, LOW);
  }
  
  if (buttonState1 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write(KEY_RIGHT_ARROW);
    Serial.write("R");
  } else if (buttonState1 == LOW) {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState2 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write(KEY_DOWN_ARROW);
    Serial.write("D");
  } else if (buttonState2 == LOW)   {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState3 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("L");
    Keyboard.write(KEY_LEFT_ARROW);
  } else if (buttonState3 == LOW)   {
    digitalWrite(ledPin, LOW);
  } 

  if (buttonState4 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write('W');
    Serial.write("U2");
  } else if (buttonState4 == LOW) {
    digitalWrite(ledPin, LOW);
  }
  
  if (buttonState5 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write('D');
    Serial.write("R2");
  } else if (buttonState5 == LOW) {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState6 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write('S');
    Serial.write("D2");
  } else if (buttonState6 == LOW)   {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState7 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Keyboard.write('A');
    Serial.write("L2");
  } else if (buttonState7 == LOW)   {
    digitalWrite(ledPin, LOW);
  } 
  
  delay(100);
}

