#define INA 11
#define INB 10

void setup() {
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
//  digitalWrite(INA, HIGH);
//  digitalWrite(INB, LOW);
  for(int i=0; i<=255; i++){
    analogWrite(INA, i);
    analogWrite(INB, 255-i);
    
    Serial.println(i);
    delay(10);
    
  }

//  for(int i=255; i=0; i--){
//    analogWrite(INA, i);
//    Serial.println(i);
//    delay(10);
//  }
  
}
