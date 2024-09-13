import cv2
import serial
import time
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject

cap = cv2.VideoCapture(0)
arduino = serial.Serial(port='COM8', baudrate=115200, timeout=.1)
detector = HandDetector(detectionCon=0.8)

while True:
    success, image = cap.read()
    hands, bboxInfo = detector.findHands(image)
    if len(hands)==1:
        mare=detector.fingersUp(hands[0])[0]
        arat=detector.fingersUp(hands[0])[1]
        mij=detector.fingersUp(hands[0])[2]
        inel=detector.fingersUp(hands[0])[3]
        mic=detector.fingersUp(hands[0])[4]

        print(mare,arat,mij,inel,mic)

        mare = str(mare)
        mare=mare+"\r"
        arduino.write(mare.encode())

        arat = str(arat)
        arat = arat + "\r"
        arduino.write(arat.encode())

        mij = str(mij)
        mij = mij + "\r"
        arduino.write(mij.encode())

        inel = str(inel)
        inel = inel + "\r"
        arduino.write(inel.encode())

        mic = str(mic)
        mic = mic + "\r"
        arduino.write(mic.encode())

        time.sleep(0.1)      

    cv2.imshow('image',image)      
    cv2.waitKey(1)       