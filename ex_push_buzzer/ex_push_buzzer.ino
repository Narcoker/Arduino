// 푸쉬버튼 입력 받기 => 디지털 입력
// ---------------------------------------

// 센서 연결 핀 선언 ------------------------
#define  PUSH_PIN 8
#define  Buzz_PIN 7
// 초기화 함수
void setup() {
  // put your setup code here, to run once:
  // 아누이노에게 사용핀 알림 설정
  // 아두이노 핀 내부에 풀업저항 사용 설정
  pinMode(PUSH_PIN, INPUT_PULLUP);
  pinMode(Buzz_PIN, OUTPUT);
  // 시리얼 통신 초기화
  Serial.begin(9600);
}


// 기능 구현 함수 ---------------------------
// 전원을 OFF 해야지만 멈춤
void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(PUSH_PIN);
  Serial.print("Push value : ");
  Serial.println(value);

  if(value == 0) digitalWrite(Buzz_PIN, HIGH);
  else digitalWrite(Buzz_PIN, LOW);
}
