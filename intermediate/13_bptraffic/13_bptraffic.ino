int LR = PA0;
int LY = PA1;
int LG = PA2;


void setup() {
  pinMode(PC13, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(LY, OUTPUT);
  pinMode(LG, OUTPUT);
  
}

void loop() {
  digitalWrite(PC13, HIGH);
  delay(100);
  digitalWrite(PC13, LOW);
  delay(100);

  digitalWrite(LR, HIGH);
  delay(200);
  digitalWrite(LR, LOW);
  digitalWrite(LY, HIGH);
  delay(200);
  digitalWrite(LY, LOW);
  digitalWrite(LG, HIGH);
  delay(200);
  digitalWrite(LG, LOW);
  
  
}
