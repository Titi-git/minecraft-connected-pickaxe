#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
//#include <Arduino_JSON.h>

#define A1 1

WiFiClient client;
HTTPClient http;

int flag = 0;
const char *SSID = "SSID";
const char *PWD = "Password";
const char* serverName = "hrrp://YourLocalIP:5000/click";
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
  //Serial.begin(9600);
  WiFi.begin(SSID, PWD);
  pinMode(A1, INPUT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    //Serial.println("Connecting to WiFi..");
  }
  //Serial.println("Connected to the WiFi network");
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  //Get
  String serverPath = serverName ;
  // Your Domain name with URL path or IP address with path
  http.begin(serverPath.c_str());
}

// the loop function runs over and over again forever
void loop() {
  //Check WiFi connection status
  //Serial.println(analogRead(A1));
  if(analogRead(A1) > 1000){
    if(flag == 0){
      int httpResponseCode = http.GET();
      //Serial.print("HTTP Response code: ");
      //Serial.println(httpResponseCode);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      flag = 1;
    }
  }
  else{
    flag=0;
  }

}

