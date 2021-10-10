#include <Arduino.h>
#include <WEMOS_SHT3X.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "secrets.h"

const int SAMPLES = 10;
const int LDR_READ_PIN = 36;
const int MOIST_POWER_PIN = 26;
const int MOIST_READ_PIN = 39;
const int LED_BUILTIN = 5;

RTC_DATA_ATTR int bootCount = 0;
RTC_DATA_ATTR char name[15] = CLIENT;

SHT3X sht30(0x45);
StaticJsonDocument<500> doc;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.print(" with password ");
  Serial.println(password);

  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, LOW);

  // sinaliza a conexão com wi-fi piscando leds 
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }
  
}

void POSTData()
{
      
      if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      http.begin(serverName);
      http.addHeader("Content-Type", "application/json");

      String json;
      serializeJson(doc, json);

      Serial.println(json);
      int httpResponseCode = http.POST(json);
      Serial.println(httpResponseCode);
      }
}

void loop() {
  // put your main code here, to run repeatedly:  
  ++bootCount; // move this to setup()
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  //getDevice(); // use ESP in sleep mode and watchdog trigger
  //senseLight(LDR_READ_PIN);
  //senseMoisture(MOIST_POWER_PIN, MOIST_READ_PIN);
  //senseTemp();
  //senseHumid();

  doc["iluminacao"] = true;
  doc["irrigacao"] = true;

  digitalWrite(LED_BUILTIN, LOW);
  delay(10000);
  Serial.println("Posting...");
  POSTData();
  serializeJsonPretty(doc, Serial);
  Serial.println("\nDone.");
}