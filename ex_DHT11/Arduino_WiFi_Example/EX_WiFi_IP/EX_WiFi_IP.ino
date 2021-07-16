/* ---------------------------------------------------------------------------
 *  사용하는 AP공유기의 SSID, PASSWORD로 변경하여 실습
 *  
 *   AT+CWJAP=\"사용 AP공유기 SSID\",\"사용 AP공유기 PASSWORD\" 
 * --------------------------------------------------------------------------*/

#include <SoftwareSerial.h>

//- 전역 상수 선언 --------------------------------------------------------------
#define RXD_PIN       2
#define TXD_PIN       3

SoftwareSerial wifi(RXD_PIN, TXD_PIN);  

//- 전역 상수 선언 --------------------------------------------------------------
#define JOIN_CMD      "AT+CWJAP=\"Narcoker\",\"1234qwer\""
#define IP_CMD        "AT+CIPSTA?"
#define CIPSTA_IP     "+CIPSTA:ip:"
#define CIPSTA_GW     "+CIPSTA:gateway:"

//- 전역 변수 선언 --------------------------------------------------------------
boolean bConnected = false;

//- 초기화 ------------------------------------------------------------------------
void setup()
{
    Serial.begin(9600);          // 아두이노 <-> PC
    wifi.begin(9600);            // 아두이노 <-> ESP-01 WiFi
    wifi.setTimeout(5000);
}

//- 기능 구현 함수 -------------------------------------------------------------
void loop(){
  if(!bConnected)  connectWiFi();
}

//- AP 접속 후 IP 할당 받기 --------------------------------------------------
void connectWiFi()
{
    //- 접속할 AP 명령어 
    String  arrCMD[] = { JOIN_CMD, IP_CMD };
    String  arrMSG[] = { "\n1)Joining...", "\n2)IP... "};
    String  rxData = "";

    for(int i=0; i<2; i++)
    {
        Serial.print( arrMSG[i] );
        Serial.print("\n[ CMD ] "); 
        Serial.print(arrCMD[i]);
        
        wifi.println(arrCMD[i]);
        
        while(!wifi.available());
        
        while(wifi.available())
        {
                Serial.print("\n[ RXD ] "); 
                rxData = wifi.readString();
                Serial.println( (rxData.indexOf("OK")>=0)?"OK":"Fail" );
        }
        
      if(rxData.indexOf("+CIPSTA:ip:")>=0){
                 rxData ="IP:" +
                 rxData.substring(rxData.indexOf(CIPSTA_IP)+12,
                 rxData.lastIndexOf(CIPSTA_GW)-3);
                 Serial.println(rxData);
                 bConnected = true;
        }
    }
}
