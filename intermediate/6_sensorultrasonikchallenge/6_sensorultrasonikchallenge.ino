#include <DallasTemperature.h>
#include <NewPing.h>
#include <OneWire.h>

// INISIALISASI
int pinSuhu = 2;
int pinBuzzer = 3;
int pinTrigger = 4;
int pinEcho = 5;
int pinR = 6;
int pinY = 7;
int pinG = 8;

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
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void setLed(int r, int y, int g){
  digitalWrite(pinR, r);
  digitalWrite(pinY, y);
  digitalWrite(pinG, g);
}

void fastBuzz(){
  analogWrite(pinBuzzer, 180);
  delay(80);
  analogWrite(pinBuzzer, 0);
  delay(80);
}

void slowBuzz(){
  analogWrite(pinBuzzer, 180);
  delay(180);
  analogWrite(pinBuzzer, 0);
  delay(400);
}

void loop() {

  // BACA DATA
  unsigned long bacaJarak = cm.ping_cm();

  Serial.println("Jarak=" + String(bacaJarak) + "cm");

  if(bacaJarak > 0 && bacaJarak <= 20){
    fastBuzz();
    setLed(HIGH, LOW, LOW);
  } else if (bacaJarak > 0 && bacaJarak <= 71) {
    setLed(LOW, HIGH, LOW);
    slowBuzz();
  } else {
    setLed(LOW,LOW,HIGH);
  }

}
