/* Testing dance machine buttons to communicate to Processing */
const int buttonPin0 = 2;
const int buttonPin1 = 3;     // the number of the pushbutton pin
const int buttonPin2 = 4;
const int buttonPin3 = 5;
const int ledPin =  13;      // the number of the LED pin
int buttonState0 = LOW; 
int buttonState1 = LOW;         // variable for reading the pushbutton status
int buttonState2 = LOW;
int buttonState3 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin0, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  
  if (buttonState0 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("U");
  } else if (buttonState0 == LOW) {
    digitalWrite(ledPin, LOW);
  }
  
  if (buttonState1 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("D");
  } else if (buttonState1 == LOW) {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState2 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("R");
  } else if (buttonState2 == LOW)   {
    digitalWrite(ledPin, LOW);
  }

  if (buttonState3 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("L");
  } else if (buttonState3 == LOW)   {
    digitalWrite(ledPin, LOW);
  } 
  
  delay(100);
}

