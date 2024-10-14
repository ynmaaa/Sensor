#include "DHT.h"
#define DHT22PIN 13


DHT dht(DHT22PIN, DHT22);

void setup() {
  pinMode(15, OUTPUT);

  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(1000);

  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humi);

  if(temp > 30){
    digitalWrite(15, HIGH);
  }else if(temp < 25){
    digitalWrite(15, LOW);
  }
  delay(1000);
}
