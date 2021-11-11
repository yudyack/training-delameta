// Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Servo.h>

// INISIALISASI
int SS_PIN = 10;
int RST_PIN = 9;
int pinBuzzer = 3;
int pinIR = 5;
int pinServo = 6;

String uidString;
int prev = 1;
int gateState = 0;

// Inisialisasi pembuatan variable
// harus cari alamatnnya dulu -> I2C scanner arduino
// pakai library wire
LiquidCrystal_I2C lcd(0x27, 16, 2);

// RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Servo
Servo myservo;

void twoBuzz() {
  digitalWrite(pinBuzzer, HIGH);
  delay(100);
  digitalWrite(pinBuzzer, LOW);
  delay(100);
  digitalWrite(pinBuzzer, HIGH);
  delay(100);
  digitalWrite(pinBuzzer, LOW);
  delay(1000);
  Serial.println("twobuzz");
}

void longBuzz() {
  digitalWrite(pinBuzzer, HIGH);
  delay(600);
  digitalWrite(pinBuzzer, LOW);
  delay(1000);
}

void lcdWrite(String top, String bot) {
  // Program yang akan dijalankan berulang-ulang
  lcd.clear(); // Untuk Menghapus karakter pada LCD
  lcd.setCursor(0, 0);
  lcd.print(top);
  lcd.setCursor(0, 1);
  lcd.print(bot);
}

void readRFID() {

  String pembatas = "-";
  String content = "";
  byte letter;
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uidString = content;
  uidString.toUpperCase();
}

int isIRRising() {

  int readIR = digitalRead(pinIR);
  if (prev == 1 && readIR == 0) {
    prev = readIR;

    Serial.println("isRising");
    return 1;
  }
  prev = readIR;
  return 0;
}

void setup() {
  // Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinIR, INPUT);
  SPI.begin();
  mfrc522.PCD_Init(); // Initiate MFRC522
  lcd.begin();
  twoBuzz();
  Serial.println("selamat datang");
  lcdWrite("SELAMAT DATANG", "Gerbang Dibuka");
  myservo.attach(pinServo);
}

void loop() {

  int masuk;
  // Select one of the cards

  if (mfrc522.PICC_IsNewCardPresent() && gateState == 0) {
    masuk = isIRRising();
    Serial.println("masuk");
    readRFID();
    // print UID
    Serial.print("UID tag=");
    Serial.println(uidString);
    Serial.print("Message: ");
    if (uidString == "0AA89015") {
      lcdWrite("SELAMAT DATANG", "Gerbang Dibuka");
      myservo.write(90);
      Serial.println("selamat datang");
      gateState = 1;
      twoBuzz();
    } else {
      Serial.println("tidak dikenal");
      lcdWrite("tidak", "dikenal");
      longBuzz();
    }
  } else if (gateState == 1) {
    masuk = isIRRising();
    if (masuk == 1) {

      Serial.println("gerbang ditutup");
      lcdWrite("gerbang", "ditutup");
      myservo.write(0);
      gateState = 0;
    }
  }
}
