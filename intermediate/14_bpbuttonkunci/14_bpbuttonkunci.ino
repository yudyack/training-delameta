// Inisialisasi
int pinLeds[] = {PA0, PA1, PA2};
int pinButtons[] = {PA5, PA6, PA7};
boolean buttonPrevState[] = {0,0,0};
boolean ledState[] = {0,0,0};



void setup() {
    Serial.begin(9600);
    // set pin
    for (size_t i = 0; i < 3; i++)
    {
        pinMode(pinLeds[i], OUTPUT);
        pinMode(pinButtons[i], INPUT); 
    }

}

void writeLeds(){
    for (size_t i = 0; i < 3; i++)
    {
        digitalWrite(pinLeds[i], ledState[i]);
    }
    
}

void loop() {
    int inputs[3];
    for (size_t i = 0; i < 3; i++)
    {
        // read input
        inputs[i] = digitalRead(pinButtons[i]);

        // print input
        Serial.print("button" + String(i) + "=" + String(inputs[i]) + " ");

        if(inputs[i] == 1 && buttonPrevState[i] == 0){
            ledState[i] = !ledState[i];
        }
        buttonPrevState[i] = inputs[i];
        
    }
    writeLeds();
    Serial.println();
}
//06
//07
//13
