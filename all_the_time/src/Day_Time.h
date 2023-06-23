#include <WiFi.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include "RTClib.h"
#include <time.h>
#include <NTPClient.h>

RTC_DS3231 Rtc;             // RTC-Instanz
WiFiUDP Udp;                // WiFiUDP-Instanz 
NTPClient timeClient(Udp);  // NTPClient-Instanz

void synchronizeRTC()
{
  // Mit NTP-Server verbinden
  timeClient.begin();

  // RTC-Zeit mit NTP_Server synchronisieren
  if (timeClient.update())
  {
    Rtc.adjust(timeClient.getEpochTime());
  }

  // Verbindung schließen
  timeClient.end();
}

void start_RTC()
{
  Wire.begin();
  Rtc.begin();

  Rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  //synchronizeRTC();
}

void ac_time(int *Y, int *M, int *D, int *h, int *m, int *s)
{
  DateTime now = Rtc.now();

  *Y = now.year();
  *M = now.month();
  *D = now.day();
  *h = now.hour();
  *m = now.minute();
  *s = now.second();
  
}
