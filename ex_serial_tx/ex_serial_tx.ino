//전역변수----------------------------------------------------
int number = 1;

// 아두이노 초기화 함수 ----------------------------------------
// 전원 on 했을 때 딱 1번만 동작
// 7가지의 임베디드 보드 연결방식: GPIO, PWM, ADC(아날로그를 디지털로 번역) IRQ, Serial 통신방식, I2C 통신방식, SPI통신방식  
void setup() {
  // put your setup code here, to run once:
  // 시리얼 통신 초기화
  Serial.begin(9600); // 1초에 9600bit 
}

// 특정 기능 반복 수행하는 함수-----------------------------------
// 전원 off 하기전까지 계속 실행
void loop() {
  // put your main code here, to run repeatedly:
  // PC로 USB케이블 통해서 데이터 보내기
  Serial.println(number++);

  // delay(밀리세컨드) : 지정된 시간만큼 일시정지
  delay(1000); // 1초 = 1000밀리세컨드
}
