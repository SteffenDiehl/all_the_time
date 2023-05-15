#include <Arduino.h>
#include <WiFi.h>
#include <web_server.cpp>
#include <Day_Time.cpp>
#include <display_anzeige.cpp>

int menue = 999,
int previous_Millis = 0;

const char* ssid = "Techniker_RDF";
const char* password = "TEchniker_Schule";

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();

  get_time();
}

void loop() {
  serve();
  display_Anzeige(menue);

}