int led[] = {5, 6, 7};
int tombol[] = {2, 3, 4};

int state[] = {0, 0, 0};
int prev[] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  for (size_t i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
    pinMode(tombol[i], INPUT);
  }
}

void loop() {

  for (size_t i = 0; i < 3; i++) {
    int current = digitalRead(tombol[i]);
    if (current == 1 && prev[i] == 0) {
      state[i] = !state[i];
      digitalWrite(led[i], state[i]);
    }
    prev[i] = current;
  }
}
