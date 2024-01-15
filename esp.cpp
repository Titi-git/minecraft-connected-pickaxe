#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>

const char *SSID = "Lamotte qui a la 5g";
const char *PWD = "beex8814";
const char* serverName = "http://192.168.172.247:5000/click";

#define A1 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(SSID, PWD);
  pinMode(A1, INPUT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  WiFiClient client;
      HTTPClient http;
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);
      //Get
      String serverPath = serverName ;
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
}

void loop() {
    //Check WiFi connection status
    if(A1 == HIGH){
      int httpResponseCode = http.GET();
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
}
