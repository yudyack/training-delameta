
int pinBuzz1 = PA0;
int pinBuzz2 = PA1;

int pinBuzzs[] = {pinBuzz1, pinBuzz2};

// Melody melody("c d f f f f f f f f");

void setup() {
  Serial.begin(9600);
  // melody.setTempo(120);
}

void loop() {
  
  Serial.println("print");
  tone(pinBuzz1, 500);
  // melody.restart();


  // while(melody.hasNext()){
  //   melody.next();

  //   unsigned int freq = melody.getFrequency(); 
  //   unsigned long duration = melody.getDuration();
  //   int loudness = melody.getLoudness();
  //   Serial.println("freq=" + String(freq));

  //   freq > 0 ? tone(pinBuzz1,freq,duration) : noTone(pinBuzz1);

  //   // loudness could be use with a mapping, according to your buzzer or sound-producing hardware
  //   //For Example :
  //   /*
  //     { 
  //       int realIntensity = map(loudness, -4, 4, 0, 1023);
  //       myBuzzer.setIntensity(realIntensity);
  //     }


  //   */

  // }
}