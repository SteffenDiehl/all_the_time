#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include <Wire.h>
#include "RTClib.h"
#include <stdio.h>

#include <webbrowser.h>
#include <Day_Time.h>
#include <display_anzeige.h>
#include <Menue_Steuerung.h>
#include <neo_pixel.h>

//Variablen
int menue = 0;
int last_menue = 1;
int back_menue = 1;
int rotary = 1;
int rotary_click = 0;
int position = 1;
int position_max = 0;
unsigned long previous_Millis = 0;
unsigned long last_millis = 0;
unsigned long last_action;
int act_timer = 0;//active timer
unsigned long timer_1 = 0;
unsigned long timer_2 = 0;
unsigned long timer_3 = 0;
unsigned long timer_4 = 0;
unsigned long timer_5 = 0;
unsigned long timer[5];
int timer_pause[5] = {0, 0, 0, 0, 0};
int timer_anz = 0;
int timer_out = 0;//abgelaufene timer
int Wi_Fi = 0;
int Wi_Fi_act = 0;
int Web_Server = 0;
int Web_Server_act = 0;
String feste_Timer_Name[10] = {"Nudeln 7min", "Kartoffeln 14min", "Steak medium", "Mittag 1h", "Mittag 30min", "-", "-", "-", "-", "-"};
unsigned long feste_Timer[10] = {420000, 840000, 90000, 3600000, 1800000, 0, 0, 0, 0, 0};
int year;
int month;
int day;
int hour;
int minute;
int second;
unsigned long rtc_last_sync = 0;
int button_click = 0;
int ledoff_click = 0;
int rotary_move = 0;

//buttons
#define Button_30s 15
#define Button_1min 16
#define Button_5min 17
#define Button_15min 18
//rotary
#define Rotary_IN1 14
#define Rotary_IN2 27
#define Rotary_IN3 26 //Button Rotary
//neopixel
#define neopixel_pin 5
#define neopixel_anz 56
#define summer 2

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::FOUR3);
// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(Rotary_IN1, Rotary_IN2, RotaryEncoder::LatchMode::TWO03);

const char* ssid = "HUAWEI P20 Pro";
const char* password = "AndreasSeisAurach";

void setup() {
  pinMode(Button_30s, INPUT);
  pinMode(Button_1min, INPUT);
  pinMode(Button_5min, INPUT);
  pinMode(Button_15min, INPUT);
  pinMode(Rotary_IN3, INPUT);
  pinMode(summer, OUTPUT);
  Serial.begin(115200);

  //display
  start_display();

//RTC_lib
  start_RTC();

//neopixel
  neopixel_start(neopixel_anz, neopixel_pin);
  
  encoder.setPosition(10000);
}

