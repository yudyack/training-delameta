#include <MFRC522.h>
#include <SPI.h>

int pinSDA = PB1;
int pinRST = PB0;

MFRC522 mfrc522(PB1, PB0);

String uidString = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void readUID() {
  uidString = "";
  for (size_t i = 0; i < mfrc522.uid.size; i++) {
		uidString.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    uidString.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  uidString.toUpperCase();
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
      readUID();
      Serial.println("uid: " + String(uidString));
    }
  }
}
