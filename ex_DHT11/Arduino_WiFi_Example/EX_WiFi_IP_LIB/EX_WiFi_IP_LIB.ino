//- 라이브러리 추가 -------------------------------------------------------------
#include <WiFiEsp.h>
#include <SoftwareSerial.h>

//- 전역 상수 선언 --------------------------------------------------------------
#define RXD_PIN         4
#define TXD_PIN         5

SoftwareSerial          wifi(RXD_PIN, TXD_PIN);  

//- 전역 변수 선언 --------------------------------------------------------------
char ssid[]       = "so";                 //- 연결 AP공유기 SSID
char pass[]       = "so123456";           //- 연결 AP공유기 PASS
int  wifiStatus   = WL_IDLE_STATUS;       //- 현재 WiFi 상태 저장 변수 

//- 초기화 ------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);         //- 디버깅용 시리얼 초기화
    wifi.begin(9600);          //- ESP WiFi 연결될 시리얼 포트 초기화
    initWiFly();               //- ESP WiFi 초기화
}

//- 기능 구현 --------------------------------------------------------------------
void loop(){  }

//- WiFi 초기화 ----------------------------------------------------------------
void initWiFly() {
    Serial.println("InitWiFly.....");
    
    //- ESP WiFi 모듈과 아두이노 시리얼 포트 연결 초기화
    WiFi.init(&wifi);
  
    //- ESP WiFi 존재 여부 체크 
    if (WiFi.status() == WL_NO_SHIELD)
    {
        Serial.println("WiFi shield not present");
        while (true);
    }
  
    //- AP 공유기 접속 시도
    while ( wifiStatus != WL_CONNECTED) 
    {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        
        //- WPA/WPA2 네트워크 접속 시도
        wifiStatus = WiFi.begin(ssid, pass);
    }
  
    //- AP 공유기 접속 완료 후 정보 출력
    Serial.println("You're connected to the network");
    printConnectInfo();
}

//- 연결 정보 출력--------------------------------------------------------------
void printConnectInfo()
{
  //- 연결된 AP공유기 정보 출력
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  //- 할당 받은 IP주소 정보 출력
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  Serial.println();
  
  //- 접속 웹서버 브라우저 정보 출력
  Serial.println();
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
  Serial.println();
}
