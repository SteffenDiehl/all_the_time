#include <Arduino.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
  #include <SPIFFS.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
  #include <Hash.h>
  #include <FS.h>
#endif
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

const char* PARAM_festerTimerName6 = "festerTimerName6";
const char* PARAM_festerTimer6 = "festerTimer6";
const char* PARAM_festerTimerName7 = "festerTimerName7";
const char* PARAM_festerTimer7 = "festerTimer7";
const char* PARAM_festerTimerName8 = "festerTimerName8";
const char* PARAM_festerTimer8 = "festerTimer8";
const char* PARAM_festerTimerName9 = "festerTimerName9";
const char* PARAM_festerTimer9 = "festerTimer9";
const char* PARAM_festerTimerName10 = "festerTimerName10";
const char* PARAM_festerTimer10 = "festerTimer10";

const char* PARAM_festeTimerNameSelect = "festeTimerNameSelect";
const char* PARAM_timerSelect = "timerSelect";

const char* PARAM_timer1value = "timer1value";
const char* PARAM_timer2value = "timer2value";
const char* PARAM_timer3value = "timer3value";
const char* PARAM_timer4value = "timer4value";
const char* PARAM_timer5value = "timer5value";

String _feste_Timer_Name[10] = {"Nudeln 7min", "Kartoffeln 14min", "Steak medium", "Mittag 1h", "Mittag 30min", "-", "-", "-", "-", "-"};
unsigned long _feste_Timer[10] = {420000, 840000, 90000, 3600000, 1800000, 0, 0, 0, 0, 0};
const char* festeFileName[10] = {"/festerTimerName1", "/festerTimerName2", "/festerTimerName3", "/festerTimerName4", "/festerTimerName5", "/festerTimerName6", "/festerTimerName7", "/festerTimerName8", "/festerTimerName9", "/festerTimerName10"};
const char* festeFile[10] = {"/festerTimer1", "/festerTimer2", "/festerTimer3", "/festerTimer4", "/festerTimer5", "/festerTimer6", "/festerTimer7", "/festerTimer8", "/festerTimer9", "/festerTimer10"};
const char* PARAM_CURRENTTIME = "currentTime";
String* Pointerfeste_Timer_Name = nullptr;
unsigned long *Pointerfeste_Timer = nullptr;
unsigned long *pointer_timer_1 = nullptr;
unsigned long *pointer_timer_2 = nullptr;
unsigned long *pointer_timer_3 = nullptr;
unsigned long *pointer_timer_4 = nullptr;
unsigned long *pointer_timer_5 = nullptr;
unsigned long *pointer_timer = nullptr;
String Date;
String Time;

