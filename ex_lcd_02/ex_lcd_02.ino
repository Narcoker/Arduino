// I2C Text LCD 사용하기 + pc에서 입력받은 데이터 출력하기

//라이브러리 추가
#include <LiquidCrystal_I2C.h>

//객체 변수 선언
LiquidCrystal_I2C lcd(0x27, 16, 2); //(기기 주소값, 칸수, 줄수)

//초기화 함수
void setup() {
  //시리얼 통신 초기화
  Serial.begin(9600);
  
  //센서 초기화
  lcd.init(); // 초기화시 (0,0)에 커서 위치
  lcd.backlight();
  lcd.print("init ok");
  delay(1000); 

}

//기능 구현 함수
void loop() {

}

//데이터 수신 처리 콜백 함수
void serialEvent(){
  //pc로 부터 데이터 수신한것 읽어오기
  String data = Serial.readString();
  
  //I2C text LCD에 출력하기
  lcd.clear();
  lcd.print(data);  
}
