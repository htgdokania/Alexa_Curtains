void setup()
{
    // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enablePin,OUTPUT);

  digitalWrite(enablePin,HIGH); //Disable it. Enables when set to LOW

  Serial.begin(115200);
  wifiConnected = connectWifi();
  if (wifiConnected)
  {
    espalexa.addDevice(Device_1_Name, curtainChanged); //simplest definition, default state off
    espalexa.begin();
  }

}
