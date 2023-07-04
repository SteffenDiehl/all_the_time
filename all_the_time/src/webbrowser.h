#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

WebServer server(80);
const int NUM_TIMERS = 10;
String _feste_Timer_Name[NUM_TIMERS] = {};
unsigned long  *pointer_feste_Timer_Name;
unsigned long _feste_Timer[NUM_TIMERS] = {};
unsigned long  *pointer_feste_timer;
String *pointer_feste_timer_name;
int Y;
int M;
int D;
int h;
int m;
int s;
bool timerRunning[5] = {false, false, false, false, false};
unsigned long timerStartTimes[5] = {0, 0, 0, 0, 0};
bool timerExpired[5] = {false, false, false, false, false};

unsigned long *pointer_timer_1;
unsigned long _timer_1 = 0;
unsigned long *pointer_timer_2;
unsigned long _timer_2 = 0;
unsigned long *pointer_timer_3;
unsigned long _timer_3 = 0;
unsigned long *pointer_timer_4;
unsigned long _timer_4 = 0;
unsigned long *pointer_timer_5;
unsigned long _timer_5 = 0;
unsigned long *pointer_timer;
unsigned long _timer[5];
int _timer_pause[5] = {0, 0, 0, 0, 0};

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
  for (int i = 0; i < 5; i++){
    html += "<td>Timer"+ String(i) + "</td>";
    html += "<td>" + String(_timer[i]) + " seconds</td>";
    html += "</tr>";

    if (timerRunning[i]) {
      unsigned long elapsedTime = millis() - timerStartTimes[i];
      unsigned long timeLeft = (_timer[i] * 1000 > elapsedTime) ? (_timer[i] * 1000 - elapsedTime) : 0;
      int secondsLeft = timeLeft / 1000;
      html += "<td><span id=\"timer" + String(i+1) + "\">" + String(secondsLeft) + "</span> seconds</td>";

      if (timeLeft > 0) {
        html += "<td style=\"color: yellow;\">Running</td>";
        html += "<td><a href=\"/stop Timer" + String(i+1) + "\">Stop</a></td>";
        if (!timerExpired[i]) {
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status Timer" + String(i+1) + "').textContent = 'Running';";
          html += "</script>";
        }
      } else {
        if (!timerExpired[i]) {
          html += "<td style=\"color: red;\">Expired</td>";
          html += "<td>-</td>";
          timerExpired[i] = true;
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status Timer" + String(i+1) + "').textContent = 'Expired';";
          html += "</script>";
        } else {
          html += "<td style=\"color: red;\">Expired</td>";
          html += "<td><a href=\"/start Timer" + String(i+1) + "\">Restart</a></td>";
          // Update the status dynamically
          html += "<script>";
          html += "document.getElementById('status Timer" + String(i+1) + "').textContent = 'Expired';";
          html += "</script>";
        }
      }
    } else {
      html += "<td>---</td>";
      html += "<td style=\"color: green;\"><a href=\"/start Timer" + String(i + 1) + "\">Start</a></td>";
      // Update the status dynamically
      html += "<script>";
      html += "document.getElementById('status Timer" + String(i) + "').textContent = '---';";
      html += "</script>";
    }

    html += "</tr>";
  }

  html += "</table>";

  html += "<br><br><form method=\"get\" action=\"/set\">";
  for(int i = 5; i < NUM_TIMERS; i++){
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
  html += "<script>";
  html += "function saveSelectedNumber() {";
  html += "  var dropdown = document.getElementById(\"timerSelect\");";
  html += "  var selectedNumber = dropdown.value;";
  html += "  // You can now use the selectedNumber variable to perform further actions or save the value.";
  html += "  console.log(\"Selected number: \" + selectedNumber);";
  html += "  // You can send the selectedNumber to the server using AJAX or perform any other desired action.";
  html += "}";
  html += "</script>";
  html += "</body></html>";

  html += "<select id=\"timerSelect\">";
  html += "<option value=\"_timer_1\">Timer 1</option>";
  html += "<option value=\"_timer_2\">Timer 2</option>";
  html += "<option value=\"_timer_3\">Timer 3</option>";
  html += "<option value=\"_timer_4\">Timer 4</option>";
  html += "<option value=\"_timer_5\">Timer 5</option>";
  html += "</select>";

  html += "<select id=\"festeTimerSelect\">";
  for (int i = 0; i < NUM_TIMERS; i++) {
    html += "<option value=\"_feste_Timer[" + String(i) + "]\">";
    html.concat(String(_feste_Timer_Name[i]));
    html += "</option>";

  }
  html += "</select>";

  html += "<button onclick=\"addSelectedValues()\">Add Selected Values</button>";
  html += "<script>";
  html += "function addSelectedValues() {";
  html += "  var timerDropdown = document.getElementById(\"timerSelect\");";
  html += "  var festeTimerDropdown = document.getElementById(\"festeTimerSelect\");";
  html += "  var selectedTimer = timerDropdown.value;";
  html += "  var selectedFesteTimer = festeTimerDropdown.value;";
  html += "  // Send the selected values to the server using AJAX or perform any other desired action.";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/addValues?timer=' + selectedTimer + '&festeTimer=' + selectedFesteTimer, true);";
  html += "  xhr.onreadystatechange = function() {";
  html += "    if (xhr.readyState === 4 && xhr.status === 200) {";
  html += "      console.log('Values added successfully!');";
  html += "    }";
  html += "  };";
  html += "  xhr.send();";
  html += "}";
  html += "</script>";

  html += "<button id=\"addButton\" onclick=\"addValues()\">Add Values</button>";
  html += "<script>";
  html += "function addValues() {";
  html += "  var xhr = new XMLHttpRequest();";
  html += "  xhr.open('GET', '/addValues', true);";
  html += "  xhr.onreadystatechange = function() {";
  html += "    if (xhr.readyState === 4 && xhr.status === 200) {";
  html += "      console.log('Values added successfully!');";
  html += "    }";
  html += "  };";
  html += "  xhr.send();";
  html += "}";
  html += "</script>";


  server.send(200, "text/html", html);
}


