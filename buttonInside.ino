void readElevatorButtonInside(){
  if(digitalRead(buttonToFloor1)== HIGH){
    buttonInsideSelected = 1;
    callElevatorButtonInside();
 }else if(digitalRead(buttonToFloor2)==HIGH){
    buttonInsideSelected = 2;
    callElevatorButtonInside();
 }else if(digitalRead(buttonToFloor3)==HIGH){
    buttonInsideSelected = 3;
    callElevatorButtonInside();
 }else if(digitalRead(buttonDoor)==HIGH){
    buttonInsideSelected = 4;
    callElevatorButtonInside();
 }
}

void callElevatorButtonInside(){
    switch(buttonInsideSelected){
    case 1: 
      if(buttonInsideSelected != currentFloor){
        Serial.print("Moving to floor 1\n");
        lcd.setCursor(0,0); 
        lcd.print("Moving to floor1");
      }
      moveElevator(1);
      buttonInsideSelected = 0;
      delay(500);
      currentFloor = 1;
      floorIndicator();
      break;
      
    case 2: 
      if(buttonInsideSelected != currentFloor){
        Serial.print("Moving to floor2\n");
        lcd.setCursor(0,0); 
        lcd.print("Moving to floor2");
     }
      moveElevator(2);
      buttonInsideSelected = 0;
      delay(500);
      currentFloor = 2;
      floorIndicator();
      break;
      
    case 3: 
      if(buttonInsideSelected != currentFloor){
        Serial.print("Moving to floor 3\n");
        lcd.setCursor(0,0);  
        lcd.print("Moving to floor3");
     } 
      moveElevator(3);
      buttonInsideSelected = 0;
      delay(500);
      currentFloor = 3;
      floorIndicator();
      break;
      
    case 4:
      if(isDoorOpen == false){
        openDoor();
        delay(2000);
        closeDoor();
      }
      buttonInsideSelected = 0;     
    default:
      delay(10); 
      break;
  }
}
