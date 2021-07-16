// I2C Text LCD 사용하기

//라이브러리 추가
#include <LiquidCrystal_I2C.h>

//객체 변수 선언
LiquidCrystal_I2C lcd(0x27, 16, 2); //(기기 주소값, 칸수, 줄수)

//초기화 함수
void setup() {
  //센서 초고하
  lcd.init(); // 초기화시 (0,0)에 커서 위치
  lcd.backlight();
  lcd.print("init ok");
  delay(1000); 
}

//기능 구현 함수
void loop() {
  lcd.clear(); //클리어시 (0,0)으로 자동 이동
  lcd.print("Good-Luck"); 

  //2번째 줄에 출력
  lcd.setCursor(0,1); // 0번 칸, 1번 줄로 커서이동
  lcd.print("___^^___");

  delay(2000);
  
}
