# waste_sorting_ROBOT_ARM
 

## 1. 개요

tensorflow object detection API를 사용하여 재활용 쓰레기(캔, 페트병, 비닐)를 감지할 수 있도록 학습 후,  
arduino 로봇팔을 이용한 쓰레기 분리하는 프로그램 (WS_model.py, waste_sorting.ino)  

#### waste sorting test video

[![youtube영상]<![s](https://user-images.githubusercontent.com/46870741/73062004-ba734600-3ede-11ea-8cdd-eefde39f7247.png)
](https://youtu.be/Q2wgBEOW0eo)

## 2. 구현 환경

1) ubuntu 18.04
2) Python 3.6
3) OpenCV-python 4.2.0
4) Numpy 1.17
5) tensorflow 1.12

## 3. training data, test data 및 학습과정

분리수거 모델을 위해서 각 label당 200여 장 씩, 약 600장의 training data와 약 60장의 test data가 사용.  
labelImg를 이용해 annotation을 만들고, tensorflow object detection API를 써서 1시간가량 학습.

tensorflow object detection API 사용법 및 학습 관련된 자세한 사항은 블로그 글 참고.  
<https://junsoofeb.github.io/posts/od1/>   
<https://junsoofeb.github.io/posts/od2/>  
<https://junsoofeb.github.io/posts/od3/>  

## 4. WS_model.py  동작 과정

### WS_model은 입력 이미지에서 can, pet, vinyl 3가지 label을 detection.

1) 사용자가 재활용 쓰레기가 잘 잡히도록 카메라의 위치를 설정한다.    
2) 자동 동작방식(mog2 알고리즘 사용) 또는  수동 동작방식을 선택한다.( 코드 상에서 주석처리! )   
3) 자동 동작 방식이라면, 동작 감지 후 4초 뒤 입력이미지로 사용될 frame을 촬영한다.  
4) 수동 동작 방식이라면, 지정된 위치에 두고, 's'키를 누르면 입력이미지로 사용될 frame을 촬영한다.  
5) 입력이미지를 학습된 모델에 넣고 어떤 label에 속하는지 알아낸다.  
6) label에 따라 robot ARM이 분리한다.

## 5. object detection 관련 이미지

![4](https://user-images.githubusercontent.com/46870741/72787225-db376380-3c72-11ea-8785-4035511e9be4.png)

![5](https://user-images.githubusercontent.com/46870741/72787227-db376380-3c72-11ea-80f0-038f8409fae4.png)

![6](https://user-images.githubusercontent.com/46870741/72787229-dbcffa00-3c72-11ea-8cf8-97e77ba82493.png)

![7](https://user-images.githubusercontent.com/46870741/72787230-dbcffa00-3c72-11ea-80b5-4ba43e6afd51.png)

![11](https://user-images.githubusercontent.com/46870741/72787231-dbcffa00-3c72-11ea-8ada-29cbec23016a.png)

![22](https://user-images.githubusercontent.com/46870741/72787232-dbcffa00-3c72-11ea-9c0b-36669721ec2b.png)
