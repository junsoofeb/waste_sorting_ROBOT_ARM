// 아두이노 4자유도 로봇팔 제어
#include <Servo.h> 

// min_angle[]은 서보모터 최소 각도
// max_angle[]는 서보모터 최대 각도
// init_angle[]은 서보모터 초기각도 

const int SERVO_NUM = 4; // 서보 개수 
int PIN[SERVO_NUM], min_angle[SERVO_NUM], max_angle[SERVO_NUM], init_angle[SERVO_NUM];
Servo myservo[SERVO_NUM];

// 조종할 때 사용할 전역 변수
int body; 
int left_arm; 
int right_arm;
int claw; 

// 움직이는 정도를 조절
int move = 15;
    

//****************************************************
// min, max, init_angle은 직접 서보 움직여보며 congif필요!
// 현재 범위는 내 로봇팔에 맞춰진 상태
// 직접 서보 움직여보며, 배선 상태 및 움직임 범위를 측정해야함 
//****************************************************
void setup() {
  
  //몸통 서보모터
  PIN[0] = 9; //서보모터 IO를 9번핀으로 지정
  min_angle[0] = 0; //최소로 회전할 수 있는 각도
  max_angle[0] = 110; //최대로 회전할 수 있는 각도
  init_angle[0] = 55; //서보모터 초기각도 

  // 0 으로주면 오른쪽
  // 110으로주면 왼쪽
  
  
  //왼쪽 팔 서보모터
  PIN[1] = 6;
  min_angle[1] = 60; 
  max_angle[1] = 100;
  init_angle[1] = 60;
  //init_angle[1] = 60;
  // 각도 커질수록 위로 올라감 

  //오른쪽 팔 서보모터
  PIN[2] = 5;
  min_angle[2] = 10;
  max_angle[2] = 80;
  init_angle[2] = 10;
  //init_angle[2] = 30;
  // 각도 커질수록 앞으로 나감 

  // 오른팔 80으로 하면 앞으로 쭉 내밈
  // 10으로 하면 원상태로 

  //집게  서보모터
  PIN[3] = 10;
  min_angle[3] = 0;
  max_angle[3] = 70;
  init_angle[3] = 60;
  // 0이면 물고, 60이면 벌림 

  // 처음 위치 잡기
  for (int i = 0; i < SERVO_NUM; i++)
  {
    myservo[i].attach(PIN[i]);
    myservo[i].write(init_angle[i]);
  }

  body = init_angle[0];
  left_arm = init_angle[1];
  right_arm = init_angle[2];
  claw = init_angle[3];
    
  // sample code
  // attach에는 PIN, write에는 angle
  //mysevo[0].attach(9); // 좌우회전 모터
  //mysevo[1].attach(6); // 왼쪽팔 모터
  //mysevo[2].attach(5); // 오른쪽팔 모터
  //mysevo[3].attach(10); // 집게 모터
  

  Serial.begin(9600);

}

  


void loop() {

    long value = Serial.read();
    
    switch(value) 
    {
      // vinyl이면 오른쪽으로 분리
      // 몸통 왼쪽으로 , 팔 앞으로, 회전 오른쪽 
      case 'v':
        myservo[0].write(110); // 몸 왼쪽 
         delay(1000);
        myservo[2].write(80); // 팔 앞으로 
         delay(1000);
        myservo[0].write(0);// 몸 오른쪽으로

        // 원상복귀
        myservo[0].write(body);
        myservo[1].write(left_arm);
        myservo[2].write(right_arm); 
        myservo[3].write(claw); 
        break;
        
      // can은 왼쪽으로 분리 
      case 'c':
        myservo[0].write(0); // 몸 오른쪽 
        delay(1000);
        myservo[2].write(80); // 팔 앞으로 
        delay(1000);
        myservo[0].write(110);// 몸 왼쪽으로
        delay(1000);
        // 원상복귀
        myservo[0].write(body);
        myservo[1].write(left_arm);
        myservo[2].write(right_arm); 
        myservo[3].write(claw); 
        break;

      // pet는 앞쪽으로 분리 
      case 'p':
        myservo[2].write(80); // 팔 앞으로 
        delay(1000);
        // 원상복귀
        myservo[2].write(right_arm); 
        break;
        
    }
 
} 
