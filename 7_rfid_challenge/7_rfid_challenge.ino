#include <DallasTemperature.h>
#include <MFRC522.h>
#include <NewPing.h>
#include <OneWire.h>
#include <SPI.h>

// INISIALISASI
#define SS_PIN 10
#define RST_PIN 9

int pinSuhu = 2;
int pinBuzzer = 3;
int pinTrigger = 4;
int pinEcho = 5;
int pinR = 6;
int pinY = 7;
int pinG = 8;
int pinIR = 5;

String uidString;

int gateState = 0;
int prev = 1;
int BATAS = 20 * 100;

// Sensor Suhu
OneWire oneWire(pinSuhu);
DallasTemperature sensors(&oneWire);

// Sensor Ultrasonik
NewPing cm(pinTrigger, pinEcho, BATAS);

// RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinIR, INPUT);

  SPI.begin();        // initiate SPI buss
  mfrc522.PCD_Init(); // Initiate MFRC522

  twoBuzz();
  Serial.println("start");
}

void setLed(int r, int y, int g) {
  digitalWrite(pinR, r);
  digitalWrite(pinY, y);
  digitalWrite(pinG, g);
}

void twoBuzz() {
  analogWrite(pinBuzzer, 180);
  delay(100);
  analogWrite(pinBuzzer, 0);
  delay(100);
  analogWrite(pinBuzzer, 180);
  delay(100);
  analogWrite(pinBuzzer, 0);
  delay(2000);
}

void longBuzz() {
  analogWrite(pinBuzzer, 180);
  delay(600);
  analogWrite(pinBuzzer, 0);
  delay(2000);
}

void readRFID() {

  mfrc522.PICC_ReadCardSerial();
  String pembatas = "-";
  uidString = String(mfrc522.uid.uidByte[0], HEX) + pembatas +
              String(mfrc522.uid.uidByte[1], HEX) + pembatas +
              String(mfrc522.uid.uidByte[2], HEX) + pembatas +
              String(mfrc522.uid.uidByte[3], HEX);
  uidString.toUpperCase();
}

int isIRRising() {
  int readIR = digitalRead(pinIR);
  if(prev == 1 && readIR == 0) {
    prev = readIR;
    return 1;
  }
  prev = readIR;
  return 0;
}

void loop() {

  // int readIR = digitalRead(pinIR);
  int masuk = isIRRising();
//  Serial.println("print1");
//  delay(100);

  if (mfrc522.PICC_IsNewCardPresent()&& gateState ==0 ) {

    readRFID();
    // print UID
    Serial.print("UID tag=");
    Serial.println(uidString);
    Serial.print("Message: ");
    if (uidString == "4A-51-6E-AE" ) {
      Serial.println("Selamat datang");
      Serial.println("Gerbang dibuka");
      gateState = 1;
      twoBuzz();
    } else{
      Serial.println("tidak dikenal");
      longBuzz();
    }
  } else if(masuk == 1 && gateState == 1) {
    Serial.println("gerbang ditutup");
    gateState = 0;
  }
}
