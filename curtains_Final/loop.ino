void loop()
{
  espalexa.loop();
  
  digitalWrite(enablePin,HIGH); //Disable it. Enables when set to LOW
  if(count<maxPos and pos>=0 and pos<=maxPos){
      digitalWrite(enablePin,LOW); //Enable it. Enables when set to LOW
        
      //if  curtains are turned on , i.e instructed to close down. final pos should be maxPos
      if (curState == 255 and pos<maxPos){
        //For moving down
        digitalWrite(dirPin,LOW);   
        int del=100;   
        
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(del); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(del); 
        pos+=1;
        if(pos== maxPos){
          // update current position in memory as well
          EEPROM.put(0, pos);
          EEPROM.commit();
        }
      }
      //if  curtains are turned off , i.e instructed to open. final pos should be 0
      else
      if(curState == 0 and pos>0){
        //For moving UP
        digitalWrite(dirPin,HIGH);
        int del=100;
        
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(del); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(del); 
        pos-=1;
        if(pos== 0){
          // update current position in memory as well
          EEPROM.put(0, pos);
          EEPROM.commit();
        }
      }
      count+=1;   
      
    //Serial.println(pos); 
  }
  else
  if(pos<=0){
    pos=0;
    count=maxPos;
  }
  else
  if(pos>=maxPos){
    pos=maxPos;
    count =maxPos;
  }
  else{
    count =maxPos;
  }
  delayMicroseconds(10);
}
