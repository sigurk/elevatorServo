
// Move elevator. Either one level up or one level down, depending on which bool from getDirection is true. 
void moveElevator() {
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);    // Interrupt for PID 
  readButtons();

  if (goUp == true) {
    pos = 0;
    posi = 0;                    // Reset pos before running pid from 0-target (2048) again. 2048 equals one rev
    while (pos <= target) {
      readButtons();
      pid();
    }
    for (i = 0; i < 50; i++) {
      pid();
    }
    goUp = false;
    currentFloor = currentFloor + 1;
  } else if (goDown == true) {
    pos = 0;
    posi = 0;
    while (pos <= target) {
      readButtons();
      pid();
    }
    for (i = 0; i < 50; i++) {
      pid();
    }
    goDown = false;
    currentFloor = currentFloor - 1;
  }
}

// Check current floor versus which floor user selected, booleans used further in moveElevator to move correct direction 
void getDirection(int currentFloor, int toFloor) {
  if (currentFloor > toFloor) {
    goDown = true;
  } else if (currentFloor < toFloor) {
    goUp = true;
  } else if (currentFloor == toFloor) {
    stay = true;
  }
}

// Lights up LED corresponding to which floor user is at
void floorIndicator() {
  if (currentFloor == floor1led - 47 ) {
    digitalWrite(floor1led, HIGH);
    digitalWrite(floor2led, LOW);
    digitalWrite(floor3led, LOW);

  } else if (currentFloor == floor2led - 45) {
    digitalWrite(floor2led, HIGH);
    digitalWrite(floor1led, LOW);
    digitalWrite(floor3led, LOW);
    
  } else if (currentFloor == floor3led - 43) {
    digitalWrite(floor3led, HIGH);
    digitalWrite(floor1led, LOW);
    digitalWrite(floor2led, LOW);
  }
}
