void loop()
{
  espalexa.loop();
  
  digitalWrite(enablePin,HIGH); //Disable it. Enables when set to LOW
  if(count<maxPos and pos>=0 and pos<=maxPos){
      digitalWrite(enablePin,LOW); //Disable it. Enables when set to LOW
        
      //if  curtains are turned on , i.e instructed to close down. final pos should be maxPos
      if (curState == 255){
        //For moving down
        digitalWrite(dirPin,LOW);   
        int del=100;   
        
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(del); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(del); 
        pos+=1;
      }
      //if  curtains are turned off , i.e instructed to open. final pos should be 0
      else{
        //For moving UP
        digitalWrite(dirPin,HIGH);
        int del=100;
        
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(del); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(del); 
        pos-=1;
      }
      count+=1;    
  }
  else
  if(pos<0 or pos>maxPos){
    count =maxPos;
    
  }
  delayMicroseconds(10);
}
