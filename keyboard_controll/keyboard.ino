// 아두이노 4자유도 로봇팔 제어
#include <Servo.h> 

#define XPOS 0
#define YPOS 1

const int SERVOS = 4;
int PIN[SERVOS], MIN[SERVOS], MAX[SERVOS], INITANGLE[SERVOS], currentAngle[SERVOS];
Servo myservo[SERVOS];

int body; 
int left_arm; 
int right_arm;
int claw; 
    

void setup() {

  //좌우회전 서보모터
  PIN[0] = 9; //서보모터 IO를 9번핀으로 지정
  MIN[0] = 0; //서보모터 최소 회전각도
  MAX[0] = 180; //서보모터 최대 회전각도
  INITANGLE[0] = 0; //서보모터 초기각도
  
  
  //왼쪽 서보모터
  PIN[1] = 6;
  MIN[1] = 0; 
  MAX[1] = 180;
  INITANGLE[1] = 0;

  //오른쪽 서보모터
  PIN[2] = 5;
  MIN[2] = 0;
  MAX[2] = 180;
  INITANGLE[2] = 0;

  //집게  서보모터
  PIN[3] = 10;
  MIN[3] = 0;
  MAX[3] = 180;
  INITANGLE[3] = 0;

  // 처음 위치 잡기
  for (int i = 0; i < SERVOS; i++)
  {
    myservo[i].attach(PIN[i]);
    myservo[i].write(INITANGLE[i]);
    currentAngle[i]=INITANGLE[i];
  }

  int body = currentAngle[0];
  int left_arm = currentAngle[1];
  int right_arm = currentAngle[2];
  int claw = currentAngle[3];
    

  //mysevo[0].attach(9); // 좌우회전 모터
  //mysevo[1].attach(6); // 왼쪽팔 모터
  //mysevo[2].attach(5); // 오른쪽팔 모터
  //mysevo[3].attach(10); // 집게 모터
  
  // MIN[]은 서보모터 최소 각도
  // MAX[]는 서보모터 최대 각도
  // INITANGLE[]은 서보모터 초기각도 

  Serial.begin(9600);

}

  


void loop() {

  while (Serial.available() > 0) 
  {

    long value = Serial.read();
    
    switch(value) 
    {
      // w 누르면 로봇팔 앞으로 
      case 'w':
        right_arm += 5;
        if(right_arm >= 180) 
          right_arm = 180;
        myservo[2].write(right_arm); // 오른쪽팔 모터
        delay(1000);
        break;
        
      // a 누르면 몸통 왼쪽으로
      case 'a':
        body += 5;
        if(body >= 180) 
          body = 180;
        myservo[0].write(body);
        delay(1000);
        break;
        
      // d 누르면 몸통 오른쪽으로
      case 'd':
        body -= 5;
        if (body <= 0)
          body = 0;
        myservo[0].write(body);
        delay(1000);
        break;
        
      // s 누르면 로봇팔 뒤로 
      case 's':
        right_arm -= 5;
        if(right_arm <= 0) 
          right_arm = 0;
        myservo[2].write(right_arm); // 오른쪽팔 모터
        delay(1000);
        break;
        
      // r 누르면 팔 위로
      case 'r':
        left_arm += 5;
        if(left_arm >= 180) 
          left_arm = 180;
        myservo[1].write(left_arm);
        delay(1000);
        break;
        
      // f 누르면 로봇팔 아래로 
      case 'f':
        left_arm -= 5;
        if(left_arm <= 0) 
          left_arm = 0;
        myservo[1].write(left_arm);
        delay(1000);
        break;
        
      // g 누르면 집게 잡기
      case 'g':
        claw += 5;
        if(claw >= 180)
          claw = 180;
        myservo[3].write(claw); // 집게 모터
        delay(1000);
        break;
        
      case 'h':
        claw -= 5;
        if(claw <= 0)
           claw = 0;
        myservo[3].write(claw); // 집게 모터
        delay(1000);
        break;
        
    }
  }
} 
