int R = 5;
int Y = 6;
int G = 7;
int delay_dur = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R,HIGH);
  delay(delay_dur);
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  delay(delay_dur);
  digitalWrite(Y,LOW);
  digitalWrite(G,HIGH);
  delay(delay_dur);
  digitalWrite(G,LOW);
  digitalWrite(Y,HIGH);
  delay(delay_dur);
  digitalWrite(Y,LOW);
}
