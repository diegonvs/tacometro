import serial
import time
ser = serial.Serial('/dev/ttyACM0', baudrate=9600)
txt = ""
i=0

while i < 150:
	dados = open("data.txt","a")
	line = ser.readline()
	txt += line
	print(txt)
	dados.write(txt)
	txt=""
	i = i + 1

time.sleep(2)
dados.close()
print("a contagem terminou!")