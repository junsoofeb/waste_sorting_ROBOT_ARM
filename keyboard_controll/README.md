# 4 dof robot arm keyboard controller

## 1. 개요

키보드를 이용해 손쉽게 로봇팔을 조종할 수 있는 python 프로그램. 
나중에 카메라와 함께 사용할 예정이라 keyboard 모듈이 아닌 OpenCV의 waitKey로 구현.   

로봇팔 출처 및 조립은 아래 링크 참조  
<https://smallhammer.cc/docs/snam500>

## 2. 주요 H/W 

1. 아두이노 UNO  
2. 아두이노 UNO용 서보 IO 확장 보드  
3. SNAM 1900 (로봇팔 frame 및 서보모터)  

## 3. 주요 S/W

1. python 3.6 
2. arduino IDE 1.8.10
3. OpenCV 4.2.0   

## 4. 사용 방법 (manual 참고)

### manual
<img width="543" alt="arm" src="https://user-images.githubusercontent.com/46870741/72552221-be4d0a00-38d9-11ea-832f-d9073cc8e84b.png">

### 사용 전, 본인의 로봇팔에 맞게 min_angle, max_angle 등의 configure 필요!! 
### PC와 아두이노는 serial통신을 한다고 가정.


1. keyboard.ino 파일에서 자신의 로봇팔에 맞게 min, max, initial angle등 을 설정.   
2. keyboard.ino 파일을 arduino IDE에서 컴파일 후 아두이노에 업로드.  
3. python_controll.py을 실행하고, 키보드를 이용해 조종.  

w 키를 누르면 로봇팔이 앞으로 전진.  
s 키를 누르면 로봇팔이 뒤로 후진.  
a 키를 누르면 로봇팔 몸통이 왼쪽으로 회전.  
d 키를 누르면 로봇팔이 몸통이 오른쪽으로 회전.  
g 키를 누르면 로봇팔 집게가 물체를 집음.  
h 키를 누르면 로봇팔 집게가 물체를 놓음.  


