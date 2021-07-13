//- 센서 제어 핀 선언 --------------------------------------------------------
#define DUST_PIN          A0      // 미세먼지 핀 번호
#define IRED_PIN          12      // 미세먼지 센서 내 적외선 LED 핀 번호


//- 센서 제어 관련 상수 선언  -------------------------------------------------
#define DUST_DENSITY_RATIO     0.167  
#define VOC                    400
#define VCC                    5000

#define SAMPLING_TIME         280
#define WAITING_TIME          40
#define STOP_TIME             9680    // 센서 미 구동 시간  

#define FILTER_MAX              3

float arrFilter[FILTER_MAX] = {0,};

//- 초기화 함수 ---------------------------------------------------------------
void setup() {
  Serial.begin(9600);

  pinMode(IRED_PIN, OUTPUT);
  digitalWrite(IRED_PIN, HIGH);

  for(int i=0; i<FILTER_MAX; i++)
    arrFilter[i] = 0;
}

//- 1초 간격 미세먼지 측정 -----------------------------------------------------
void loop() {
  
 float dustDensity = filtering(probe_dust_density());

 Serial.print("Dust Density = ");
 Serial.print(dustDensity);
 Serial.println(" ug/m^3 ");
 
 delay(1000);
}

//- 미세먼지 측정 후 보정한 값 구하기 ---------------------------------------------
float probe_dust_density(){
  float dustValue = 0.0;
  float dustVo = 0.0;

  digitalWrite(IRED_PIN, LOW);
  delayMicroseconds(SAMPLING_TIME);

  dustValue = analogRead(DUST_PIN);
  delayMicroseconds(WAITING_TIME);

  digitalWrite(IRED_PIN, HIGH);
  delayMicroseconds(STOP_TIME);

  dustVo = (dustValue * (VCC / 1024.0));

  if(dustVo >= VOC)
  {
     float deltaV = dustVo - VOC;
     return deltaV * DUST_DENSITY_RATIO;
  }else{
     return 0;
  }
}

//- 미세먼지 측정 값 필터링 ---------------------------------------------------
float filtering(float val){
    int   sample_cnt = 0;
    float density = 0;
    
    for(int i=0; i<FILTER_MAX; i++)
      arrFilter[i-1] = arrFilter[i];

     arrFilter[FILTER_MAX-1]  = val;

    for(int i=0; i<FILTER_MAX; i++)
    {
        if( arrFilter[i] )
        {
            sample_cnt++;
            density += arrFilter[i];
        }
    }

    if(sample_cnt >0)
        return density / sample_cnt;

    return density;
}

