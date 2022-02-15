#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>

#include <EEPROM.h>


boolean connectWifi();
void  curtainChanged(uint8_t deviceState);
const char* ssid = "SWATI";
const char* password = "8585865764";
String Device_1_Name = "Curtains one";
boolean wifiConnected = false;
Espalexa espalexa;


//Default when device turns on curtains are assumed to be off i.e in open state   so initial pos=0 , max pos =8000
int maxPos=42 * 200 * 8;
const int stepPin = D5; 
const int dirPin = D6;
const int enablePin =D7;
int pos = 0;



int lastState =999;//Any random value 
int curState = 999;
int count=maxPos;



//Default 1/8 : MS2, MS1: 00: 1/8, 01: 1/32, 10: 1/64 11: 1/16
// to go up keep delay 300, dirPin HIGH and microstep 1/8  
// to go down keep delay 100, dirPin LOW and microstep 1/8

// full up or down in 41 full revolutions
