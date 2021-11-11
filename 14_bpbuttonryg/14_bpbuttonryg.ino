// Inisialisasi
int LR = PA0;
int LY = PA1;
int LG = PA2;

int pinB1 = PA5;
int pinB2 = PA6;
int pinB3 = PA7;


void setup() {
  Serial.println(9600);
  pinMode(PC13, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(LY, OUTPUT);
  pinMode(LG, OUTPUT);
  
}

void loop() {

  // READ INPUT
  int button1 = digitalRead(pinB1);
  int button2 = digitalRead(pinB2);
  int button3 = digitalRead(pinB3);

  digitalWrite(LR, button1);
  digitalWrite(LY, button2);
  digitalWrite(LG, button3);

  // LED
  digitalWrite(PC13, HIGH);
  delay(40);
  digitalWrite(PC13, LOW);
  delay(130);
  
}
