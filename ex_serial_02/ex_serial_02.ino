//시리얼 통신 실습

// 초기화 함수
void setup() {
  //시리얼 통신 초기화
  Serial.begin(9600);
  Serial.println("--init ok");
}

// 기능 구현
void loop() {
  // 시리얼 통신으로 데이터 수신(받기)
  // (1) 수신 버퍼(ex : 받은 편지함)에 데이터 존재 여부 체크
  // (2) 데이터 존재하면 읽기
  if( Serial.available() > 0){
    char rxData = char(Serial.read()); // read()함수는 버퍼의 한글자값의 아스키코드 값을 리턴한다. 

    //수신 데이터 확인 웨해서 PC로 전송
    Serial.print("rxDATA = ");
    Serial.println(rxData);
  }
}
