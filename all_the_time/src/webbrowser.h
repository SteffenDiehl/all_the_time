#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char* ssid = "JustDiehlWithIt";
const char* password = "DiehlWithIt09";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

WebServer server(80);

const int NUM_TIMERS = 6;
int timerValues[NUM_TIMERS] = {60, 60, 60, 60, 60, 60};
bool timerRunning[NUM_TIMERS] = {false, false, false, false, false, false};
unsigned long timerStartTimes[NUM_TIMERS] = {0, 0, 0, 0, 0, 0};
bool timerExpired[NUM_TIMERS] = {false, false, false, false, false, false};

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Current Time: <span id=\"currentTime\"></span></h1>";

  html += "<table>";
  html += "<tr>";
  html += "<th>Timer</th>";
  html += "<th>Value</th>";
  html += "<th>Time Left</th>";
  html += "<th>Status</th>";
  html += "<th>Actions</th>";
  html += "</tr>";

  for (int i = 0; i < NUM_TIMERS; i++) {
    html += "<tr>";
    html += "<td>Timer " + String(i + 1) + "</td>";
    html += "<td>" + String(timerValues[i]) + " seconds</td>";

    if (timerRunning[i]) {
      unsigned long elapsedTime = millis() - timerStartTimes[i];
      unsigned long timeLeft = (timerValues[i] * 1000 > elapsedTime) ? (timerValues[i] * 1000 - elapsedTime) : 0;
      int secondsLeft = timeLeft / 1000;
      html += "<td><span id=\"timer" + String(i) + "\">" + String(secondsLeft) + "</span> seconds</td>";

      if (timeLeft > 0) {
        html += "<td style=\"color: yellow;\">Running</td>";
        html += "<td><a href=\"/stop" + String(i + 1) + "\">Stop</a></td>";
        if (!timerExpired[i]) {
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status" + String(i) + "').textContent = 'Running';";
          html += "</script>";
        }
      } else {
        if (!timerExpired[i]) {
          html += "<td style=\"color: red;\">Expired</td>";
          html += "<td>-</td>";
          timerExpired[i] = true;
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status" + String(i) + "').textContent = 'Expired';";
          html += "</script>";
        } else {
          html += "<td style=\"color: red;\">Expired</td>";
          html += "<td><a href=\"/start" + String(i + 1) + "\">Restart</a></td>";
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status" + String(i) + "').textContent = 'Expired';";
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
  html += "Set Timer 5 Value: <input type=\"text\" name=\"timer5\">";
  html += "<input type=\"submit\" value=\"Set\">";
  html += "<br><br>";
  html += "Set Timer 6 Value: <input type=\"text\" name=\"timer6\">";
  html += "<input type=\"submit\" value=\"Set\">";
  html += "</form>";

  html += "<script>";
  html += "function updateTime() {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/time', true);";
  html += "  xhr.onreadystatechange = function() {";
  html += "    if (xhr.readyState === 4 && xhr.status === 200) {";
  html += "      var timeData = JSON.parse(xhr.responseText);";
  html += "      document.getElementById('currentTime').textContent = timeData.currentTime;";

  for (int i = 0; i < NUM_TIMERS; i++) {
    html += "      document.getElementById('timer" + String(i) + "').textContent = timeData.timers.timer" + String(i) + ";";
  }

  html += "    }";
  html += "  };";
  html += "  xhr.send();";
  html += "}";
  html += "updateTime();";  // Call updateTime() when the page finishes loading
  html += "setInterval(updateTime, 1000);";  // Update time every second
  html += "</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}


void handleTime() {
  String currentTime = timeClient.getFormattedTime();

  String json = "{";
  json += "\"currentTime\":\"" + currentTime + "\",";
  json += "\"timers\": {";

  for (int i = 0; i < NUM_TIMERS; i++) {
    unsigned long elapsedTime = millis() - timerStartTimes[i];
    unsigned long timeLeft = (timerValues[i] * 1000 > elapsedTime) ? (timerValues[i] * 1000 - elapsedTime) : 0;
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
  int timerIndex = action.substring(6).toInt() - 1; // Extract timer index from URI

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
  String timer5Value = server.arg("timer5");
  String timer6Value = server.arg("timer6");

  if (timer5Value.length() > 0) {
    timerValues[NUM_TIMERS - 2] = timer5Value.toInt();
  }

  if (timer6Value.length() > 0) {
    timerValues[NUM_TIMERS - 1] = timer6Value.toInt();
  }

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

void web_browser_begin() {
  server.on("/", handleRoot);
  server.on("/time", handleTime);
  server.on("/start1", handleStartStop);
  server.on("/start2", handleStartStop);
  server.on("/start3", handleStartStop);
  server.on("/start4", handleStartStop);
  server.on("/stop1", handleStartStop);
  server.on("/stop2", handleStartStop);
  server.on("/stop3", handleStartStop);
  server.on("/stop4", handleStartStop);
  server.on("/start5", handleStartStop);
  server.on("/start6", handleStartStop);
  server.on("/stop5", handleStartStop);
  server.on("/stop6", handleStartStop);
  server.on("/set", handleSet);

  server.begin();
}

void web_browser_end(){
  server.close();
}

void loop() {
  server.handleClient();
}