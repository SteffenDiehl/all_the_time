#include <Arduino.h>
#include <WiFi.h>
//#include <web_server.h>
#include <Day_Time.h>
#include <display_anzeige.h>
#include <RotaryEncoder.h>
#include <Menue_Steuerung.h>
#include <Wire.h>

int menue = 0;
int last_menue = 1;
int back_menue = 1;
int rotary = 1;
int position = 1;
int position_max = 0;
unsigned long previous_Millis = 0;
unsigned long last_action;
int act_timer = 0;
unsigned long timer_1 = 0;
unsigned long timer_2 = 0;
unsigned long timer_3 = 0;
unsigned long timer_4 = 0;
unsigned long timer_5 = 0;
int WiFi = 0;
int WebServer = 0;
int feste_Timer[];

#define Button_30s 15
#define Button_1min 16
#define Button_5min 17
#define Button_15min 18

#define Rotary_IN1 14
#define Rotary_IN2 27
#define Rotary_IN3 26 //Button Rotary

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);
// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(Rotary_IN1, Rotary_IN2, RotaryEncoder::LatchMode::TWO03);


const char* ssid = "Techniker_RDF";
const char* password = "Techniker_Schule";

void setup() {
  pinMode(Button_30s, INPUT);
  pinMode(Button_1min, INPUT);
  pinMode(Button_5min, INPUT);
  pinMode(Button_15min, INPUT);
  pinMode(Rotary_IN3, INPUT);
  Serial.begin(115200);

// RTC_lib
  start_RTC();

// Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());

//  server.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();

//  get_time();
}

void loop() {
  unsigned long actual_Millis = millis();
//  serve();
  display_Anzeige(&menue, &position, &position_max, &act_timer, &timer_1, &timer_2, &timer_3, &timer_4, &timer_5);
  encoder.tick();
  unsigned int newposition = encoder.getPosition();

  if(rotary != newposition){
    last_action = actual_Millis;
    if(menue != 0){
      if(newposition < rotary && position > 1){
        position--;
      }
      else if (newposition > rotary && position < position_max){
        position++;
      }
      rotary = newposition;
    }
    else if(menue == 0){
      menue = last_menue;
      position = 1;
    }
  }

  if(digitalRead(Rotary_IN3) == LOW && menue != 0){
    while (digitalRead(Rotary_IN3) == LOW)
    {
      delay(1);
    }
    Rotary_Click(&menue, &position, &back_menue, &WiFi, &WebServer);
  }

  if(digitalRead(Rotary_IN3) == LOW && menue == 0){
    while (digitalRead(Rotary_IN3) == LOW)
    {
      delay(1);
    }
    menue = last_menue;
    position = 1;
  }  


  if((last_action+60000) <= actual_Millis && menue != 0){
    last_menue = menue;
    menue = 0;
  }

}