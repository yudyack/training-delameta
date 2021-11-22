#include <MFRC522.h>
#include <SPI.h>

// INISIALISASI
int SS_PIN = 10;
int RST_PIN = 9;

int pinSuhu = 2;
String uidString;


// RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);

  SPI.begin();        // initiate SPI buss
  mfrc522.PCD_Init(); // Initiate MFRC522
  Serial.println("setup");

}

// void setLed(int r, int y, int g) {
//   digitalWrite(pinR, r);
//   digitalWrite(pinY, y);
//   digitalWrite(pinG, g);
// }

// void twoBuzz() {
//   analogWrite(pinBuzzer, 180);
//   delay(100);
//   analogWrite(pinBuzzer, 0);
//   delay(100);
//   analogWrite(pinBuzzer, 180);
//   delay(100);
//   analogWrite(pinBuzzer, 0);
//   delay(500);
// }

// void longBuzz() {
//   analogWrite(pinBuzzer, 180);
//   delay(600);
//   analogWrite(pinBuzzer, 0);
//   delay(500);
// }

void readRFID() {

  mfrc522.PICC_ReadCardSerial();
  String pembatas = "-";
  uidString = String(mfrc522.uid.uidByte[0], HEX) + pembatas +
              String(mfrc522.uid.uidByte[1], HEX) + pembatas +
              String(mfrc522.uid.uidByte[2], HEX) + pembatas +
              String(mfrc522.uid.uidByte[3], HEX);
  uidString.toUpperCase();
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {

    readRFID();

    // print UID
    Serial.print("UID tag=");
    Serial.println(uidString);
    Serial.print("Message: ");
    if (uidString == "4A-51-6E-AE") {
      Serial.println("Selamat datang");
      // twoBuzz();
    } else {

      Serial.println("tidak dikenal");
      // longBuzz();
    }
  }
}
