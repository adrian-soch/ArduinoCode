#include <AccelStepper.h>
#include <Servo.h>

AccelStepper stepper1;
Servo servo1;

int laserPin = 13;
int xpotPin = A0; 
int ypotPin = A1; 
int bpotPin = 6; 
int xval=0; 
int yval=0; 
int bval=0; 
const int stepsPR = 200;

void setup() {
  pinMode(xpotPin,INPUT); 
  pinMode(ypotPin,INPUT); 
  pinMode(laserPin,OUTPUT);
  pinMode(bpotPin,INPUT_PULLUP); 
  servo1.attach(9);
  servo1.write (90);
  stepper1.setMaxSpeed(400.0);
}

void loop() {
  
  int stepSpeed = 0;
  
  xval = analogRead(xpotPin);
  yval = analogRead(ypotPin);
  bval = digitalRead(bpotPin);

  if(xval > 540){
    stepSpeed = map(xval,540,1024,10,700);
  }
  if (xval < 500) {
    stepSpeed = map(xval, 0, 500, -700, -10);
  }
  stepper1.setSpeed(stepSpeed);
  stepper1.run();

  servo1.write(map(yval,0,1024,0,180));   
  
  if (bval == LOW){
  digitalWrite(laserPin, HIGH);
  } else {
  digitalWrite(laserPin, LOW);
  }
}
