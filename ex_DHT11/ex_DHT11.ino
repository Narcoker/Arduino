//디지털 온습도 센서 제어 => 라이브러리 사용

// 센서 라이브러리 포함하기
#include "DHT.h" 

//센서 관련 전역변수 선언하기
#define DHT_PIN 4 
#define DHTTYPE DHT11

//센서 객체 변수 선언하기
DHT dht(DHT_PIN, DHTTYPE);

//초기화 함수
void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  dht.begin(); // 센서 객체 초기화
}

//기능 구현
void loop() {
  delay(2000); //지정된 밀리세컨드 만큼 일시정지

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //출력 문자열 생성
  String msg = "Temp: ";
  msg += t;
  msg += " C";
  msg += " HUM : ";
  msg += h;
  msg +=" %";

  Serial.println(msg);
}