void loop() {
  unsigned long actual_Millis = millis();

  //Actual Time
  if(actual_Millis > rtc_last_sync + 604800000 && Wi_Fi_act){
    synchronizeRTC();
  }
  ac_time(&year, &month, &day, &hour, &minute, &second);

  //Wifi
  if(Wi_Fi && !Wi_Fi_act){//wenn verbunden Wi_Fi_act = 1 setzen
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
    }
    Wi_Fi_act = 1;
    synchronizeRTC();
  }
  else if(!Wi_Fi && Wi_Fi_act){
    WiFi.disconnect();
    Wi_Fi_act = 0;

    web_browser_end();
    Web_Server_act = 0;
  }

  //Webserver
  if(Web_Server && !Web_Server_act && Wi_Fi_act){
    web_browser_begin(feste_Timer, feste_Timer_Name, &timer_1, &timer_2, &timer_3, &timer_4, &timer_5, timer);
    Web_Server_act = 1;
  }
  else if(!Web_Server && Web_Server_act){
    web_browser_end();
    Web_Server_act = 0;
  }

  if(Web_Server_act){
    web_browser(Y, M, D, h, m, s, feste_Timer, feste_Timer_Name);
  }

  
  neo.clear();

  //OLED Anzeige
  display_Anzeige(&menue, &position, &position_max, &act_timer, &timer_1, &timer_2, &timer_3, &timer_4, &timer_5, &hour, &minute, &second, &day, &month, &year, feste_Timer_Name, &Wi_Fi_act, &timer_out, timer, timer_pause, &timer_anz);
  
  if(!rotary_move){
    //rotary drehung
    encoder.tick();
    unsigned int newposition = encoder.getPosition();

    if(rotary != newposition){//Rotary bewegung
      last_action = actual_Millis;
      if(menue == 8){//timer einstellen
        position = 1;
        switch (act_timer)
        {
        case 0:
          if(newposition < rotary && timer_1 > 0){
            timer_1 -= 1000;
            neopixel_rotary_rotate_(-1);
          }
          else if (newposition > rotary && timer_1 < 86400000){
            timer_1 += 1000;
            neopixel_rotary_rotate_(1);
          }
          break;
          
        case 1:
          if(newposition < rotary && timer_2 > 0){
            timer_2 -= 1000;
            neopixel_rotary_rotate_(-1);
          }
          else if (newposition > rotary && timer_2 < 86400000){
            timer_2 += 1000;
            neopixel_rotary_rotate_(1);
          }
          break;
          
        case 2:
          if(newposition < rotary && timer_3 > 0){
            timer_3 -= 1000;
            neopixel_rotary_rotate_(-1);
          }
          else if (newposition > rotary && timer_3 < 86400000){
            timer_3 += 1000;
            neopixel_rotary_rotate_(1);
          }
          break;
          
        case 3:
          if(newposition < rotary && timer_4 > 0){
            timer_4 -= 1000;
            neopixel_rotary_rotate_(-1);
          }
          else if (newposition > rotary && timer_4 < 86400000){
            timer_4 += 1000;
            neopixel_rotary_rotate_(1);
          }
          break;
          
        case 4:
          if(newposition < rotary && timer_5 > 0){
            timer_5 -= 1000;
            neopixel_rotary_rotate_(-1);
          }
          else if (newposition > rotary && timer_5 < 86400000){
            timer_5 += 1000;
            neopixel_rotary_rotate_(1);
          }
          break;
        
        default:
          break;
        }
      }
      else if(menue != 0){
        if(newposition < rotary && position > 1){
          position--;
        }
        else if (newposition > rotary && position < position_max){
          position++;
        }
        if(newposition < rotary){
          neopixel_rotary_rotate_(-1);
        }
        else if (newposition > rotary){
          neopixel_rotary_rotate_(1);
        }
      }
      else if(menue == 0){
        menue = last_menue;
        position = 1;
      }
      rotary = newposition;
      rotary_move++; 
    }
  }

  if(digitalRead(Rotary_IN3) == LOW && menue == 9 && rotary_click == 0){//Rotary Button
    last_action = actual_Millis;
    rotary_click = 1;
    if(feste_Timer[position-1] == 0){
    }
    else{
      Rotary_Click(&menue, &position, &back_menue, &Wi_Fi, &Web_Server, &act_timer, &timer_1, &timer_2, &timer_3, &timer_4, &timer_5, feste_Timer, timer, Wi_Fi_act, &timer_anz, timer_pause, &timer_out);
    }
  }

  else if (digitalRead(Rotary_IN3) == LOW && menue == 8 && rotary_click == 0){
    last_action = actual_Millis;
    rotary_click = 1;
    Rotary_Click(&menue, &position, &back_menue, &Wi_Fi, &Web_Server, &act_timer, &timer_1, &timer_2, &timer_3, &timer_4, &timer_5, feste_Timer, timer, Wi_Fi_act, &timer_anz, timer_pause, &timer_out);
  }
  else if(digitalRead(Rotary_IN3) == LOW && menue != 0 && rotary_click == 0 && menue < 20){
    last_action = actual_Millis;
    rotary_click = 1;
    Rotary_Click(&menue, &position, &back_menue, &Wi_Fi, &Web_Server, &act_timer, &timer_1, &timer_2, &timer_3, &timer_4, &timer_5, feste_Timer, timer, Wi_Fi_act, &timer_anz, timer_pause, &timer_out);
  }

  else if(digitalRead(Rotary_IN3) == LOW && menue == 0 && rotary_click == 0){
    last_action = actual_Millis;
    rotary_click = 1;
    menue = last_menue;
    position = 1;
  }

  if(digitalRead(Button_30s) && digitalRead(Button_15min) && ledoff_click == 0){//neopixel on/off
    ledoff();
    switch (act_timer)
    {
    case 0:
      menue = 1;
      position = 1;
      timer_1 = 0;
      break;
      
    case 1:
      menue = 2;
      position = 1;
      timer_2 = 0;
      break;
      
    case 2:
      menue = 3;
      position = 1;
      timer_3 = 0;
      break;
      
    case 3:
      menue = 4;
      position = 1;
      timer_4 = 0;
      break;
      
    case 4:
      menue = 5;
      position = 1;
      timer_5 = 0;
      break;
    
    default:
      break;
    }
  }
  else if(digitalRead(Button_30s) && digitalRead(Button_1min) && ledoff_click == 0){//brightness-
    brighness_decrease();
    switch (act_timer)
    {
    case 0:
      menue = 1;
      position = 1;
      timer_1 = 0;
      break;
      
    case 1:
      menue = 2;
      position = 1;
      timer_2 = 0;
      break;
      
    case 2:
      menue = 3;
      position = 1;
      timer_3 = 0;
      break;
      
    case 3:
      menue = 4;
      position = 1;
      timer_4 = 0;
      break;
      
    case 4:
      menue = 5;
      position = 1;
      timer_5 = 0;
      break;
    
    default:
      break;
    }
  }
  else if(digitalRead(Button_30s) && digitalRead(Button_5min) && ledoff_click == 0){//brightness+
    brightness_increase();
    switch (act_timer)
    {
    case 0:
      menue = 1;
      position = 1;
      timer_1 = 0;
      break;
      
    case 1:
      menue = 2;
      position = 1;
      timer_2 = 0;
      break;
      
    case 2:
      menue = 3;
      position = 1;
      timer_3 = 0;
      break;
      
    case 3:
      menue = 4;
      position = 1;
      timer_4 = 0;
      break;
      
    case 4:
      menue = 5;
      position = 1;
      timer_5 = 0;
      break;
    
    default:
      break;
    }
  }
  else{
  if(digitalRead(Button_30s) && act_timer != 5 && !button_click){//new timer +30s
    button_click = 1;
    last_action = actual_Millis;
    menue = 8;
    switch (act_timer)
      {
      case 0:
        timer_1 += 30000;
        break;
        
      case 1:
        timer_2 += 30000;
        break;
        
      case 2:
        timer_3 += 30000;
        break;
        
      case 3:
        timer_4 += 30000;
        break;
        
      case 4:
        timer_5 += 30000;
        break;
      
      default:
        break;
      }
  }

  if(digitalRead(Button_1min) && act_timer != 5 && !button_click){//new timer +1min
    button_click = 1;
    last_action = actual_Millis;
    menue = 8;
    switch (act_timer)
      {
      case 0:
        timer_1 += 60000;
        break;
        
      case 1:
        timer_2 += 60000;
        break;
        
      case 2:
        timer_3 += 60000;
        break;
        
      case 3:
        timer_4 += 60000;
        break;
        
      case 4:
        timer_5 += 60000;
        break;
      
      default:
        break;
      }
  }

  if(digitalRead(Button_5min) && act_timer != 5 && !button_click){//new timer +5min
    button_click = 1;
    last_action = actual_Millis;
    menue = 8;
    switch (act_timer)
      {
      case 0:
        timer_1 += 300000;
        break;
        
      case 1:
        timer_2 += 300000;
        break;
        
      case 2:
        timer_3 += 300000;
        break;
        
      case 3:
        timer_4 += 300000;
        break;
        
      case 4:
        timer_5 += 300000;
        break;
      
      default:
        break;
      }
  }

  if(digitalRead(Button_15min) && act_timer != 5 && !button_click){//new timer +15min
    button_click = 1;
    last_action = actual_Millis;
    menue = 8;
    switch (act_timer)
      {
      case 0:
        timer_1 += 900000;
        break;
        
      case 1:
        timer_2 += 900000;
        break;
        
      case 2:
        timer_3 += 900000;
        break;
        
      case 3:
        timer_4 += 900000;
        break;
        
      case 4:
        timer_5 += 900000;
        break;
      
      default:
        break;
      }
  }
  }

  for(int i = 0; i<5; i++){//timer--
    if(timer[i] > 0 + (actual_Millis - last_millis)){
      if(timer_pause[i]){
        continue;
      }
      timer[i] -= (actual_Millis - last_millis);
    }
    else if (timer[i] > 0)
    {
      timer[i] = 0;
      timer_out++;
      menue = 21;
    }
    
  }
  
  if(menue > 20 && timer_out > 0 && digitalRead(Rotary_IN3) == LOW && rotary_click == 0){//timer reset
    rotary_click = 1;
    act_timer--;
    timer_out--;
    timer_anz = 0;
    switch (act_timer)
    {
    case 0:
      timer_1 = 0;
      menue = 1;
      position = 1;
      break;
      
    case 1:
      if(timer[0] == 0){
        timer_1 = timer_2;
        timer[0] = timer[1];
      }
      timer_2 = 0;
      timer[1] = 0;
      if(timer_out == 0){
        menue = 2; 
      }
      position = 1;
      break;
      
    case 2:
      if(timer[0] == 0){
        timer_1 = timer_2;
        timer_2 = timer_3;
        timer[0] = timer[1];
        timer[1] = timer[2];
      }
      else if(timer[1] == 0){
        timer_2 = timer_3;
        timer[1] = timer[2];
      }
      timer_3 = 0;
      timer[2] = 0;
      if(timer_out == 0){
        menue = 3; 
      }
      position = 1;
      break;
      
    case 3:
      if(timer[0] == 0){
        timer_1 = timer_2;
        timer_2 = timer_3;
        timer_3 = timer_4;
        timer[0] = timer[1];
        timer[1] = timer[2];
        timer[2] = timer[3];
      }
      else if(timer[1] == 0){
        timer_2 = timer_3;
        timer_3 = timer_4;
        timer[1] = timer[2];
        timer[2] = timer[3];
      }
      else if(timer[2] == 0){
        timer_3 = timer_4;
        timer[2] = timer[3];
      }
      timer_4 = 0;
      timer[3] = 0;
      if(timer_out == 0){
        menue = 4; 
      }
      position = 1;
      break;
      
    case 4:
      if(timer[0] == 0){
        timer_1 = timer_2;
        timer_2 = timer_3;
        timer_3 = timer_4;
        timer_4 = timer_5;
        timer[0] = timer[1];
        timer[1] = timer[2];
        timer[2] = timer[3];
        timer[3] = timer[4];
      }
      else if(timer[1] == 0){
        timer_2 = timer_3;
        timer_3 = timer_4;
        timer_4 = timer_5;
        timer[1] = timer[2];
        timer[2] = timer[3];
        timer[3] = timer[4];
      }
      else if(timer[2] == 0){
        timer_3 = timer_4;
        timer_4 = timer_5;
        timer[2] = timer[3];
        timer[3] = timer[4];
      }
      else if(timer[3] == 0){
        timer_4 == timer_5;
        timer[3] = timer[4];
      }
      timer_5 = 0;
      timer[4] = 0;
      if(timer_out == 0){
        menue = 5; 
      }
      position = 1;
      break;
    
    default:
      break;
    }
  }

  if(timer_out != 0){
    menue = 21;
    digitalWrite(summer, HIGH);
    neopixel_time_blink(actual_Millis);
  }

  if((last_action+60000) <= actual_Millis && menue != 0 && timer_out == 0){//Bildschirmschoner
    last_menue = menue;
    menue = 0;
  }
  
  neopixel_leiste(Wi_Fi, Wi_Fi_act, Web_Server, Web_Server_act, timer_1, timer_2, timer_3, timer_4, timer_5, timer);
  neopixel_time(timer_1, timer_2, timer_3, timer_4, timer_5, timer, timer_out, timer_anz);
  neopixel_rotary_rotate();
  if(rotary_click){neopixel_rotary_press();}

  if(digitalRead(Rotary_IN3) == HIGH && rotary_click == 1 && actual_Millis >= (last_action + 500)){//reset rotary_click
    rotary_click = 0;
  }

  if(!digitalRead(Button_30s) && !digitalRead(Button_1min) && !digitalRead(Button_5min) && !digitalRead(Button_15min) && ledoff_click && actual_Millis >= last_action + 500){//reset ledoff_click
    ledoff_click = 0;
  }

  if(!digitalRead(Button_30s) && !digitalRead(Button_1min) && !digitalRead(Button_5min) && !digitalRead(Button_15min) && button_click && actual_Millis >= last_action + 500){//reset ledoff_click
    button_click = 0;
  }

  if(rotary_move && actual_Millis >= last_action + 25){
    rotary_move = 0;
  }

  last_millis = actual_Millis;
  neo.show();
}