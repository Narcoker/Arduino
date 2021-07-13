//능동부저 제어하기 실습

//센서 연결핀 선언 -------------------------
#define BUZ_PIN 7

//counter 전역변수 선언
int counter = 0;

//초기화 기능 함수 -------------------------
void setup() {
  // 아두이노에게 센서 연결된 핀 정보 알림 설정
  pinMode(BUZ_PIN, OUTPUT);

  // 시리얼 모니터 초기화
  Serial.begin(9600);
}

// 일정 간격으로 부저 소리 출력하기
void loop() {
  //부저 켜기
  if(counter < 5){ // 5번만 울리도록 if문 지정
  digitalWrite(BUZ_PIN, HIGH);
  Serial.println("Buzzer ON");
  delay(500);

  //부저 켜기
  digitalWrite(BUZ_PIN, LOW);
  Serial.println("Buzzer OFF");
  delay(500);

  // counter 변수값 갱신
  counter++;
  Serial.println(counter);
  }
}
