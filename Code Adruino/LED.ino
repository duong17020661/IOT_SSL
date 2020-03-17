#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "controlled-b013c.firebaseio.com"
#define FIREBASE_AUTH "Wb97e0cjuBoRcDfMmsi2eJyvxBnhs4t55lPfYWPJ"
#define WIFI_SSID "Cao Thi Yen"
#define WIFI_PASSWORD "cy12345678"
String fireStatus = "";
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(16, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Dang ket noi ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Da ket noi ");
  Serial.println(WIFI_SSID);
  Serial.print("Dia chi IP la : ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  fireStatus = Firebase.getString("LED/1/bt");
  if (fireStatus == "ON" || fireStatus == "on") {    
    Serial.println("LED SANG");
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(16, HIGH);
  }
  else if (fireStatus == "OFF" || fireStatus == "off") {            
    Serial.println("LED TAT");
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(16, LOW);
  }
  else {
    Serial.println("Lenh dieu khien sai! Vui gui ON/OFF");
  }
}
