import serial
import matplotlib.pyplot as plt
import time

# Ajuste a porta serial se necessário
# Linux geralmente é /dev/ttyACM0 ou /dev/ttyUSB0
porta = '/dev/ttyACM0'
baudrate = 115200

ser = serial.Serial(porta, baudrate)

temperaturas = []
tempos = []

plt.ion()  # modo interativo
inicio = time.time()

while True:
    linha = ser.readline().decode().strip()

    try:
        temp = float(linha)
        tempo = time.time() - inicio

        temperaturas.append(temp)
        tempos.append(tempo)

        plt.clf()
        plt.plot(tempos, temperaturas)
        plt.xlabel("Tempo (s)")
        plt.ylabel("Temperatura (°C)")
        plt.title("Temperatura interna – Raspberry Pi Pico W")
        plt.pause(0.1)

    except:
        pass
