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
  pinMode(tombol3, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}



void loop() {
  int baca_tombol1 = digitalRead(tombol1);
  digitalWrite(R, baca_tombol1);

  int baca_tombol2 = digitalRead(tombol2);
  digitalWrite(Y, baca_tombol2);

  int baca_tombol3 = digitalRead(tombol3);
  digitalWrite(G, baca_tombol3);

  Serial.println("Kondisi tombol: " + String(baca_tombol1)+ ", tombol2: " + String (baca_tombol2) + ", tombol3: " + String (baca_tombol3));


}
