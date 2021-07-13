//조도센서 측정 실습

#define CDS_PIN A0

void setup() {
  pinMode(CDS_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(CDS_PIN);
  Serial.println(value);
}
