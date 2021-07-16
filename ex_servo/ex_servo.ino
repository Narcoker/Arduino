#include <Servo.h>

#define SERVO_PIN 9

Servo myServo;
int pos = 0;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(90);
}

void loop() {
//  for(pos = 0; pos < 180; pos += 1){
//    myServo.write(pos);
//    delay(15);
//  }
//
//  for(pos = 180; pos>=1; pos -=1){
//    myServo.write(pos);
//    delay(15)
//  }

  myServo.write(0);
  delay(1000);
  
  myServo.write(90);
  delay(1000);
  
  myServo.write(180);
  delay(1000);

  myServo.write(90);
  delay(1000);


  
}