void handleTime() {

  String json = "{";
  json += "\"Time\":\"" + String(h) + String(m) + String(s) + "\",";
  json += "\"timers\": {";

  for (int i = 0; i < NUM_TIMERS; i++) {
    unsigned long elapsedTime = millis() - timerStartTimes[i];
    unsigned long timeLeft = (_timer[i] * 1000 > elapsedTime) ? (_timer[i] * 1000 - elapsedTime) : 0;
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
    String timerValue = server.arg(pointer_feste_Timer_Name[i] + "_value");
    
    if (timerName.length() > 0) {
      _feste_Timer_Name[i] = timerName;
      pointer_feste_timer_name[i] = _feste_Timer_Name[i];
    }
    
    if (timerValue.length() > 0) {
      _feste_Timer[i] = timerValue.toInt() * 1000;
      pointer_feste_timer[i] = _feste_Timer[i];
    }
  }

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}
void handleAddValues() {
  String selectedTimer = server.arg("timer");
  String selectedFesteTimer = server.arg("festeTimer");

  unsigned long* timerPointer = nullptr;
  unsigned long* festeTimerPointer = nullptr;

  if (selectedTimer == "_timer_1") {
    timerPointer = pointer_timer_1;
  } else if (selectedTimer == "_timer_2") {
    timerPointer = pointer_timer_2;
  } else if (selectedTimer == "_timer_3") {
    timerPointer = pointer_timer_3;
  } else if (selectedTimer == "_timer_4") {
    timerPointer = pointer_timer_4;
  } else if (selectedTimer == "_timer_5") {
    timerPointer = pointer_timer_5;
  }

  if (selectedFesteTimer.startsWith("_feste_Timer[")) {
    int startIndex = selectedFesteTimer.indexOf('[') + 1;
    int endIndex = selectedFesteTimer.indexOf(']');
    if (startIndex >= 0 && endIndex > startIndex) {
      String indexStr = selectedFesteTimer.substring(startIndex, endIndex);
      int index = indexStr.toInt();
      if (index >= 0 && index < NUM_TIMERS) {
        festeTimerPointer = &(_feste_Timer[index]);
      }
    }
  }

  if (timerPointer != nullptr && festeTimerPointer != nullptr) {on
    *timerPointer += *festeTimerPointer;
  }
  *pointer_timer_1 = _timer_1;
  *pointer_timer_2 = _timer_2;
  *pointer_timer_3 = _timer_3;
  *pointer_timer_4 = _timer_4;
  *pointer_timer_5 = _timer_5;

  server.send(200, "text/plain", "Values added successfully!");
}


void web_browser_begin(unsigned long ft[10] = {}, String ftn[10] = {}, unsigned long *tmr1 = nullptr, unsigned long *tmr2 = nullptr, unsigned long *tmr3 = nullptr, unsigned long *tmr4 = nullptr, unsigned long *tmr5 = nullptr, unsigned long *ts = nullptr) {
  for(int i = 0; i<10; i++){
    _feste_Timer[i] = ft[i];
    _feste_Timer_Name[i] = ftn[i];
  }
    _timer_1 = *tmr1;
  pointer_timer_1 = tmr1;
  _timer_2 = *tmr2;
  pointer_timer_2 = tmr2;
  _timer_3 = *tmr3;
  pointer_timer_3 = tmr3;
  _timer_4 = *tmr4;
  pointer_timer_4 = tmr4;
  _timer_5 = *tmr5;
  pointer_timer_5 = tmr5;
  pointer_timer = ts;
  for(int i=0; i<5; i++){
    _timer[i] = ts[i];
  }
  server.on("/", handleRoot);
  server.on("/time", handleTime);
  for (int i = 0; i < 5; i++) {
    char start[50];
    char stop[50];
    sprintf(start, "/start Timer%i",i);
    server.on(start, handleStartStop);
    sprintf(stop, "/stop Timer%i",i);
    server.on(stop, handleStartStop);
  }
  server.on("/set", handleSet);
  server.on("/addValues", handleAddValues);

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