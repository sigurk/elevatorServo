void readElevatorButtonOutside(){
  if(digitalRead(buttonCallFloor1)== HIGH){
    callElevatorFrom = 1;
    callElevatorButtonOutside();
  }else if(digitalRead(buttonCallFloor2down)==HIGH){
    callElevatorFrom = 2;
    callElevatorButtonOutside();
  }else if(digitalRead(buttonCallFloor2up)==HIGH){
    callElevatorFrom = 3;
    callElevatorButtonOutside();
  }else if(digitalRead(buttonCallFloor3)==HIGH){
    callElevatorFrom = 4;
    callElevatorButtonOutside();
  }
}

void callElevatorButtonOutside(){
  switch(callElevatorFrom){
  case 1: 
    if(callElevatorFrom != currentFloor){ 
      Serial.print("Call to floor 1\n");
      lcd.setCursor(0,0);  
      lcd.print("Call to floor1"); 
    }
    moveElevator(1);
    delay(500);      
    callElevatorFrom = 0;
    currentFloor = 1;
    floorIndicator();
    break;
      
  case 2: 
     if(callElevatorFrom != currentFloor){ 
      Serial.print("Calling elevator to floor 2, direction down\n");
      lcd.setCursor(0,0);  
      lcd.print("Call to 2,down");
    } 
    moveElevator(2);
    delay(500);      
    callElevatorFrom = 0;
    currentFloor = 2;
    floorIndicator();
    break;
      
  case 3: 
      if(callElevatorFrom != currentFloor){ 
      Serial.print("Calling elevator to floor 2, direction up\n");
      lcd.setCursor(0,0);
      lcd.print("Call to 2,up");
    }
    moveElevator(2);
    delay(500);      
    callElevatorFrom = 0;
    currentFloor = 2;
    floorIndicator();
    break;
    
  case 4: 
   if(callElevatorFrom != currentFloor){ 
      Serial.print("Calling elevator to floor 3\n");
      lcd.setCursor(0,0);  
      lcd.print("Call to floor 3");
    }
    moveElevator(3);
    delay(500);      
    callElevatorFrom = 0;
    currentFloor = 3;
    floorIndicator();
    break;
  default:
    delay(10); 
    break;
  }
}
