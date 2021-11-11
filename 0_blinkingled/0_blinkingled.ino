int R = 5;
int Y = 6;
int G = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R,HIGH);
  digitalWrite(Y,HIGH);
  digitalWrite(G,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  delay(100);
 
}
