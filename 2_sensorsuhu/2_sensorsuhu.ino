#include <DallasTemperature.h>
#include <OneWire.h>


// INISIALISASI
int pinSuhu = 2;
int pinBuzzer = 3;
OneWire oneWire(pinSuhu);
DallasTemperature sensors(&oneWire);



void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(pinBuzzer, OUTPUT);
}


int flag = 0;

void loop() {

  
  // BACA DATA
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0); /*membaca index 0*/


  // LOGIKA
  if(bacaSuhu != DEVICE_DISCONNECTED_C){
    Serial.println("data suhu pada index 0="+ String(bacaSuhu));
    if(bacaSuhu >= 31.0) {
      analogWrite(pinBuzzer, 180);
      delay(100);
      analogWrite(pinBuzzer, 0);
      delay(100);
    }
  } else {
    Serial.println("tidak ditemukan");
  }
}
