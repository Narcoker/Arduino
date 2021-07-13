//인체 감지센서(PIR) 실습 : 감지시 내장 led 점등
#define PIR_PIN 7 
#define LED 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(PIR_PIN);
  Serial.print("PIR Value : ");
  Serial.println(value);
  
//  if (value == 0)digitalWrite(LED, LOW);
//  else digitalWrite(LED, HIGH); 
  digitalWrite(LED, value);
}
