#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

WebServer server(80);
const int NUM_TIMERS = 10;
String _feste_Timer_Name[NUM_TIMERS] = {};
unsigned long _feste_Timer[NUM_TIMERS] = {};
int Y;
int M;
int D;
int h;
int m;
int s;
bool timerRunning[NUM_TIMERS] = {false, false, false, false, false, false, false, false, false, false};
unsigned long timerStartTimes[NUM_TIMERS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool timerExpired[NUM_TIMERS] = {false, false, false, false, false, false, false, false, false, false};

unsigned long timer_1 = 0;
unsigned long timer_2 = 0;
unsigned long timer_3 = 0;
unsigned long timer_4 = 0;
unsigned long timer_5 = 0;
unsigned long timer[5];
int timer_pause[5] = {0, 0, 0, 0, 0};

void handleRoot() {
  String html = "<html><body style=\"background-color: lightblue;\">";
  html += "<h1>Current Time: <span id=\"currentTime\"></span></h1>";
  html += "<h3>Date: " + String(D) + String(M) + String(Y) + "</h3>";
  html += "<h3>Time: " + String(h) + String(m) + String(s) + "</h3>";
  html += "<h4>Team Biscuit <h4>";
  html += "<table>";
  html += "<tr>";
  html += "<th>Timer</th>";
  html += "<th>Value</th>";
  html += "<th>Time Left</th>";
  html += "<th>Status</th>";
  html += "<th>Actions</th>";
  html += "</tr>";
  html += "<th>ESP-Timer</th>";
  for (int i = 0; i < 5; i++){
    html += "<td>Timer"+ String(i) + "</td>";
    html += "<td>" + String(timer[i]) + " seconds</td>";
    html += "</tr>";
  }
  html += "<th>Web-Timer</th>";
  html += "<tr>";
  for (int i = 0; i < NUM_TIMERS; i++) {
    html += "<tr>";
    html += "<td>" + String(_feste_Timer_Name[i]) + "</td>";
    html += "<td>" + String(_feste_Timer[i]) + " seconds</td>";

    if (timerRunning[i]) {
      unsigned long elapsedTime = millis() - timerStartTimes[i];
      unsigned long timeLeft = (_feste_Timer[i] * 1000 > elapsedTime) ? (_feste_Timer[i] * 1000 - elapsedTime) : 0;
      int secondsLeft = timeLeft / 1000;
      html += "<td><span id=\"timer" + String(i) + "\">" + String(secondsLeft) + "</span> seconds</td>";

      if (timeLeft > 0) {
        html += "<td style=\"color: yellow;\">Running</td>";
        html += "<td><a href=\"/stop" + String(_feste_Timer_Name[i +1]) + "\">Stop</a></td>";
        if (!timerExpired[i]) {
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status" + String(_feste_Timer_Name[i]) + "').textContent = 'Running';";
          html += "</script>";
        }
      } else {
        if (!timerExpired[i]) {
          html += "<td style=\"color: red;\">Expired</td>";
          html += "<td>-</td>";
          timerExpired[i] = true;
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status" + String(_feste_Timer_Name[i]) + "').textContent = 'Expired';";
          html += "</script>";
        } else {
          html += "<td style=\"color: red;\">Expired</td>";
          html += "<td><a href=\"/start" + String(_feste_Timer_Name[i +1]) + "\">Restart</a></td>";
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status" + String(_feste_Timer_Name[i]) + "').textContent = 'Expired';";
          html += "</script>";
        }
      }
    } else {
      html += "<td>---</td>";
      html += "<td style=\"color: green;\"><a href=\"/start" + String(i + 1) + "\">Start</a></td>";
      // Update the status dynamically
      html += "<script>";
      html += "document.getElementById('status" + String(i) + "').textContent = '---';";
      html += "</script>";
    }

    html += "</tr>";
  }

  html += "</table>";

  html += "<br><br><form method=\"get\" action=\"/set\">";
  for(int i = 4; i < NUM_TIMERS; i++){
      html += "Set " + String(_feste_Timer_Name[i]) + " Name:  <input type=\"text\" name=\"" + String(_feste_Timer_Name[i]) + "_name\">";
      html += "Value:  <input type=\"text\" name=\"" + String(_feste_Timer_Name[i]) + "_value\">";
      html += "<input type=\"submit\" value=\"Set\">";
      if(i < (NUM_TIMERS - 1)){
        html += "<br><br>";
      }
      else{
        html += "</form>";
      }
  }

  html += "<script>";
  html += "function updateTime() {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/time', true);";
  html += "  xhr.onreadystatechange = function() {";
  html += "    if (xhr.readyState === 4 && xhr.status === 200) {";
  html += "      var timeData = JSON.parse(xhr.responseText);";
  html += "      document.getElementById('currentTime').textContent = timeData.currentTime;";
  html += "      ";

  // Update the timer values dynamically
  for (int i = 0; i < NUM_TIMERS; i++) {
    html += "      document.getElementById('timer" + String(i) + "').textContent = timeData.timers.timer" + String(i) + ";";
  }

  html += "    }";
  html += "  };";
  html += "  xhr.send();";
  html += "}";
  html += "updateTime();";  // Call updateTime() when the page finishes loading
  html += "setInterval(updateTime, 1000);";  // Update time every second
  html += "</script>setTimeout(function() { location.reload(); }, 5000);</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}


void handleTime() {

  String json = "{";
  json += "\"Time\":\"" + String(h) + String(m) + String(s) + "\",";
  json += "\"timers\": {";

  for (int i = 0; i < NUM_TIMERS; i++) {
    unsigned long elapsedTime = millis() - timerStartTimes[i];
    unsigned long timeLeft = (_feste_Timer[i] * 1000 > elapsedTime) ? (_feste_Timer[i] * 1000 - elapsedTime) : 0;
    int secondsLeft = timeLeft / 1000;

    json += "\"timer" + String(i) + "\": " + String(secondsLeft);

    if (i < NUM_TIMERS - 1) {
      json += ",";
    }
  }

  json += "}}";

  server.send(200, "application/json", json);
}

void handleStartStop() {
  String action = server.uri();
  int timerIndex = action.substring(10).toInt() - 1; // Extract timer index from URI

  if (timerIndex >= 0 && timerIndex < NUM_TIMERS) {
    if (action.startsWith("/start")) {
      timerRunning[timerIndex] = true;
      timerStartTimes[timerIndex] = millis();
    } else if (action.startsWith("/stop")) {
      timerRunning[timerIndex] = false;
      timerExpired[timerIndex] = false;
    }
  }

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void handleSet() {
  for(int i = 4; i < NUM_TIMERS; i++){
    String timerName = server.arg(_feste_Timer_Name[i] + "_name");
    String timerValue = server.arg(_feste_Timer_Name[i] + "_value");
    
    if (timerName.length() > 0) {
      _feste_Timer_Name[i] = timerName;
    }
    
    if (timerValue.length() > 0) {
      _feste_Timer[i] = timerValue.toInt() * 1000;
    }
  }

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void web_browser_begin(unsigned long ft[10] = {}, String ftn[10] = {}) {
  for(int i = 0; i<10; i++){
    _feste_Timer[i] = ft[i];
    _feste_Timer_Name[i] = ftn[i];
  }

  server.on("/", handleRoot);
  server.on("/time", handleTime);
  for (int i = 0; i < numTimers; i++) {
    char start[50];
    char stop[50];
    sprintf(start, "/start %s", _feste_Timer_Name[i]);
    server.on(start, handleStartStop);
    sprintf(stop, "/stop %s", _feste_Timer_Name[i]);
    server.on(stop, handleStartStop);
  }
  server.on("/set", handleSet);

  server.begin();
}

void web_browser_end(){
  server.close();
}

void web_browser(int _Y, int _M, int _D, int _h, int _m, int _s, unsigned long *ft, String *ftn) {
  Y = _Y;
  M = _M;
  D = _D;
  h = _h;
  m = _m;
  s = _s;
  for(int i=0; i<10; i++){
    ft[i] = _feste_Timer[i];
    ftn[i] = _feste_Timer_Name[i];
  }

  server.handleClient();
}