void loop()
{
  espalexa.loop();

  // check if lastStatus changed

  //move unless we reach at extreme pos i.e pos==0 or pos==8000 and number of steps (count) are not exhausted.
  
  if(count<8000 and pos>0 and pos<8000){

      //if  curtains are turned on , i.e instructed to close down. final pos should be 8000
      if (curState == 255){
        myStepper.step(1);
        pos+=1;
        yield();
      }
      //if  curtains are turned on , i.e instructed to close down. final pos should be 0
      else{
        myStepper.step(-1);
        yield();
        pos-=1;
      }
      count+=1;    
      Serial.println(count);
  }
  else
  if(pos<=0 or pos>=8000){
    count =8000;
  }
  //else if at extreme postion set count == 8000
  delay(1);
}
