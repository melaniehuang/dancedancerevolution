/*Recieve serial response from Arduino sketch and display arrow on screen*/

import processing.serial.*;

Serial myPort;

void setup() {
  size(displayWidth, displayHeight);
  background(255);

  String danceMat = Serial.list()[2];
  myPort = new Serial(this, danceMat, 9600);
  myPort.bufferUntil('\n'); 

  noStroke();
  fill(200);
}

void draw() {
  if ( myPort.available() > 0) {  
    String val = myPort.readString();
    
    if (val != null) { 
      print(val.equals("H1"));
      
      if (val.equals("H1") == true) {
        background(#A0FA3A);
      } else if (val.equals("L1") == true) {
        background(0);
      } else if (val.equals("H2") == true) {
        background(#FA1E1E);
      } else if (val.equals("L2") == true) {
        background(0);
      } else {
        print("nothing here");
    }
  }
}