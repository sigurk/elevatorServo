void setupVars(){
  int buttonInsideSelected = 0;                 // Int to keep track of selected floor from buttons inside elevator
  int callElevatorFrom = 0;                     // Int to keep track of which floor elevator is called from                         // Set current elevator floor
  currentFloor = 1;
  boolean isDoorOpen = false;                   // Set state of door (Open/closed)

  pinMode(DCPPin,OUTPUT) ; //we have to set PWM pin as output
  pinMode(DCEPin,OUTPUT) ; 
  pinMode(DCDPin,OUTPUT) ;
}      

            
void floorIndicator(){ 
  if(currentFloor == floor1led-47 ){
    digitalWrite(floor1led,HIGH);
    digitalWrite(floor2led,LOW);
    digitalWrite(floor3led,LOW);
   
  }else if(currentFloor == floor2led-45){
    digitalWrite(floor2led,HIGH);
    digitalWrite(floor1led,LOW);
    digitalWrite(floor3led,LOW);
    ;
  }else if(currentFloor == floor3led - 43){
    digitalWrite(floor3led,HIGH);
    digitalWrite(floor1led,LOW);
    digitalWrite(floor2led,LOW);
 
  }
}
 
void setupStepVars(){ // enables stepmotor to function
  pinMode(BPPin,OUTPUT);
  pinMode(BPin,OUTPUT);
  pinMode(APPin,OUTPUT);
  pinMode(APin,OUTPUT);
  digitalWrite(BPPin,HIGH);
  digitalWrite(BPin,HIGH);
  digitalWrite(APPin,HIGH);
  digitalWrite(APin,HIGH);
}
