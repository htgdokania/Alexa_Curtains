#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>
// define the GPIO connected with Relays
#define RelayPin1 5  //D1
#define Led 2 //GPIO02

boolean connectWifi();
void  Changed(uint8_t brightness);
const char* ssid = "SWATI";
const char* password = "8585865764";
String Device_1_Name = "Curtains";
boolean wifiConnected = false;
Espalexa espalexa;
