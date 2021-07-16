//시리얼 통신 실습 => serialEvent 사용
#define r_pin 9
#define g_pin 10
#define b_pin 11

bool rstate = false;
bool gstate = false;
bool bstate = false;

// 초기화 함수

void setup() {
  //시리얼 통신 초기화
  Serial.begin(9600);
  Serial.println("--init ok");

  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);

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
  if(rxData == 'r'){
    rstate = !rstate;
    digitalWrite(r_pin, rstate);
  }
  else if(rxData == 'g'){
    gstate = !gstate;
    digitalWrite(g_pin, gstate);
  }
  else if(rxData == 'b'){
    bstate = !bstate;
    digitalWrite(b_pin, bstate);
  }
  
}
