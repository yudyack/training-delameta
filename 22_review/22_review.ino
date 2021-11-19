
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Servo.h>

// INISIALISASI

int pinIR = 2;
int pinBuzzer = 3;
int pinR = 4;
int pinY = 5;
int pinG = 7;
int pinServo = 6;

// RFID
int pinSS = 10;
int pinRST = 9;
MFRC522 mfrc522(pinSS, pinRST);

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// SERVO
Servo servo;

// VARIABLE
String uidString = "";
int prev = 0;
int gate = 0;

void readUID() {
  uidString = "";
  for (size_t i = 0; i < mfrc522.uid.size; i++) {
    uidString.concat(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    uidString.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uidString.toUpperCase();
}

void writeLED(int r, int y, int g) {
  digitalWrite(pinR, r);
  digitalWrite(pinY, y);
  digitalWrite(pinG, g);
}

void writeLCD(String atas, String bawah) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(atas);
  lcd.setCursor(0, 1);
  lcd.print(bawah);
}

int checkRising(int input) {
  int isRising = 0;
  if (prev == 0 && input == 1) {
    isRising = 1;
  }
  prev = input;
  return isRising;
}

void longBuzz() {
  analogWrite(pinBuzzer, 200);
  delay(350);
  analogWrite(pinBuzzer, 0);
  delay(600);
}

void doubleBuzz() {
  analogWrite(pinBuzzer, 210);
  delay(120);
  analogWrite(pinBuzzer, 0);
  delay(40);
  analogWrite(pinBuzzer, 210);
  delay(120);
  analogWrite(pinBuzzer, 0);
  delay(400);
}

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  pinMode(pinIR, INPUT);

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin();

  servo.attach(pinServo);

  writeLCD("TEMPELKAN KARTU", "");
  Serial.println("TEMPELKAN KARTU GERBANG DITUTUP");
  writeLED(1, 0, 0);
  servo.write(0);
}

void loop() {

  int readIR = !digitalRead(pinIR);
  int isRising = checkRising(readIR);

  if (mfrc522.PICC_IsNewCardPresent() && gate == 0) {
    if (mfrc522.PICC_ReadCardSerial()) {
      readUID();
      Serial.println("UID = " + uidString);
      if (uidString == "C79D884A") {
        doubleBuzz();
        Serial.println("SELAMAT DATANG YUDHYA");
        Serial.println("GERBANG DIBUKA");
        writeLCD("SELAMAT DATANG", "YUDHYA");
        delay(1200);
        writeLCD("GERBANG DIBUKA", "");
        gate = 1;
        writeLED(0, 0, 1);
        servo.write(90);

      } else {
        longBuzz();
        Serial.println("IDENTITAS TIDAK DIKENAL");
        writeLCD("IDENTITAS TIDAK", "DIKENAL");
        delay(2100);
        writeLCD("", "");
        delay(400);
        writeLCD("TEMPELKAN KARTU", "");
      }
    }
  }

  if (isRising && gate == 1) {
    Serial.println("SELAMAT JALAN");
    Serial.println("GERBANG DITUTUP");
    writeLCD("SELAMAT JALAN", "");
    gate = 0;
    servo.write(0);
    delay(600);
    writeLCD("GERBANG DITUTUP", "");
    writeLED(1, 0, 0);
    delay(2100);
    writeLCD("", "");
    delay(400);
    writeLCD("TEMPELKAN KARTU", "");
  }
}
