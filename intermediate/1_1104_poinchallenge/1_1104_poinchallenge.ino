// INISIALISASI
int pinLDR = A0;
int pinFlame = A1;
int pinBuzzer = 5;
int pinLedR = 6;
int pinLedY = 7;
int pinLedG = 4;


void ledYG(int y, int g){
  digitalWrite(pinLedY, y);
  digitalWrite(pinLedG, g);
}

void setup() {
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedY, OUTPUT);
  pinMode(pinLedG, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  ledYG(LOW,LOW);
  
}


int flag = 0;

void loop() {

  
  // BACA DATA
  int bacaFlame = analogRead(pinFlame);
  int flameScaled = map(bacaFlame, 800, 1023, 100, 0);

  int bacaLDR = analogRead(pinLDR); //320-920
  
//  // PRINT
//  Serial.print("Flame=");
//  Serial.print(bacaFlame);
//  Serial.print(",Scaled=");
//  Serial.print(flameScaled);
//  Serial.println();
//  
//  Serial.print("LDR=");
//  Serial.print(bacaLDR);
//  Serial.println();

  //LOGIKA
  if(flameScaled < 10) {
    Serial.println("Aman banget");
    ledYG(LOW,HIGH);
  } else if (flameScaled >= 10 && flameScaled < 80) {
    Serial.println("Warning Silahkan periksa");
    digitalWrite(pinBuzzer, HIGH);
    delay(200);
    digitalWrite(pinBuzzer, LOW);
    delay(500);
    ledYG(HIGH,LOW);

  } else {
    Serial.println("Waspada harap mengungsi");
    digitalWrite(pinBuzzer, HIGH);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
    ledYG(HIGH, HIGH);
  }

  analogWrite(pinLedR, map(bacaLDR, 0, 1023, 0, 255));

}
