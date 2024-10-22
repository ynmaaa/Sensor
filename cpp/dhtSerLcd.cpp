#include <Wire.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define Ser 2

#define DHT_PIN 16
DHT dht(DHT_PIN, DHT22);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  myservo.attach(Ser);

}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  if(isnan(suhu) || isnan(kelembapan)){
    Serial.println("Sensor Rusak");
  } else {
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print(" C\t");
    Serial.print("Kelembapan: ");
    Serial.print(kelembapan);
    Serial.println(" %");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Suhu: ");
    lcd.print(suhu);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Kelembapan: ");
    lcd.print(kelembapan);
  }
  delay(2000);

  if ( suhu > 50 ){
    myservo.write(180);
    delay(1000);
  }
  else if ( suhu < 50){
    myservo.write(0);
    delay(1000);
  }

}