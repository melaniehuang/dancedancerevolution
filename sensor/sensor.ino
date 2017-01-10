/* Testing dance machine buttons to communicate to Processing */

const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println("H");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println("L");
  }

  delay(200);
}
