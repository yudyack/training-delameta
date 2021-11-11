int R = 5;
int Y = 6;
int G = 7;
int delay_dur = 1000;
int slow_dur = 20;

int states[3];

int tombol1 = 2;
int tombol2 = 3;
int tombol3 = 4;


void setup() {
  Serial.begin(9600);
  pinMode(tombol1, INPUT);
  pinMode(tombol2, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
}

void loop() {
  int button1 = digitalRead(tombol1);
  int button2 = digitalRead(tombol2);
  digitalWrite(R, button1);
  digitalWrite(Y, button1);
}
