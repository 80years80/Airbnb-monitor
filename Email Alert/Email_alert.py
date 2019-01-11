import serial
import subprocess
import smtplib
import getpass
import sys
import os
#One data entry per second max.
#The data read in is the concern level of the household conditions.
hourCount = 0;
ser = serial.Serial('/dev/ttyACM0', 9600)
while True: #Add logic to ensure data[2] is not empty
    #hourCount = hourCount + 1
    data = ser.readline().split()
    if(len(data) == 3):
        hourCount = hourCount + 1
        print hourCount

        if(hourCount == 3600):
            countSmoke = 0
            countMold = 0
            countTemp = 0
            countHumid = 0
            hourCount = 0
        print data[2]  # For testing
        if (data[2] == 500):
            countSmoke = countSmoke + 1;
            #if 3 minutes worth of smoke concern comes through 
            if(countSmoke == 180):
                os.system('echo "Smoke Alert Email" | mail -s "Test Subject" akbulutemre7@gmail.com')
        if (data[2] == 300):
            countMold = countMold + 1;
            #if 30 minutes of mold conditions occurs.
            if(countMold == 1800):
                os.system('echo "Mold Condition Alert Email" | mail -s "Test Subject" akbulutemre7@gmail.com')
        if (data[2] == 200):
            countTemp = countTemp + 1;
            #if 30 minutes of high temperature conditions occurs.
            if(countMold == 1800):
                os.system('echo "Temperature Condition Alert Email" | mail -s "Test Subject" akbulutemre7@gmail.com')
        if (data[2] == 100):
            countHumid = countHumid + 1;
            #if 30 minutes of high moisture conditions occurs.
            if(countHumid == 1800):
                os.system('echo "Mositure Alert Email" | mail -s "Test Subject" akbulutemre7@gmail.com')



        
    else:
       print("did not recieve data for gas/smoke")
