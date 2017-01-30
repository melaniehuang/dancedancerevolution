/*Recieve serial response from Arduino sketch and display arrow on screen*/

import processing.serial.*;
PImage uImage;
PImage dImage;
PImage lImage;
PImage rImage;
Serial myPort;

void setup() {
  size(500, 500);
  background(255);

  String danceMat = Serial.list()[2];
  myPort = new Serial(this, danceMat, 9600);
  myPort.bufferUntil('\n'); 
  
  uImage = loadImage("up.png");
  dImage = loadImage("down.png");
  lImage = loadImage("left.png");
  rImage = loadImage("right.png");
  
  noStroke();
  fill(200);
}

void draw() {
  if ( myPort.available() > 0) {  
    String val = myPort.readString();
    
    if (val != null) { 
      println(val);
      
      if (val.equals("U") == true) {
        background(#1E2AE8);
        image(uImage, width/2-100, height/2-100);
      } else if (val.equals("L") == true) {
        background(#FF8E1C);
        image(lImage, width/2-100, height/2-100);
      } else if (val.equals("R") == true) {
        background(#FFDA1C);
        image(rImage, width/2-100, height/2-100);
      } else if (val.equals("D") == true) {
        background(#12DE7D);
        image(dImage, width/2-100, height/2-100);
      } else {
        background(0);
    }
  }
 }
}