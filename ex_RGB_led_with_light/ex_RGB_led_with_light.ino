#define BLUE_PIN 11
#define Green_PIN 10
#define RED_PIN 9
#define LIGHT_PIN A0

void setup() {
  pinMode(BLUE_PIN, INPUT);
  pinMode(Green_PIN, INPUT);
  pinMode(RED_PIN, INPUT);

  pinMode(LIGHT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(LIGHT_PIN);
  Serial.println(value);

  if(value > 900)
    controlRGBLED(HIGH, LOW, LOW);

  else if(value > 600)
    controlRGBLED(LOW, HIGH, LOW);
  
  else
    controlRGBLED(LOW, LOW, HIGH);
 
  delay(1000);
   
}

//RGBLED 제어함수
void controlRGBLED(int r, int g, int b){
  digitalWrite(RED_PIN, r);
  digitalWrite(Green_PIN, g);
  digitalWrite(BLUE_PIN, b);
}
