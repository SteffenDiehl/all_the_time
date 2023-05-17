#include <Arduino.h>
#include <WiFi.h>
//#include <web_server.h>
#include <Day_Time.h>
#include <display_anzeige.h>
#include <RotaryEncoder.h>
#include <Menue_Steuerung.h>

int menue = 0;
int last_menue = 0;
int position = 1;
int previous_Millis = 0;
int last_action;

#define Button_30s 15
#define Button_1min 16
#define Button_5min 17
#define Button_15min 18

#define Rotary_IN1 14
#define Rotary_IN2 27
#define Rotary_IN3 26 //Button Rotary

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);
// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(Rotary_IN1, Rotary_IN2, RotaryEncoder::LatchMode::TWO03);


const char* ssid = "Techniker_RDF";
const char* password = "TEchniker_Schule";

void setup() {
  pinMode(Button_30s, INPUT);
  pinMode(Button_1min, INPUT);
  pinMode(Button_5min, INPUT);
  pinMode(Button_15min, INPUT);
  pinMode(Rotary_IN3, INPUT);
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

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

//  get_time();
}

void loop() {
  int actual_Millis = millis();
//  serve();
  display_Anzeige(&menue, &position);
  encoder.tick();
  int newposition = encoder.getPosition();

  if(position != newposition and menue <= 50){
    last_action = actual_Millis;
    if(menue != 0){
      position = newposition;
    }
    else{
      menue = last_menue;
    }
  }
  if(digitalRead(Rotary_IN3) == HIGH and menue <= 50){
    Rotary_Click(&menue, &position);

  }


  if((last_action+60000) <= actual_Millis){
    last_menue = menue;
    menue = 0;
  }
  
}