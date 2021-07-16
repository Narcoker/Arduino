// 문자열 String 클래스 사용하기

void setup() {
  //시리얼 통신 초기화
  Serial.begin(9600);
  showInfo("Hello");

  String data1 = "123";
  String data2 = "999";

  Serial.println(data1 + data2); // 문자열의 합 연산 
  data2 += 2020;
  data2 += "Good Luck";
  Serial.println(data2);

  //숫자로된 문자열의 자료형을 숫자로 변형
  Serial.println(data1.toInt());
  data1 = data1.toInt();
  Serial.println(data1+2020);
}


// 기능 구현 함수
void loop() {
  // put your main code here, to run repeatedly:

}

// 문자열 다루는 함수
void showInfo(String msg){
  Serial.println(msg);
  
  Serial.print( " msg.length() => "); // 문자열 길이 반환
  Serial.println(msg.length());

  //대소문자 반환
  Serial.print( " msg.toUpperCase() => "); // 대문자 변환
  msg.toUpperCase();
  Serial.println(msg);

  Serial.print( " msg.toLowerCase() => "); // 소문자 변환
  msg.toLowerCase();
  Serial.println(msg);

  //시작문자, 끝문자 확인
  Serial.print(" msg.startsWith(he) => "); // 시작문자 확인
  Serial.println(msg.startsWith("he"));
  Serial.print(" msg.startsWith(HE) => ");
  Serial.println(msg.startsWith("HE"));

  Serial.print(" msg.endsWith(lo) => "); // 끝문자 확인
  Serial.println(msg.endsWith("lo"));
  Serial.print(" msg.endsWith(LO) => ");
  Serial.println(msg.endsWith("LO"));

  //문자열안에 문자 또는 문자열 인덱스
  Serial.print(" msg.indexOf(ll) => "); // 있으면 맨처음 문자의 인덱스 값 출력
  Serial.println(msg.indexOf("ll"));

  Serial.print(" msg.indexOf(LL) => "); // 없으면 -1 반환
  Serial.println(msg.indexOf("LL"));

  //문자열 추출
  Serial.print(" msg.substring(2,4) => "); 
  Serial.println(msg.substring(2,4)); // 2,3번 인덱스 추출
  
  Serial.print(" msg.substring(3) => "); 
  Serial.println(msg.substring(3)); // 3번 인덱스부터 끝까지 추출
  

}
