#include <SoftwareSerial.h>

#define RXD_PIN 2
#define TXD_PIN 3

SoftwareSerial bt(RXD_PIN, TXD_PIN);
char data;

void setup() 
{
  Serial.begin(9600);
  bt.begin(9600);

  Serial.println("Ready.....");
}

void loop() 
{
  Serial.flush();
  Serial.print("CMD : ");

  while(!Serial.available()); // 아두이노가 데이터를 수신할때 까지 대기

  while(Serial.available()) // 아두이노 시리얼 RX핀으로 수신된 데이터를 블루투스 모듈로 전송
  {
    data = Serial.read();
    if(data == -1) break;

    bt.print(data);
    Serial.print(data);
    delay(1);
  }
  Serial.println();
  delay(1000); // 블루투스 모듈이 커맨드를 처리할 시간 지연
  Serial.print("Return : ");

  while(bt.available()) //블루투스 모듈의 RX핀으로 수신된 데이터를 아두이노로 전송
  {
    data = bt.read();
    if(data == -1) break;

    Serial.print(data);
    delay(1);
  }
  Serial.println("\n\n");
}
