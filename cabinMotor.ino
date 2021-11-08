


void moveElevator(int toFloor) {
// initialize the stepper library on pins 8 through 11:
  if (currentFloor < toFloor) {
   Serial.print("Motor moving up\n");
//     if(digitalRead(buttonToFloor2)==HIGH){
//     buttonInsideSelected = 2;
//     callElevatorButtonInside();
//     
//     for(i = 1; i < 200; i++){
//         digitalWrite(6, HIGH);
//         analogWrite(7, i);
//         delay(12); 
//         if(i==199){
//           digitalWrite(6, LOW);
//           analogWrite(7, 0);
//         }
//     }
//   }

  } else if (currentFloor == toFloor) {
    if (isDoorOpen == false) {
      
       Serial.print("Same floor, opening door\n");
      delay(1000);
      setDoorTimer();
    } else if (isDoorOpen == true){
      Serial.print("Same floor\n");
      setDoorTimer();
    }
  } else if (currentFloor > toFloor) {
    Serial.print("Motor moving down\n");
//     if(digitalRead(buttonToFloor1)==HIGH){
//     buttonInsideSelected = 1;
//     callElevatorButtonInside();
//     
//     for(i = 1; i < 200; i--){
//         digitalWrite(5, HIGH);
//         analogWrite(7, i);
//         delay(12); 
//         if(i==2){
//           digitalWrite(6, LOW);
//           analogWrite(7, 0);
//         }
//     }
//  }
    
  }
}

void setDoorTimer(){
      isDoorOpen = true;
      currentMillis = millis();
      timerCloseDoor();
}
void timerCloseDoor(){
  if (currentMillis >= interval) {
        Serial.print("Closing door TIMER\n");
        isDoorOpen = false;
        currentMillis = 0;
}



}
