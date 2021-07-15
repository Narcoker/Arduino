//블루투스 통신으로 APP 제어 실습

#include <SoftwareSerial.h>

//센서 연결 핀 및 전역변수 선언
#include<DHT.h>

#define RX_PIN 2
#define TX_PIN 3
#define LED_PIN 7
#define CDS_PIN A0
#define DHT_PIN 4

//객체 변수 선언
SoftwareSerial bt(RX_PIN, TX_PIN);
DHT myDHT(DHT_PIN, DHT11);

unsigned long preMillis = 0; // 타이머 기준 시간

// 초기화 함수
void setup() {
  //시리언 통신, 블루투스 통신 초기화
  Serial.begin(9600);
  bt.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(CDS_PIN, INPUT);
  myDHT.begin();
  
  Serial.println("--- Setup OK ---");
}

// 기능 구현 함수
void loop() {
  // 블루투스 통신으로 수신한 데이터 처리

  //LED 제어
  if(bt.available() > 0) //블루투스 통신으로 받아온 값이 있으면
  {
    //수신 데이터 읽어서 출력하기
    int rxData=bt.read();
    digitalWrite(LED_PIN,rxData);
  }

  //조도 센서,온습도 센서 값 어플로 송신
  if(millis() - preMillis >= 1000)
  {
    int CDS = analogRead(CDS_PIN); // 조도
    int temp = myDHT.readTemperature(); // 습도
    int humi = myDHT.readHumidity(); // 온도

    String msg = "";
    msg += CDS; 
    msg += "|";
    msg += temp;
    msg += "|";
    msg += humi;   
    
    bt.print(msg);
    
    preMillis = millis();
  }

  //온습도 센서 값 확인

  

}
