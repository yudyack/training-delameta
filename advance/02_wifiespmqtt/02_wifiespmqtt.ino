#include <PubSubClient.h>
#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>
#include "SoftwareSerial.h"

char ssid[] = "Bleua";        // your network SSID (name)
char pass[] = "yudhyapw";     // your network password
int status = WL_IDLE_STATUS;  // the Wifi radio's status
unsigned long lastSend;
int pinR = 13;
int pinY = 12;
int pinG = 11;
int pinFlame = A4;
int pinLdr = A5;

// Initialize the Ethernet client object
WiFiEspClient espClient;
PubSubClient client(espClient);

SoftwareSerial Serialx(2,
                       3);  // RX, TX   //ESP8266 RX,TX connected to these pins

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  Serialx.begin(9600);
  // initialize ESP module
  WiFi.init(&Serialx);
  pinMode(pinR, OUTPUT);
  pinMode(pinY, OUTPUT);
  pinMode(pinG, OUTPUT);

  pinMode(pinFlame, INPUT);
  pinMode(pinLdr, INPUT);

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true)
      ;
  }

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
    lastSend = 0;
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");

  // connect to MQTT server
  client.setServer("broker.hivemq.com", 1883);
  client.setCallback(callback);
}

// print any message received for subscribed topic
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Pesan diterima [");
  Serial.print(topic);
  Serial.println("] ");
  //==============================================================
  if (strcmp(topic, "yudhyapw/lampu") == 0)  // Membandingkan 2 buah String
  {
    for (int i = 0; i < length; i++) {
      char receivedChar = (char)payload[i];
      if (receivedChar == '0') {
        // Jalankan Perintah1
        Serial.println("JALANKAN PERINTAH 0");
        digitalWrite(pinR, HIGH);
      }
      if (receivedChar == '1') {
        // Jalankan Perintah0
        Serial.println("JALANKAN PERINTAH 1");
        digitalWrite(pinR, LOW);
      }
      if (receivedChar == '2') {
        // Jalankan Perintah1
        Serial.println("JALANKAN PERINTAH 2");
        digitalWrite(pinY, HIGH);
      }
      if (receivedChar == '3') {
        // Jalankan Perintah0
        Serial.println("JALANKAN PERINTAH 3");
        digitalWrite(pinY, LOW);
      }
      if (receivedChar == '4') {
        // Jalankan Perintah1
        Serial.println("JALANKAN PERINTAH 4");
        digitalWrite(pinG, HIGH);
      }
      if (receivedChar == '5') {
        // Jalankan Perintah0
        Serial.println("JALANKAN PERINTAH 5");
        digitalWrite(pinG, LOW);
      }
    }
  }
  //==============================================================
}

void pushdata() {
  // Ambil Data / Baca Sensor
  int datax = random(10, 100);
  int readFlame = analogRead(pinFlame);
  int readLdr = analogRead(pinLdr);

  // POST TO SERIAL
  Serial.print("Sensor 1 :");
  Serial.print(datax);
  Serial.println();

  // POST TO MQTT
  client.publish("yudhyapw/datax", String(datax).c_str());  // Convert to String
  client.publish("yudhyapw/flame", String(readFlame).c_str());
  client.publish("yudhyapw/ldr", String(readLdr).c_str());
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }
  if (millis() - lastSend > 5000) {  // Update and send only after 1 seconds
    pushdata();
    lastSend = millis();
  }
  client.loop();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect, just a name to identify the client
    if (client.connect("yudhyadevice101")) {
      Serial.println("connected");

      // client.publish("outpic","Hello World");
      client.subscribe("yudhyapw/lampu", 0);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
