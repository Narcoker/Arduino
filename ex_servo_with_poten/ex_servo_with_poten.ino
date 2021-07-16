#include <Servo.h>

#define SERVO_PIN 9
#define POTEN_PIN A0

Servo myServo;
int val;

void setup() {
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(POTEN_PIN);
  Serial.print("변환 전: ");
  Serial.println(val);

  //가변저항 값 범위 변환하기
  val = map(val, 0, 1023, 0 , 180);
  Serial.print("변환 후: ");
  Serial.println(val);
  
  myServo.write(val);
}
