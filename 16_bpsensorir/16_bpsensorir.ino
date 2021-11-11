// Inisialisasi
int pinLDR = PB1;
int pinLedR = PB0;
int pinIR = PA7;
int prevIR = 0;
int flag = 0;

void setup() {
  // konfigurasi pin
  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinIR, INPUT);
}

int infraRising(int readIR){
  
  int isRising = 0;
  if(prevIR == 0 && readIR == 1) {
    isRising = 1;
  }
  prevIR = readIR;
  return isRising;
}

void loop() {
  // read input
  int ldr = map(analogRead(pinLDR), 0,4095, 0, 255);
  int readIR = digitalRead(pinIR);
  int isRising = infraRising(!readIR);

  // print
  Serial.println("ldr=" + String(ldr) + " ir="+ String(readIR) +" ir_rising=" + String(isRising));

  if(isRising) {
    flag = !flag;
  }

  if(flag) {
    analogWrite(pinLedR, ldr);
  } else {
    analogWrite(pinLedR, 0);
  }
  
}
