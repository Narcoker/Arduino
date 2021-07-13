//가변저항 제어 실습

#define POT_PIN A0

void setup() {
  // put your setup code here, to run once:
  pinMode(POT_PIN, INPUT); // 아날로그 입력기능으로 연결시 pinMode() 생략가능
  Serial.begin(9600);
}

void loop() {
  int pValue = analogRead(POT_PIN); // 아두이노는 10bit adc 이기 때문에 범위는 0~1023
  Serial.println(pValue);
}
