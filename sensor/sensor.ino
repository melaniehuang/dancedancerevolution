/* Testing dance machine buttons to communicate to Processing */

const int buttonPin1 = 3;     // the number of the pushbutton pin
const int buttonPin2 = 4;
const int buttonPin3 = 5;
const int ledPin =  13;      // the number of the LED pin
int buttonState1 = LOW;         // variable for reading the pushbutton status
int buttonState2 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);

  if (buttonState1 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("1");
  } else if (buttonState1 == LOW) {
    digitalWrite(ledPin, LOW);
    Serial.write("0");
  }

  if (buttonState2 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("2");
  } else if (buttonState2 == LOW)   {
    digitalWrite(ledPin, LOW);
    Serial.write("0");
  }

  if (buttonState3 == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.write("3");
  } else if (buttonState3 == LOW)   {
    digitalWrite(ledPin, LOW);
    Serial.write("0");
  }
  
  delay(100);
}

