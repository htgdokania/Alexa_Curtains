void setup()
{
  Serial.begin(115200);
  pinMode(RelayPin1, OUTPUT);
  pinMode(Led, OUTPUT);

  wifiConnected = connectWifi();
  if (wifiConnected)
  {
    espalexa.addDevice(Device_1_Name, curtainChanged); //simplest definition, default state off
    espalexa.begin();
  }
}
