// INISIALISASI
int pinBuzzer = 5;
int pinLDR = A0;
int pinLedR = 6;

void setup() {
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
}


void loop() {
  // BACA DATA
  int bacaLDR = analogRead(pinLDR);
  int scaled = map(bacaLDR, 300, 1000, 0, 255);
  
  // PRINT
  Serial.print("LDR=");
  Serial.print(bacaLDR);
  Serial.println();

  //LOGIKA
  analogWrite(pinLedR, ((float) constrain(bacaLDR-300.0, 0, 1000-300))/(1000-300) * 255);
}
