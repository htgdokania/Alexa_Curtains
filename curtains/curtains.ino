#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>
#include <Stepper.h>

boolean connectWifi();
void  curtainChanged(uint8_t deviceState);
const char* ssid = "SWATI";
const char* password = "8585865764";
String Device_1_Name = "Curtains one";
boolean wifiConnected = false;
Espalexa espalexa;


const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, D5,D6,D7,D8);
int lastState =999;//Any random value 
int curState = 999;
int count=8000;

//Default when device turns on curtains are assumed to be off i.e in open state   so initial pos=0 , max pos =8000
int pos = 0;
