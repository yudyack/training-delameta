// Inisialisasi
int pinM = PA0;
int pinY = PA1;
int pinG = PA2;

int pinB1 = PA3;
int pinB2 = PA4;
int pinB3 = PA5;


void setup() {
    // set pin
    pinMode(pinM, OUTPUT);
    pinMode(pinY, OUTPUT);
    pinMode(pinG, OUTPUT);

    pinMode(pinB1, INPUT);
    pinMode(pinB2, INPUT);
    pinMode(pinB3, INPUT);

}

void loop() {
    // read input
    int button1 = digitalRead(pinB1);
    int button2 = digitalRead(pinB2);
    int button3 = digitalRead(pinB3);


    // print
    Serial.println("button1=" + String(button1) + "button2=" + String(button2) + "button3=" + String(button3));

    // logic
    digitalWrite(pinM, button1);
    digitalWrite(pinY, button2);
    digitalWrite(pinG, button3);
}
//06
//07
//13
