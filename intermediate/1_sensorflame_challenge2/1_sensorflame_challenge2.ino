// INISIALISASI
int pinLDR = A0;
int pinFlame = A1;
int pinBuzzer = 5;
int pinLedR = 6;

void setup() {
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}


void loop() {
  // BACA DATA
  int bacaFlame = analogRead(pinFlame);
  int flameScaled = map(bacaFlame, 800, 1023, 100, 0);
  
  // PRINT
  // Serial.print("Flame=");
  // Serial.print(bacaFlame);
  // Serial.print(",Scaled=");
  // Serial.print(flameScaled);
  // Serial.println();

  //LOGIKA
  if(flameScaled < 10) {
    Serial.println("aman");
  } else if (flameScaled >= 10 && flameScaled < 80) {
    Serial.println("Warning silakan periksa");
    digitalWrite(pinBuzzer, HIGH);
    delay(200);
    digitalWrite(pinBuzzer, LOW);
    delay(500);
  } else {
    Serial.println("waspada harap mengungsi");
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
  }

}
