//PWM으로 LED 밝기 조절

// 센서 연결 핀 선언
#define LED_PIN 9 // PWM기능


void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // LED 밝기 조절
  for(int value=0; value<=255; value++){
    analogWrite(LED_PIN, value);
    delay(10);
  }
  for(int value=255; value>=0; value--){
    analogWrite(LED_PIN, value);
    delay(10);
  }
}
