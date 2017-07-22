import serial
import time
ser = serial.Serial('/dev/ttyACM0', baudrate=9600)
taxadeAtualizacao = 1000
txt = ""
i=0
while i < 10:

	dados = open("data.txt","a+")
	line = ser.readline()
	txt += line
	#dados.write(line)
	dados.write('{0} {1}'.format(x, x*x))
	time.sleep(taxadeAtualizacao)
	i = i + 1

time.sleep(2)
dados.close()
print("terminou")