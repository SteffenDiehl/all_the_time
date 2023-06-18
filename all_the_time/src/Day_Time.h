#include <WiFi.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include "RTClib.h"
#include <time.h>
#include <NTPClient.h>


const char* ntpServer = "de.pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

void start_RTC()
{
  Wire.begin();
  rtc.begin();

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  synchronizeRTC();
}

void ac_time(int *Y, int *M, int *D, int *h, int *m, int *s)
{
  DateTime now = rtc.now();

  *Y = now.year();
  *M = now.month();
  *D = now.day();
  *h = now.hour();
  *m = now.minute();
  *s = now.second();
  
}

void synchronizeRTC()
{
  // Mit NTP-Server verbinden
  timeClient.begin();

  // RTC-Zeit mit NTP_Server synchronisieren
  if (timeClient.update())
  {
    rtc.adjust(timeClient.getEpochTime());
  }

  // Verbindung schließen
  timeClient.end();
}
