//our callback functions
void curtainChanged(uint8_t deviceState)
{
    //this means we just switched
    //now check if curtains on or curtains off has been triggered
      if (deviceState == 255){
        Serial.println("in on state");
        //Close the curtains
        curState = 255;
          if(count == maxPos){
            count=0;          
          }
        }
      else{
        Serial.println("in off state");
        //Open the curtains
        curState = 0;
        if(count == maxPos){
            count=0;          
          }
        }
 
}
