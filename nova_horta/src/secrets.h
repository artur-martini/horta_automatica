const char* ssid = "PontoESP";
const char* password = "myESP123";
const char* serverName = "https://webhooks.mongodb-realm.com/api/client/v2.0/app/application-1-uetbe/service/hortaCommunication/incoming_webhook/webhook0";

// -- Project -------------------------------------------
#define CLIENT                  "teste horta"        // Client ID for the ESP (or something descriptive "Front Garden")
#define TYPE                    "ESP32"               // Type of Sensor ("Hornbill ESP32" or "Higrow" or "ESP8266" etc.)  

// -- Other - Helpers ------------------------------------
#define uS_TO_S_FACTOR          1000000               // Conversion factor for micro seconds to seconds
#define TIME_TO_SLEEP           300                   // Time ESP32 will go to sleep (in seconds) 
#define TIME_TO_SNOOZE          5                     // Time ESP32 will go to sleep (in seconds) 