// INISIALISASI
int pinPIR = 3;
int pinBuzzer = 5;

void setup() {
  Serial.begin(9600);  
  pinMode(pinPIR, INPUT);
  pinMode(pinBuzzer, OUTPUT);
}


void loop() {
  // BACA SENSOR
  float bacaPIR_a = analogRead(pinPIR);
  int bacaPIR_d = digitalRead(pinPIR);

  // PRINT
  Serial.print("PIR=");
  Serial.print(bacaPIR_d);
  Serial.print(", PIR_a=");
  Serial.print(bacaPIR_a);
  Serial.println();

  //LOGIKA
  if(bacaPIR_d) {
    Serial.println("Awas ada maling");
    analogWrite(pinBuzzer, bacaPIR_a);
    delay(100);
    digitalWrite(pinBuzzer, LOW);
    delay(100);
  } else {
    Serial.println("aman");
  }
  
}
