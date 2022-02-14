
const int stepPin = D5; 
const int dirPin = D6;
int del =300;


//Default 1/8 : MS2, MS1: 00: 1/8, 01: 1/32, 10: 1/64 11: 1/16
// to go up keep delay 300, dirPin HIGH and microstep 1/8  
// to go down keep delay 100, dirPin LOW and microstep 1/8

// full up or down in 41 full revolutions

//int count =1+ (41*200*8);
int count =0;


//default micro stepping is 1/8 so to turn 1 full turn steps= 200* 8 =1000
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

  //For moving UP
  digitalWrite(dirPin,HIGH);

//  //For moving down
//   digitalWrite(dirPin,LOW);
  
}
void loop() {
  
  if(count < (42 * 200 * 8)){
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(del); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(del); 
    count+=1;
  }
}
