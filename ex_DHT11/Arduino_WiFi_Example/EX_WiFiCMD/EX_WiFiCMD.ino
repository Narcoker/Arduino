/* ---------------------------------------------------------------------------
 *  사용하는 AP공유기의 SSID, PASSWORD로 변경하여 실습
 *  AT+CWJAP=\"사용 AP공유기 SSID\",\"사용 AP공유기 PASSWORD\" 
 *  
 *  ESP-01S WiFi 모듈 설정 예제로 딱 1번만 실행
 * --------------------------------------------------------------------------*/
#include <SoftwareSerial.h>

//- 전역 상수 선언 --------------------------------------------------------------
#define LEN           8    //- AT Command 개수
#define RXD_PIN       2
#define TXD_PIN       3


//- 객체 상수 선언 --------------------------------------------------------------
SoftwareSerial wifi(RXD_PIN, TXD_PIN);  


//- 전역 변수 선언 --------------------------------------------------------------
//- AT command 배열 
String  arrCMD[]    = { "AT+RST", "AT+GMR", "AT+CWMODE=1",
                        "AT+CWLAP",
                        "AT+CWJAP=\"Narcoker\",\"1234qwer\"",
                        "AT+CIFSR", "AT+CWQAP", 
                        "AT+UART_DEF=9600,8,1,0,0" };
//- 초기화 ------------------------------------------------------------------------
void setup()
{
    Serial.begin(115200);          // 아두이노 <-> PC
    
    wifi.begin(115200);            // 아두이노 <-> ESP-01S WiFi
    wifi.setTimeout(5000);
    
    Serial.println("Start WiFi Command Mode");
  
    String szTmp ="";
    for(int idx=0; idx<LEN; idx++)
    {
        Serial.print("CMD : ");  
        Serial.println(arrCMD[idx]);  
        wifi.println(arrCMD[idx]);      
  
        while(!wifi.available());
  
        while(wifi.available())
        {
             szTmp = wifi.readString();   
             Serial.print("ANS : ");  
             Serial.println(szTmp );
        }
    }
 }

//- 기능 구현 함수 -------------------------------------------------------------
void loop(){ }
