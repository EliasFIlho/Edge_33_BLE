import serial
from time import time

porta = "/dev/ttyACM0"
baud = 115200
arquivo = "logger.csv"

ser = serial.Serial(porta,baud)
ser.flushInput()
print("Abrindo Serial")

wait_time = 4
previous_time = time()

while time()-previous_time < wait_time:
    data = str(ser.readline().decode("utf-8"))
    print(data)
    file = open(arquivo,"a")
    file.write(data)

print("Final de leituras")
file.close()
ser.close()
