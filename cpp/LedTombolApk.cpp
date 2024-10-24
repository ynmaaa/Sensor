#include <FirebaseESP32.h>
#include <WiFi.h>
#define AUTH " api firebase"
#define HOST " link firebase"
#define LED 2

String ssid = " insert ssid wifi ";
String pass = " insert pass wifi";

FirebaseData firebaseData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }
  Serial.println("&&");
  Firebase.begin(HOST, AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Firebase.getString(firebaseData, "/UGM/pompa")) {
    String but = firebaseData.stringData();
    if (but == "1") {
      digitalWrite(LED, HIGH);
      Serial.println("Nyala");
    }
    else {
      digitalWrite(LED, LOW);
      Serial.println("Mati");
    }
  }
  delay(500);
}