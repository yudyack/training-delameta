// Inisialisasi
int pinLDR = PB1;
int pinLedR = PB0;


void setup() {
  // konfigurasi pin
  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(pinLedR, OUTPUT);
}

void loop() {
  // read input
  int ldr = map(analogRead(pinLDR), 0,4095, 0, 255);

  // print
  Serial.println("ldr=" + String(ldr));

  // logic
  if(ldr < 100 ) {
    analogWrite(pinLedR, 0);
  } else if (ldr < 200) {
    analogWrite(pinLedR, 140);
  } else if (ldr < 255) {
    analogWrite(pinLedR, 255);
  }
  
}
