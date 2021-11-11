#include <DallasTemperature.h>
#include <NewPing.h>
#include <OneWire.h>

// INISIALISASI
int pinSuhu = 2;
int pinBuzzer = 3;
int pinTrigger = 4;
int pinEcho = 5;

int BATAS = 20 * 100;

// Sensor Suhu
OneWire oneWire(pinSuhu);
DallasTemperature sensors(&oneWire);

// Sensor Ultrasonik
NewPing cm(pinTrigger, pinEcho, BATAS);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(pinBuzzer, OUTPUT);
}

void buzz() {
  analogWrite(pinBuzzer, 180);
  delay(100);
  analogWrite(pinBuzzer, 0);
  delay(100);
}

void loop() {

  // BACA DATA
  // sensors.requestTemperatures();
  // float bacaSuhu = sensors.getTempCByIndex(0); /*membaca index 0*/

  unsigned long bacaJarak = cm.ping_cm();

  // LOGIKA
  // if(bacaSuhu != DEVICE_DISCONNECTED_C){
  //   Serial.println("data suhu pada index 0="+ String(bacaSuhu));
  //   if(bacaSuhu >= 31.0) {
  //     buzz();

  //   }
  // } else {
  //   Serial.println("tidak ditemukan");
  // }

  Serial.println("Jarak=" + String(bacaJarak) + "cm");
  analogWrite(pinBuzzer, bacaJarak);

}
