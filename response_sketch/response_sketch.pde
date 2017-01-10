/*Recieve serial response from Arduino sketch and display arrow on screen*/

import processing.serial.*;

Serial myPort;

void setup() {
  size(800, 600);
  background(255);

  String danceMat = Serial.list()[1];
  myPort = new Serial(this, danceMat, 9600);
  myPort.bufferUntil('\n'); 

  noStroke();
  fill(200);
  frameRate(60);
}

void draw() {
  if ( myPort.available() > 0) {  
    String val = myPort.readString();
    if (val != null) { 
      print(val);
      
      if (val.equals("H") == true) {
        background(#A0FA3A);
      } else if (val.equals("L") == true) {
        background(0);
      }
    } else {
      print("nothing here");
    }
  }
}