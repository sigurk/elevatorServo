
void setupVars(){
  int buttonInsideSelected = 0;                 // Int to keep track of selected floor from buttons inside elevator
  int callElevatorFrom = 0;                     // Int to keep track of which floor elevator is called from
  int currentFloor = 1;                        // Set current elevator floor
  int elevatorState = 0;                        // 0 = stopped, 1 = unwiding, 2 = winding;

  boolean isDoorOpen = false;                   // Set state of door (Open/closed)
}

void setupStep(){
 pinMode(BPPin,OUTPUT);
 pinMode(BPin,OUTPUT);
 pinMode(APPin,OUTPUT);
 pinMode(APin,OUTPUT);
 digitalWrite(BPPin,HIGH);
 digitalWrite(BPin,HIGH);
 digitalWrite(APPin,HIGH);
 digitalWrite(APin,HIGH);

}
