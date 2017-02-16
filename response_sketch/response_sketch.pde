/*Recieve serial response from Arduino sketch and display arrow on screen*/

import processing.serial.*;
PImage uImage;
PImage dImage;
PImage lImage;
PImage rImage;
Serial myPort;

void setup() {
  size(displayWidth, displayHeight);
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
  if (keyPressed) {
    if (key == 'w' || key == 'W') {
      background(#F23F1B);
      image(uImage, width/2-100, height/2-100);
    } else if (key == 'd' || key == 'D') {
      background(#F23F1B);
      image(rImage, width/2-100, height/2-100);
    } else if (key == 's' || key == 'S') {
      background(#F23F1B);
      image(dImage, width/2-100, height/2-100);
    } else if (key == 'a' || key == 'A') {
      background(#F23F1B);
      image(lImage, width/2-100, height/2-100);
    } else if (key == CODED) {
      background(#1AEAFF);
      if (keyCode == UP) { 
        image(uImage, width/2-100, height/2-100);
      } else if (keyCode == LEFT) {
        image(lImage, width/2-100, height/2-100);
      } else if (keyCode == RIGHT) {
        image(rImage, width/2-100, height/2-100);
      } else if (keyCode == DOWN) {
        image(dImage, width/2-100, height/2-100);
      }
    } else {
      background(0);
    }
  }
}