//조도센서 측정 실습

#define LIGHT_PIN A0

void setup() {
  pinMode(LIGHT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  String tmp = "Light : ";

  tmp += analogRead(LIGHT_PIN);
  tmp += "LUX";
  Serial.println(tmp);
  delay(1000);
}
