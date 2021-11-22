int R = 5;
int Y = 6;
int G = 7;
int delay_dur = 1000;

void setup() {
  for (size_t i = 5; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (size_t i = 5; i <= 7; i++) {
    digitalWrite(i, HIGH);
    delay(delay_dur);
    digitalWrite(i, LOW);
  }
}
