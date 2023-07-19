#include <Preferences.h>
#include "WiFi.h"

Preferences pref;

String ssid;
String pswd;

const int led = 2;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pref.begin("wifiCredentials", false);
 
  ssid = pref.getString("ssid", ""); 
  pswd = pref.getString("pswd", "");

  if (ssid == "" || pswd == ""){
    Serial.println("No value found !");
  }
  else {
    WiFi.begin(ssid.c_str(), pswd.c_str());
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print('.');
      delay(1000);
    }
    Serial.println(" ");
    Serial.println("Connected");
    Serial.println(WiFi.localIP()); 
    digitalWrite(led, HIGH);
    
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}