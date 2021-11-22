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
  int flameScaled = map(bacaFlame, 800, 1023, 0, 100);
  
  // PRINT
  Serial.print("Flame=");
  Serial.print(bacaFlame);
  Serial.print(",Scaled=");
  Serial.print(flameScaled);
  Serial.println();

  //LOGIKA
  analogWrite(pinLedR, map(100 - flameScaled, 0, 100, 0,255));
}
