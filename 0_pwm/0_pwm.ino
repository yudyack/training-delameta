int R = 5;
int Y = 6;
int delay_dur = 1000;
int slow_dur = 20;

void setup() {
  Serial.begin(9600);
  for (size_t i = 5; i < 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void slow_high(int pin) {
  for (size_t i = 0; i < 256; i++) {
    analogWrite(pin, i);
//    float hasil = map(i,0,255,0,5)
    float hasil = i/255.0 * 5.0;
    Serial.println("DATA :" + String(hasil) + " Volt");
    delay(slow_dur);
  }
}

void slow_low(int pin) {
 for (size_t i = 255; i > 0; i--) {
   analogWrite(pin, i);
//    float hasil = map(i,0,255,0,5)
    float hasil = i/255.0 * 5.0;
    Serial.print("DATA :");
    Serial.print(hasil);
    Serial.println();
    delay(slow_dur);
 }
}

void loop() {
  slow_high(R);
  slow_low(R);
  slow_high(Y);
  slow_low(Y);
}
