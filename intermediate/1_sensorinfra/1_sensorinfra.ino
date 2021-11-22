int led[] = {5, 6, 7};
int tombol[] = {2, 3, 4};

int led_state[] = {1, 0, 0};
int input_prev_state[] = {0, 0, 0};

void setup() {
  Serial.begin(9600);
  for (size_t i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
    pinMode(tombol[i], INPUT);
  }

  
  Serial.println("SYSTEM START:");
}

boolean gate_state = 0;

void writeLed() {
  for(int i = 0; i < 3; i++){
    digitalWrite(led[i],led_state[i]);
  }
}

void loop() {
  writeLed();
  int bacaTombol = digitalRead(tombol[0]);
  int bacaInfra = digitalRead(tombol[1]);

//  Serial.println("Tombol="+String(bacaTombol)+",SensorInfra="+String(bacaInfra));

  if(bacaTombol == 1 && input_prev_state[0] == 0 && gate_state == 0) {
    gate_state = 1;
    Serial.println("palang selamat datang silakan ambil tiket");
    Serial.println("gerbang dibuka");
    led_state[0] = 0;
    led_state[2] = 1;
    writeLed();
    delay(500);
  }
  input_prev_state[0] = bacaTombol;

  if(bacaInfra == 0) {
    if(gate_state == 1) {
      gate_state = 0;
      Serial.println("gerbang ditutup"); 
      led_state[0] = 1;
      led_state[2] = 0;
      writeLed();
    }
  }
}
