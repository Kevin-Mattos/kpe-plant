#!/usr/bin/env python3
import serial
import json
import requests
import traceback
import time
import socket


def sendData(jsonString):
    data = json.loads(jsonString)
    method = data['method']
    jsonData = data['json'] 
    r = requests.post(f'http://192.168.1.187:8080/{method}', data = jsonData)

    
def getMyIp():
    hostName = socket.gethostname()
    #print('obtendo meu ip')
    ip_ = socket.gethostbyname(hostName)
    #print(ip_)
    return ip_

def receiveData(ser):
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
    
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
 ##           sendData(line)

def connect():
    ser = serial.Serial('COM4', 9600, timeout=1) 
    ser.reset_input_buffer()
    ser.flushInput()
    ser.flushOutput() 
#    while(1):        
#        line =  ser.readline().decode('utf-8').rstrip() 
#        print(line)
#        ser.write('asdfasdf\0'.encode())

    try:
        receiveData(ser)
    except:
        print("An exception occurred when receiving data: ")
        traceback.print_exc()
        ser.close()
        connect()


def init():
    try:
        connect()
    except:
        print("An exception occurred with the connection: ")
        traceback.print_exc()

while(1):
    init()
    time.sleep(2)