unsigned long _timer[5] = {0, 0, 0, 0, 0};

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html><body style="background-color: lightblue;">
  <head>
    <meta http-equiv="refresh" content="5">
    <script>
    function submitMessage() {
      alert("Saved value to ESP SPIFFS");
      setTimeout(function(){ document.location.reload(false); }, 500);   
    }
    function submitaddMessage() {
      alert("%timer3value%");
      setTimeout(function(){ document.location.reload(false); }, 500);   
    }
    function startMessage() {
      alert("new Timer started");
      setTimeout(function(){ document.location.reload(false); }, 500);   
    }
    </script>
    <title>FUCK THIS SHIT</title>
  </head>
  <body>
    <form target= "hidden-form">
      <h1>Current Time: %currentTime%</h1>
      <h1>Date: %currentDate%</h1>
      <h2>Team Biscuit </h2>
    </form>
    <th>Timer</th>
    <th>TimerValue</th>
    <th>Time Left</th>
    <th>Actions</th>
    <br>
    <br>
    <form target= "hidden-form">
      Timer1: %timer1value% seconds / %timer1left% seconds
    </form>
    <br>
    <form target= "hidden-form">
      Timer2: %timer2value% seconds / %timer2left% seconds
    </form>
    <br>
    <form target= "hidden-form">
      Timer3: %timer3value% seconds / %timer3left% seconds
    </form>
    <br>
    <form target= "hidden-form">
      Timer4: %timer4value% seconds / %timer4left% seconds
    </form>
    <br>
    <form acton="/start5" target= "hidden-form">
      Timer5: %timer5value% seconds / %timer5left% seconds
    </form>
    <br>
      <form acton="/startnew" target= "hidden-form">
      <input type="submit" value="Start a new Timer" onclick="startMessage()">
    </form>
    <br>

    <form action="/get" target="hidden-form">
      festerTimerName6 (current value %festerTimerName6%): <input type="text" name="festerTimerName6">
      festerTimer6 (current value %festerTimer6%): <input type="number " name="festerTimer6">
      <br>
      festerTimerName7 (current value %festerTimerName7%): <input type="text" name="festerTimerName7">
      festerTimer7 (current value %festerTimer7%): <input type="number " name="festerTimer7">
      <br>
      festerTimerName8 (current value %festerTimerName8%): <input type="text" name="festerTimerName8">
      festerTimer8 (current value %festerTimer8%): <input type="number " name="festerTimer8">
      <br>
      festerTimerName9 (current value %festerTimerName9%): <input type="text" name="festerTimerName9">
      festerTimer9 (current value %festerTimer9%): <input type="number " name="festerTimer9">
      <br>
      festerTimerName10 (current value %festerTimerName10%): <input type="text" name="festerTimerName10">
      festerTimer10 (current value %festerTimer10%): <input type="number " name="festerTimer10">
      <input type="submit" value="Submit" onclick="submitMessage()">
    </form>
    <br>
    <br>

  <form action="/add" target="hidden-form">
    <label>Timer:</label>
    <select name="timerSelect">
    <option value="/timer1value.txt">Timer 1</option>
    <option value="/timer2value.txt">Timer 2</option>
    <option value="/timer3value.txt">Timer 3</option>
    <option value="/timer4value.txt">Timer 4</option>
    <option value="/timer5value.txt">Timer 5</option>
    </select>
    <label>festeTimerName:</label>
    <select name="festeTimerNameSelect">
    <option value="%festerTimer1%">%festerTimerName1%</option>
    <option value="%festerTimer2%">%festerTimerName2%</option>
    <option value="%festerTimer3%">%festerTimerName3%</option>
    <option value="%festerTimer4%">%festerTimerName4%</option>
    <option value="%festerTimer5%">%festerTimerName5%</option>
    <option value="%festerTimer6%">%festerTimerName6%</option>
    <option value="%festerTimer7%">%festerTimerName7%</option>
    <option value="%festerTimer8%">%festerTimerName8%</option>
    <option value="%festerTimer9%">%festerTimerName9%</option>
    <option value="%festerTimer10%">%festerTimerName10%</option>
    </select>
    <input type="submit" value="Submitadd" onclick="submitaddMessage()">
  </form>

  
  <iframe style="display:none" name="hidden-form"></iframe>
  </body>
</html>)rawliteral";


void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

String readFile(fs::FS &fs, const char * path){
  // Serial.print(path);
  // Serial.printf("Reading file: %s\r\n", path);
  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    // Serial.println("- empty file or failed to open file");
    return String();
  }
  // Serial.println("- read from file:");
  String fileContent;
  while(file.available()){
    fileContent+=String((char)file.read());
  }
  file.close();
  // Serial.println(fileContent);
  return fileContent;
}

void writeFile(fs::FS &fs, const char * path, const char * message){
  Serial.printf("Writing file: %s\r\n", path);
  File file = fs.open(path, "w");
  if(!file){
    Serial.println("- failed to open file for writing");
    return;
  }
  if(file.print(message)){
    Serial.println(message);
    Serial.println("- file written");
  } else {
    Serial.println("- write failed");
  }
  file.close();
}

