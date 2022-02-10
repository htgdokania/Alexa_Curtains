void setup()
{
  Serial.begin(115200);
  wifiConnected = connectWifi();
  if (wifiConnected)
  {
    espalexa.addDevice(Device_1_Name, curtainChanged); //simplest definition, default state off
    espalexa.begin();
  }

  
  myStepper.setSpeed(60);
}
