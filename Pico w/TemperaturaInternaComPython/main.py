# Leitura da temperatura interna do Raspberry Pi Pico W e envio via serial
from machine import ADC
import time

sensor_temp = ADC(4)
conversion_factor = 3.3 / 65535

while True:
    leitura = sensor_temp.read_u16()
    tensao = leitura * conversion_factor
    temperatura = 27 - (tensao - 0.706) / 0.001721

    # Envia só o número (facilita o gráfico)
    print(temperatura)
    time.sleep(1)

