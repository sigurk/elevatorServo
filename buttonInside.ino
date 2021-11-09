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


  //////////////        start  Motor   7//////////////////////

void stepmotorOpen(int stepDelay){
for(i=1; i <= 50; i++){
  digitalWrite(APPin, LOW);
  digitalWrite(BPPin, HIGH);
  delay(stepDelay);
  digitalWrite(APPin, LOW);
  digitalWrite(BPPin, LOW);
  delay(stepDelay);
  digitalWrite(APPin, HIGH);
  digitalWrite(BPPin, LOW);
  delay(stepDelay);
  digitalWrite(APPin, HIGH);
  digitalWrite(BPPin, HIGH);
  delay(stepDelay);
  }
} 

void stepmotorClose(int stepDelay){
for(i=1; i <= 50; i++){
  digitalWrite(APPin, HIGH);
  digitalWrite(BPPin, HIGH);
  delay(stepDelay);
  digitalWrite(APPin, HIGH);
  digitalWrite(BPPin, LOW);
  delay(stepDelay);
  digitalWrite(APPin, LOW);
  digitalWrite(BPPin, LOW);
  delay(stepDelay);
  digitalWrite(APPin, LOW);
  digitalWrite(BPPin, HIGH);
  delay(stepDelay);
  }
} 

void callElevatorButtonInside(){
    switch(buttonInsideSelected){
    case 1: 
      Serial.print("går til første etasje\n");
      moveElevator(1);
      buttonInsideSelected = 0;
      delay(500);
      currentFloor = 1;
      break;
    case 2: 
      Serial.print("går til andre etasje\n");
      moveElevator(2);
      buttonInsideSelected = 0;
      delay(500);
      currentFloor = 2;
      break;
    case 3: 
      Serial.print("går til tredje etasje\n");
      moveElevator(3);
      buttonInsideSelected = 0;
      delay(500);
      currentFloor = 3;
      break;
    case 4:
      if(isDoorOpen == false){
        Serial.print("Opening door\n");
        delay(10);
        isDoorOpen = true;
      }else if(isDoorOpen == true){
        Serial.print("Closing door SWITCH\n");
        delay(10);
        isDoorOpen = false;
      }
      buttonInsideSelected = 0;     
    default:
      delay(10); 
      break;
  }
}