// Replaces placeholder with stored values
String processor(const String& var){
  //Serial.println(var);
    if(var == "festerTimerName1"){
    return _feste_Timer_Name[0];
  }
    else if(var == "festerTimer1"){
    return String(_feste_Timer[0]);
  }
    else if(var == "festerTimerName2"){
    return _feste_Timer_Name[1];
  }
    else if(var == "festerTimer2"){
    return String(_feste_Timer[1]);
  }
    else if(var == "festerTimerName3"){
    return _feste_Timer_Name[2];
  }
    else if(var == "festerTimer3"){
    return String(_feste_Timer[2]);
  }
    else if(var == "festerTimerName4"){
    return _feste_Timer_Name[3];
  }
    else if(var == "festerTimer4"){
    return String(_feste_Timer[3]);
  }
    else if(var == "festerTimerName5"){
    return _feste_Timer_Name[4];
  }
    else if(var == "festerTimer5"){
    return String(_feste_Timer[4]);
  }
    else if(var == "festerTimerName6"){
    return readFile(SPIFFS, "/festerTimerName6.txt");
  }
    else if(var == "festerTimer6"){
    return readFile(SPIFFS, "/festerTimer6.txt");
  }
    else if(var == "festerTimerName7"){
    return readFile(SPIFFS, "/festerTimerName7.txt");
  }
    else if(var == "festerTimer7"){
    return readFile(SPIFFS, "/festerTimer7.txt");
  }
    else if(var == "festerTimerName8"){
    return readFile(SPIFFS, "/festerTimerName8.txt");
  }
    else if(var == "festerTimer8"){
    return readFile(SPIFFS, "/festerTimer8.txt");
  }
    else if(var == "festerTimerName9"){
    return readFile(SPIFFS, "/festerTimerName9.txt");
  }
    else if(var == "festerTimer9"){
    return readFile(SPIFFS, "/festerTimer9.txt");
  }
    else if(var == "festerTimerName10"){
    return readFile(SPIFFS, "/festerTimerName10.txt");
  }
    else if(var == "festerTimer10"){
    return readFile(SPIFFS, "/festerTimer10.txt");
  }
    else if(var == "timer1value"){
    return String((*pointer_timer_1)/1000);
  }
    else if(var == "timer2value"){
    return String((*pointer_timer_2)/1000);
  }
    else if(var == "timer3value"){
    return String((*pointer_timer_3)/1000));
  }
    else if(var == "timer4value"){
    return String((*pointer_timer_4)/1000);
  }
    else if(var == "timer5value"){
    return String((*pointer_timer_5)/1000);
  }
    else if(var == "currentTime"){
    return Time;
  }
    else if(var == "currentDate"){
    return Date;
  }
    else if(var== "timer1left") {
      return String(pointer_timer[0]);
  }
    else if(var== "timer2left") {
      return String(pointer_timer[1]);
  }
    else if(var== "timer3left") {
      return String(pointer_timer[2]);
  }
    else if(var== "timer4left") {
      return String(pointer_timer[3]);
  }
    else if(var== "timer5left") {
      return String(pointer_timer[4]);
  }
  return String();
}

