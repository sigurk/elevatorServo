void readElevatorButtonInside(){
if(digitalRead(buttonToFloor1)== HIGH){
  buttonInsideSelected = 1;
  callElevatorButtonInside();
} else if(digitalRead(buttonToFloor2)==HIGH){
  buttonInsideSelected = 2;
  callElevatorButtonInside();
} else if(digitalRead(buttonToFloor3)==HIGH){
  buttonInsideSelected = 3;
  callElevatorButtonInside();
} else if(digitalRead(buttonDoor)==HIGH){
  buttonInsideSelected = 4;
  callElevatorButtonInside();
}
}


  //////////////        start  Motor   7//////////////////////
void start_motor(){

  if(digitalRead(buttonToFloor2)==HIGH){
     
         digitalWrite(5, HIGH);
         analogWrite(7, 100);
         delay(12); 
       
  }
  
}

void startmotoren(){

if(digitalRead(buttonDoor)==HIGH){
     Serial.println("clockwise");
     //myStepper.setSpeed(20);
     myStepper.step(100);
     delay(50);
         }

}


void step_motor(){

  if(digitalRead(buttonToFloor3)==HIGH){
    
     Serial.println("clockwise");
     //myStepper.setSpeed(20);
     Stepper myStepper(200,30,31,32,33);
     myStepper.step(100);
     delay(50);
    
  }
}
  





/*void startda(){
  for (i = 200; i > 1; i--){
digitalWrite(6, HIGH);
analogWrite(7, i);
delay(12);
}
}
*/

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


// -----------------------------------------------------------------------------------------------------------

/*
void loopenloop() {

  if(currentFloor < toFloor){
  Serial.println("Floor up");
  myStepper.step(stepsPerRevolution);
  delay(500);
  }

  else if(currentFloor == toFloor){
    //ingenting
    }
    else if (currentFloor > toFloor)
    Serial.println("Floor dwon");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
*/ 
