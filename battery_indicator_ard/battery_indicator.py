import serial
import time
import psutil

ser = serial.Serial('COM5', 9600)  # Change 'COM3' to your Arduino's port
time.sleep(2)

prev_percentage = -1

while True:
    battery = psutil.sensors_battery()
    percentage = battery.percent

    if percentage != prev_percentage:
        ser.write(str(percentage).encode())
        prev_percentage = percentage

    time.sleep(1)
