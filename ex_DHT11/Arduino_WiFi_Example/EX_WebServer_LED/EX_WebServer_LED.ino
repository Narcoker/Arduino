/* ---------------------------------------------------------------------------
 *  사용하는 AP공유기의 SSID, PASSWORD로 변경하여 실습
 *  char         ssid[]       = "사용 AP공유기 SSID"
 *  char         pass[]       = "사용 AP공유기 PASSWORD" 
 *  
 *  PC 또는 노트북 또는 휴대폰과 동일 AP공유기 접속 필수!
 *  웹브라우저(익스플로러 또는 크롬)와 통신 
 * --------------------------------------------------------------------------*/
//- 라이브러리 추가 -------------------------------------------------------------
#include <WiFiEsp.h>
#include <SoftwareSerial.h>

//- 전역 상수 선언 --------------------------------------------------------------
#define RXD_PIN       2
#define TXD_PIN       3
#define RED_PIN       7
#define BLU_PIN       8

SoftwareSerial        wifi(RXD_PIN, TXD_PIN);  

//- 전역 변수 선언 --------------------------------------------------------------
char         ssid[]       = "Narcoker";                 //- 연결 AP SSID
char         pass[]       = "1234qwer";           //- 연결 AP PASS
int          wifiStatus   = WL_IDLE_STATUS;       //- 현재 WiFi 상태 
IPAddress    ip;                                  //- IP정보 저장

int          gCount      =  0;
String       szLED       =  "끄기";
bool         bSend       =  false;

//- 객체 변수 선언 --------------------------------------------------------------
WiFiEspServer server(80);                         //- 웹 서버 객체 선언

//- 초기화 ------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);                         //- 디버깅용 시리얼 초기화
    wifi.begin(9600);                           //- ESP WiFi 연결될 시리얼 포트 초기화
    
    pinMode(RED_PIN, OUTPUT);
    pinMode(BLU_PIN, OUTPUT);
    digitalWrite(RED_PIN, HIGH);                //- ESP WiFi 초기화 시작
    initWiFly();                                //- ESP WiFi 초기화
    digitalWrite(RED_PIN, LOW);                 //- ESP WiFi 초기화 끝
}

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
  
    //-서버 시작 
    server.begin();
    Serial.println("SERVER BEGIN = OK !");

    //- 할당 받은 IP주소 정보 출력
    ip = WiFi.localIP();
    Serial.print("To see this page in action, open a browser to http://");
    Serial.println(ip);
    Serial.println();
}

//- 기능 구현 -------------------------------------------------------------------
void loop()
{
   //- 클라이언트 접속 요청 시 클라이언트 객체 생성
   WiFiEspClient client = server.available();
   if(client) 
   {
      Serial.println("new client");
      
      //- 클라이언트가 접속되어 있는 동안
      while(client.connected()) 
      {
          //- 클라이언트로부터 전송된 데이터가 있을 경우 
          if (client.available()) 
          {
              String rxData = client.readString();
             /* 디버깅용 생략 가능 
              Serial.println("============================================");
              Serial.println(rxData);
              Serial.println("============================================");
             */
              //- Client로부터 온 요청 처리
             if(rxData.startsWith("GET /H"))
             {
                  digitalWrite(RED_PIN, HIGH);
                   szLED = "켜기";
                   Serial.println("ON ON");
                   bSend = true;
             }else if(rxData.startsWith("GET /L")){
                  digitalWrite(RED_PIN, LOW);
                  szLED = "끄기";
                  Serial.println("OFFF");
                  bSend = true;
             }

              //- Client 응답 페이지 전송
              if(rxData.endsWith("\r\n\r\n"))
              {
                 sendHttpResponse(client);
                 break;
             }
             
          }
      } //- while()

      client.stop();
      Serial.println("client disonnected");
  }
}

//- 클라이언트 요청에 대한 응답 웹페이지 출력 함수 -------------------
void sendHttpResponse(WiFiEspClient client)
{
    Serial.print("Client Request Ended!");
    Serial.println("Web page transfer Start!");

    client.println("HTTP/1.1 200 OK");  
    client.println("Content-Type: text/html; charset=UTF-8");
    client.println("Connection: close");
    client.println("Refresh: 7");         //- 웹 페이지 갱신 초 단위 시간 설정
    client.println();

    // 클라이언트에 보여질 웹 페이지 HTML 부분
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<h1>Hello World!</h1>");
    client.print("Requests received: ");
    client.print(gCount++);
    client.println("<br>");

    //- 클라이언트에 센서로부터 측정된 값 출력 부분
    client.print("Analog input A0: ");
    client.print(analogRead(0));
    client.println("<br>");

    //- 현재 LED 상태 출력 부분
    client.print("The LED : ");
    client.print(szLED);
    client.println("<br>");

    //- 클라이언트의 버튼 입력을 받는 부분 ==> 2번 연속 클릭 시 데이터 전달
    client.println("<P>LED : <a href=\"/H\"><button>켜기</button></a>");
    client.println(" <a href=\"/L\"><button>끄기</button></a><br>");
    client.println("</body>");
    client.println("</html>");
    client.println();
    client.println();
    Serial.println("Web page transfer END");
}
