//시리얼 통신 실습 => serialEvent 사용
#define buz_pin 7

bool state = false;

// 초기화 함수

void setup() {
  //시리얼 통신 초기화
  Serial.begin(9600);
  Serial.println("--init ok");

  pinMode(buz_pin, OUTPUT);
}

// 기능 구현
void loop() {
  
  
}

//시리얼 통신에서 데이터 수신시 자동실행되는 함수
//콜백함수라고도 한다. 
void serialEvent(){
  char rxData = (char)Serial.read(); // read()함수는 버퍼의 한글자값의 아스키코드 값을 리턴한다. 

  controlSensor(rxData);
 
    //수신 데이터 확인 웨해서 PC로 전송
  Serial.print("rxDATA = ");
  Serial.println(rxData);
}

//센서 제어 함수
void controlSensor(char rxData){
//   if(rxData == 'b' && state == false){
//    digitalWrite(buz_pin, HIGH);
//    state = true;
//    Serial.println("켜짐");
//  }
//  else if(rxData == 'b' && state == true){
//    digitalWrite(buz_pin, LOW);
//    state = false;
//    Serial.println("꺼짐");
//  }

  if(rxData == 'b'){
    state = !state;
    digitalWrite(buz_pin, state);
  }
}