void web_browser_begin(unsigned long ft[10] = {}, String ftn[10] = {}, unsigned long *tmr1 = nullptr, unsigned long *tmr2 = nullptr, unsigned long *tmr3 = nullptr, unsigned long *tmr4 = nullptr, unsigned long *tmr5 = nullptr, unsigned long ts[5] = {}) {
  for(int i = 0; i<10; i++){
    _feste_Timer[i] = ft[i];
    _feste_Timer_Name[i] = ftn[i];
  }
  Pointerfeste_Timer = ft;//check main
  Pointerfeste_Timer_Name = ftn;//check main 
  pointer_timer_1 =tmr1;
  pointer_timer_2 =tmr2;
  pointer_timer_3 =tmr3;
  pointer_timer_4 =tmr4;
  pointer_timer_5 =tmr5;
  pointer_timer =ts;
  Serial.begin(115200);
  // Initialize SPIFFS
  #ifdef ESP32
    if(!SPIFFS.begin(true)){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
    }
  #else
    if(!SPIFFS.begin()){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
    }
  #endif

  WiFi.mode(WIFI_STA);

  // Send web page with input fields to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/get?festerTimerName=<inputMessage>
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    unsigned long changetimer;
    String inputMessage;
    // GET festerTimerName value on <ESP_IP>/get?festerTimerName=<inputMessage>
    if (request->hasParam(PARAM_festerTimerName6)) {
      inputMessage = request->getParam(PARAM_festerTimerName6)->value();
      writeFile(SPIFFS, "/festerTimerName6.txt", inputMessage.c_str());
      Pointerfeste_Timer_Name[5] = inputMessage;
    }
    // GET inputInt value on <ESP_IP>/get?inputInt=<inputMessage>
    if (request->hasParam(PARAM_festerTimer6)) {
      inputMessage = request->getParam(PARAM_festerTimer6)->value();
      writeFile(SPIFFS, "/festerTimer6.txt", inputMessage.c_str());
      changetimer = (inputMessage.toInt()/1000);
      Pointerfeste_Timer[5] = changetimer;
    }
    if (request->hasParam(PARAM_festerTimerName7)) {
      inputMessage = request->getParam(PARAM_festerTimerName7)->value();
      writeFile(SPIFFS, "/festerTimerName7.txt", inputMessage.c_str());
      Pointerfeste_Timer_Name[6] = inputMessage;
    }
    if (request->hasParam(PARAM_festerTimer7)) {
      inputMessage = request->getParam(PARAM_festerTimer7)->value();
      writeFile(SPIFFS, "/festerTimer7.txt", inputMessage.c_str());
      changetimer = (inputMessage.toInt()/1000);
      Pointerfeste_Timer[6] = changetimer;
    }
    if (request->hasParam(PARAM_festerTimerName8)) {
      inputMessage = request->getParam(PARAM_festerTimerName8)->value();
      writeFile(SPIFFS, "/festerTimerName8.txt", inputMessage.c_str());
      Pointerfeste_Timer_Name[7] = inputMessage;
    }
    if (request->hasParam(PARAM_festerTimer8)) {
      inputMessage = request->getParam(PARAM_festerTimer8)->value();
      writeFile(SPIFFS, "/festerTimer8.txt", inputMessage.c_str());
      changetimer = (inputMessage.toInt()/1000);
      Pointerfeste_Timer[7] = changetimer;
    }
    if (request->hasParam(PARAM_festerTimerName9)) {
      inputMessage = request->getParam(PARAM_festerTimerName9)->value();
      writeFile(SPIFFS, "/festerTimerName9.txt", inputMessage.c_str());
      Pointerfeste_Timer_Name[8] = inputMessage;
    }
    if (request->hasParam(PARAM_festerTimer9)) {
      inputMessage = request->getParam(PARAM_festerTimer9)->value();
      writeFile(SPIFFS, "/festerTimer9.txt", inputMessage.c_str());
      changetimer = (inputMessage.toInt()/1000);
      Pointerfeste_Timer[8] = changetimer;
    }
    if (request->hasParam(PARAM_festerTimerName10)) {
      inputMessage = request->getParam(PARAM_festerTimerName10)->value();
      writeFile(SPIFFS, "/festerTimerName10.txt", inputMessage.c_str());
      Pointerfeste_Timer_Name[9] = inputMessage;
    }
    if (request->hasParam(PARAM_festerTimer10)) {
      inputMessage = request->getParam(PARAM_festerTimer10)->value();
      writeFile(SPIFFS, "/festerTimer10.txt", inputMessage.c_str());
      changetimer = (inputMessage.toInt()/1000);
      Pointerfeste_Timer[9] = changetimer;
    }
    else {
      inputMessage = "No message sent";
    }
    request->send(200, "text/text", inputMessage);
  });
  server.on("/add", HTTP_GET, [](AsyncWebServerRequest *request){
    String inputMessage;
    String filename;
      if (request->hasParam(PARAM_festeTimerNameSelect)) {
      inputMessage = request->getParam(PARAM_festeTimerNameSelect)->value();
      // Serial.println("inputMessage:" + inputMessage);
      }
      if (request->hasParam(PARAM_timerSelect)) {
      filename = request->getParam(PARAM_timerSelect)->value();
      //  
      const char* file = filename.c_str();
      writeFile(SPIFFS, file, inputMessage.c_str());
      }
    });
  server.on("/startnew",HTTP_GET, [](AsyncWebServerRequest *request){
    Serial.println("new timer started");
  });
  server.onNotFound(notFound);
  server.begin();
}

void web_browser_end(){
  server.end();
}

void web_browser(int _Y, int _M, int _D, int _h, int _m, int _s) {
  Date =  String(_D) + "." + String(_M) + "." + String(_Y);
  Time = String(_h) + ":" + String(_m) + ":" + String(_s);
}