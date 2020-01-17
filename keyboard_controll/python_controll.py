import cv2
import serial

arduino = serial.Serial('/dev/ttyUSB0', 9600)

cap = cv2.VideoCapture(-1)  
while(True):  
    ret, frame = cap.read() 
    cv2.imshow('frame',frame)
    key = cv2.waitKey(1) & 0xFF	    
    if key == ord('q'):  
        break

    elif key ==ord('w'):          
        arduino.write(b'w')
        print('w')

    elif key ==ord('a'):         
        arduino.write(b'a')
        print('a')

    elif key ==ord('d'):          
        arduino.write(b'd')
        print('d')

    elif key ==ord('s'):          
        arduino.write(b's')
        print('s')

    elif key ==ord('z'):          
        arduino.write(b'z')


    elif key ==ord('g'):          
        arduino.write(b'g')
        print('g')

    elif key ==ord('h'):          
        arduino.write(b'h')
        print('h')

cap.release()  
cv2.destroyAllWindows()  
