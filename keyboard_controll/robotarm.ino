// 아두이노 4자유도 로봇팔 제어
#include <Servo.h> 

#define XPOS 0
#define YPOS 1

const int SERVOS = 4;
int PIN[SERVOS], value[SERVOS], idle[SERVOS], currentAngle[SERVOS], MIN[SERVOS];
int MAX[SERVOS], INITANGLE[SERVOS], previousAngle[SERVOS],ANA[SERVOS];
Servo myservo[SERVOS];

void setup()   {

  //좌우회전 서보모터
  PIN[0] = 9; //서보모터 IO를 9번핀으로 지정
  MIN[0] = 0; //서보모터 최소 회전각도
  MAX[0] = 180; //서보모터 최대 회전각도
  INITANGLE[0] = 90; //서보모터 초기각도
  
  //ANA[0] = 3; //조이스틱스위치입력 IO를 아날로그 A3번핀으로 지정
  
  //왼쪽 서보모터
  PIN[1] = 6;
  MIN[1] = 30; 
  MAX[1] = 165;
  INITANGLE[1] = 152;
  
  //ANA[1] = 2;
  //오른쪽 서보모터
  PIN[2] = 5;
  MIN[2] = 40;
  MAX[2] = 180;
  INITANGLE[2] = 90;
  
  //ANA[2] = 0;
  
  //그립퍼 서보모터
  PIN[3] = 10;
  MIN[3] = 60;
  MAX[3] = 180;
  INITANGLE[3] = 60;
  
  //ANA[3] = 1;
  
  for (int i = 0; i < SERVOS; i++){
    myservo[i].attach(PIN[i]);
    myservo[i].write(INITANGLE[i]);
    value[i] = 0;
    idle[i] = 0;
    previousAngle[i]=INITANGLE[i];
  }
}

void loop() {
  delay(20); // 로봇팔 속도조정을 위한 딜레이
 
    for (int i = 0; i < SERVOS; i++){
      value[i] = analogRead(ANA[i]);
      currentAngle[i] = myservo[i].read();
    
      if (value[i] > 612) {
        idle[i] = 0;
      
        if (currentAngle[i] < MAX[i]) ++currentAngle[i];
        if (!myservo[i].attached()){
          myservo[i].attach(PIN[i]);
        }
        myservo[i].write(currentAngle[i]);     
      } else if (value[i] < 412) {
      idle[i] = 0;
      if (currentAngle[i] > MIN[i]) --currentAngle[i];
      if (!myservo[i].attached()){
        myservo[i].attach(PIN[i]);
      }
      myservo[i].write(currentAngle[i]);    
    } else {
      ++idle[i];
    }
    if (idle[i] > 100){
      myservo[i].detach(); //서보모터를 일정시간 사용하지 않으면 연결을 끊어둔다.
      idle[i] = 0;
    }  
  }  
  
}
