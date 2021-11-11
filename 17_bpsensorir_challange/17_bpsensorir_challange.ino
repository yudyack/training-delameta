// inisialisasi
int pinLDR = PB1;
int pinIR = PB0;
int pinLedR = PA7;
int pinLedY = PA6;
int pinLedG = PA5;

int prev = 0;
int toggle = 0;


void setup(){
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedY, OUTPUT);
  pinMode(pinLedG, OUTPUT);

  pinMode(pinIR, INPUT);
  pinMode(pinLDR, INPUT);
}

int isRising(int input) {
  int isRising = 0;
  if(prev == 0 && input == 1) {
    isRising = 1;
  }
  prev = input;
  return isRising;
}

void writeLED(int r, int y, int g){
  digitalWrite(pinLedR, r);
  digitalWrite(pinLedY, y);
  digitalWrite(pinLedG, g);
}


void loop(){
  // baca sensor
  int readLDR = map(analogRead(pinLDR), 0, 4095, 255, 0);
  int readIR = !digitalRead(pinIR);
  int rising = isRising(readIR);

  Serial.println("ldr,ir,rising=" +String(readLDR) + "," + String(readIR) + "," + String(rising));

  if(rising) toggle = !toggle;

  if(toggle) {
    if(readLDR < 100) {
      writeLED(1,0,0);
    } else if(readLDR < 200) {
      writeLED(0,1,0);
    } else {
      writeLED(0,0,1);
    }
  } else {
    writeLED(0,0,0);
  }

  
}
