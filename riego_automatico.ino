#include <SimpleDHT.h>
#include <SPI.h>
#definir sensor_de_humedad_pin A0
#define ldr_pin A5

int pinDHT11 = 2;
SimpleDHT11 dht11;
int ldr_value = 0;
int water_pump_pin = 3;
int water_pump_speed = 255;
configuración vacía () {
  Serial.begin (9600);
}

bucle vacío () {
  Serial.println ("******************************");
  Serial.println ("Muestra DHT11 ...");
  temperatura del byte = 0;
  byte humedad_en_aire = 0;
  datos de bytes [40] = {0};
  if (dht11.read (pinDHT11, y temperatura y humedad_en_aire, datos)) {
    Serial.print ("Lectura del sensor DHT11 fallida");
    regresar;
  }
  
  Serial.print ("Muestra RAW Bits:");
  para (int i = 0; i <40; i ++) {
    Serial.print ((int) datos [i]);
    si (i> 0 && ((i + 1)% 4) == 0) {
      Serial.print ('');
    }
  }
  Serial.println ("");
  Serial.print ("Muestra OK:");
  Serial.print ("Temperatura:"); Serial.print ((int) temperatura); Serial.print ("* C,");
  Serial.print ("Humedad relativa en aire:"); Serial.print ((int) humedad_en_aire); Serial.println ("%");
  int ground_humidity_value = map (analogRead (sensor_de_humedad_pin), 0, 1023, 100, 0);
  Serial.print ("Humedad en suelo:");
  Serial.print (ground_humidity_value);
  Serial.println ("%");
  int ldr_value = map (analogRead (ldr_pin), 1023, 0, 100, 0);
  Serial.print ("Luz:");
  Serial.print (ldr_value);
  Serial.println ("%");
   Serial.println ("******************************");
 if (ground_humidity_value <= 50 && ldr_value <30 && temperature <30) {
 digitalWrite (pin_bomba_agua, ALTO);
 Serial.println ("Irrigación");
 analogWrite (pin_bomba_agua, velocidad_bomba_agua);
 }
 demás{
 digitalWrite (pin_bomba_agua, BAJO);
 Serial.println ("Riego detenido");
 }
 retraso (100); 
}
