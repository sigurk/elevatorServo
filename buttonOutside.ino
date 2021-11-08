void readElevatorButtonOutside(){
if(digitalRead(buttonCallFloor1)== HIGH){
  callElevatorFrom = 1;
  callElevatorButtonOutside();
} else if(digitalRead(buttonCallFloor2down)==HIGH){
  callElevatorFrom = 2;
  callElevatorButtonOutside();
} else if(digitalRead(buttonCallFloor2up)==HIGH){
  callElevatorFrom = 3;
  callElevatorButtonOutside();
} else if(digitalRead(buttonCallFloor3)==HIGH){
  callElevatorFrom = 4;
  callElevatorButtonOutside();
}
}

void callElevatorButtonOutside(){
    switch(callElevatorFrom){
    case 1: 
      Serial.print("Calling elevator to floor 1\n");
      moveElevator(1);
      delay(500);      
      callElevatorFrom = 0;
      currentFloor = 1;
      break;
    case 2: 
      Serial.print("Calling elevator to floor 2, direction down\n");
      moveElevator(2);
      delay(500);      
      callElevatorFrom = 0;
      currentFloor = 2;
      break;
    case 3: 
      Serial.print("Calling elevator to floor 2, direction up\n");
      moveElevator(2);
      delay(500);      
      callElevatorFrom = 0;
      currentFloor = 2;
      break;
    case 4: 
      Serial.print("Calling elevator to floor 3\n");
      moveElevator(3);
      delay(500);      
      callElevatorFrom = 0;
      currentFloor = 3;
      break;
    default:
      delay(10); 
      break;

  }
}
