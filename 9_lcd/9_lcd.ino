//Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
//harus cari alamatnnya dulu -> I2C scanner arduino
//pakai library wire
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  lcd.begin();
}

void loop() {
  //Program yang akan dijalankan berulang-ulang
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(4,0); lcd.print("WELCOME");
  lcd.setCursor(5,1); lcd.print("Yudhya");
  delay(100); //Jeda waktu perulagan seama 1000 mili detik
}
