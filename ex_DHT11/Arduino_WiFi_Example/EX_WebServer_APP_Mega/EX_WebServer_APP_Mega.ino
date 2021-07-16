/* ---------------------------------------------------------------------------
 *  사용하는 AP공유기의 SSID, PASSWORD로 변경하여 실습
 *  char         ssid[]       = "사용 AP공유기 SSID"
 *  char         pass[]       = "사용 AP공유기 PASSWORD" 
 *  
 *  안드로이드 휴대폰과 동일 AP공유기 접속 필수!
 *  안드로이드 휴대폰 APP과 통신 
 * --------------------------------------------------------------------------*/

//- 라이브러리 추가 ------------------------------------------------------------
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
//#include <Thermistor.h>

//- 센서 연결 핀 선언 ----------------------------------------------------------
#define RXD_PIN           2         // ESP-01S 연결 핀
#define TXD_PIN           3
#define LED_RED_PIN       7

//- 전역 변수 선언 -------------------------------------------------------------
char          ssid[]       = "SK_WiFiGIGA41BF";   //- 연결 AP SSID
char          pass[]       = "1702001012";        //- 연결 AP PASS
int           wifiStatus   = WL_IDLE_STATUS;      //- 현재 WiFi 상태 
IPAddress     ip;                                 //- IP정보 저장
unsigned long preMillis    = 0;                   //- 온도 정보 전달 타이머


//- 객체 변수 선언 -------------------------------------------------------------
//Thermistor            temp(A0);                    //- 온도 센서
//SoftwareSerial        wifi(RXD_PIN, TXD_PIN);      //- ESP-01S WiFi 객체
WiFiEspServer         server(8090);                 //- 서버 객체 선언
WiFiEspClient         gClient;
bool                  bConnClient = false;

//- 초기화 -----------------------------------------------------------------------
void setup()
{
    Serial.begin(115200);             //- Debug
    Serial2.begin(115200);            //- WiFi
    pinMode(LED_RED_PIN, OUTPUT);       //- LED 핀 동작 모드 설정
    
    digitalWrite(LED_RED_PIN, HIGH);    //- ESP WiFi 초기화 시작
    initWiFly();                        //- ESP WiFi 초기화
    digitalWrite(LED_RED_PIN, LOW);     //- ESP WiFi 초기화 끝
}

//- 기능 구현 -------------------------------------------------------------------
void loop()
{
      WiFiEspClient client = server.available();
      if(client)
      {
          if(client.connected())  Serial.println("Client ~~~ CONNECTED !");
      }
  /*
      if(gClient)
      {
            if(millis() - preMillis > 1000)
            {  
                //- 송신 데이터 형태 => @TMP,온도값# 
                sendWiFiData(&gClient,
                             "@TMP,", 
                             "21.3");
                preMillis = millis();
            }    
      }
      
      //- 클라이언트 접속 시 클라이언트 객체 생성
      WiFiEspClient client = server.available();
      if(client)
      {
            gClient = client;
            Serial.println("Client ~~~~");
            if(client.connected()) 
            {
                  //- 클라이언트의 요청이 있는 경우 
                  if(client.available()) 
                  {
                      //- 수신 데이터 형태 => @RED,1#  , @RED,0# 
                      String rxData = client.readString();
                      if(rxData.startsWith("@") && rxData.endsWith("#"))
                          controlWiFiData(rxData);              
                  }
            }else{
              client.stop();
              Serial.println("Client STOP");
            }
      }
      */
}


//- WiFi 초기화 ----------------------------------------------------------------
void initWiFly() {
    Serial.println("InitWiFly.....");
    
    //- ESP WiFi 모듈과 아두이노 시리얼 포트 연결 초기화
    WiFi.init(&Serial2);
  
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
    
    //- 서버 시작 
    server.begin();

    //- 할당 받은 IP주소 정보 출력
   ip = WiFi.localIP();
   Serial.println(ip);
   Serial.println();
   Serial.println("....END");
}


//- 클라이언트에서 받은 데이터 처리 ----------------------------------------
void controlWiFiData(String rxData){

  Serial.println(rxData);
  
  if( rxData.indexOf("RED,1") >=0 )
      digitalWrite(LED_RED_PIN, HIGH);
  else if( rxData.indexOf("RED,0") >=0 )
      digitalWrite(LED_RED_PIN, LOW);   
}

//- 클라이언트에 데이터 보내기 -----------------------------------------
void sendWiFiData(WiFiEspClient* client, String sztitle, String szMsg){
  String szSendData = sztitle;
  szSendData += szMsg;
  szSendData +="#";
  client->println(szSendData);
  Serial.print("TX <=== ");
  Serial.println(szSendData);
}
