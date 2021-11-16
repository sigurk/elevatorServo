-
// load queueHead (queue[0]), if between 1-3 move to 1-3. If 4 = call to floor 2 dir down. If 5 = call to floor 2 dir up. If 6 = call to floor 1. If 7 = call to floor 3. 
void executeQueue(int queueHead) {
  floorIndicator();
  if (queueHead == currentFloor) {
    sameFloorSequence();
  } else if (queueHead > 0 && queueHead < 4) {
    closedDoorCheck();
    getDirection(currentFloor, queueHead);
    lcd.setCursor(0, 0);
    lcd.print(String("Moving to ") + String(queueHead));
    if (goUp == true) {
      lcd.setCursor(0, 1);
      lcd.print("Moving up");
    } else if (goDown == true) {
      lcd.setCursor(0, 1);
      lcd.print("Moving down");
    }
    readButtons();
    delay(1000);
    moveElevator();
    floorIndicator();

    if (currentFloor == queueHead) {
      arrivedFloorSequence();
    }
  } else if (queueHead == 4 && currentFloor != 2) {
    upOrDownSequence(0);
  } else if (queueHead == 4 && currentFloor == 2) {
    lcd.clear();
    sameFloorSequence();
    lcd.clear();
  } else if (queueHead == 5 && currentFloor != 2) {
    upOrDownSequence(1);
  } else if (queueHead == 5 && currentFloor == 2) {
    lcd.clear();
    sameFloorSequence();
    lcd.clear();
  } else if (queueHead == 6) {
    callFloorSequence(1);
    if (currentFloor == 1) {
      arrivedFloorSequence();
    }
  } else if (queueHead == 7) {
    callFloorSequence(3);
    if (currentFloor == 3) {
      arrivedFloorSequence();
    }
  }
}

// Used at 4&5 call to floor 2 down/up. Open close door, move either down or up
void upOrDownSequence(int up) {
  closedDoorCheck();
  lcd.clear();
  getDirection(currentFloor, 2);
  lcd.setCursor(0, 0);
  lcd.print("Calling to 2   ");
  if (goUp == true) {
    lcd.setCursor(0, 1);
    lcd.print("Moving up");
  } else if (goDown == true) {
    lcd.setCursor(0, 1);
    lcd.print("Moving down");
  }
  moveElevator();
  floorIndicator();
  openDoor();
  delay(100);
  closeDoor();

  readButtons();
  delay(1000);

  if (up == 1) {
    goUp = true;
    lcd.setCursor(0, 0);
    lcd.print("Moving to 3      ");
    lcd.setCursor(0, 1);
    lcd.print("Moving up");
    moveElevator();
    floorIndicator();
    goUp = false;
  } else if (up == 0) {
    goDown = true;
    lcd.setCursor(0, 0);
    lcd.print("Moving to 1    ");
    lcd.setCursor(0, 1);
    lcd.print("Moving down");
    moveElevator();
    floorIndicator();
    goDown = false;
  }

  openDoor();
  delay(100);
  closeDoor();
  lcd.clear();

  queue.pop_front();
  queue.pop_front();
}

// Used in call to floor 1 and call to floor 3
void callFloorSequence(int toFloor) {
  closedDoorCheck();
  lcd.clear();
  getDirection(currentFloor, toFloor);
  lcd.setCursor(0, 0);
  lcd.print("Calling to ");
  lcd.print(toFloor);
  lcd.print("     ");
  if (goUp == true) {
  lcd.setCursor(0, 1);
    lcd.print("Moving up");
  } else if (goDown == true) {
  lcd.setCursor(0, 1);
    lcd.print("Moving down");
  }
  readButtons();
  delay(1000);
  moveElevator();
  floorIndicator();
}

// Used if current floor equals requseted floor
void sameFloorSequence() {
  lcd.setCursor(0, 0);
  lcd.print("Same floor     ");
  delay(1000);
  openDoor();
  delay(1500);
  queue.pop_front();
  queue.pop_front();
  closeDoor();
  delay(10);
  lcd.clear();    //
}

// Used after elevator has moved and reached its destination
void arrivedFloorSequence() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Arrived floor");
  delay(1000);
  openDoor();
  delay(1500);
  queue.pop_front();
  queue.pop_front();
  closeDoor();
  delay(10);
  lcd.clear();    //
}

// Clean up duplicates in queue, eg two requests for floor 1 in a row
void cleanQueueDuplicates() {
  int count = queue.count();
  if (queue.count() > 1) {
    for (i = count; i > 1; i--) {
      if (queue[i] == queue[i - 1]) {
        queue.pop_back();
      }
    }
  }
}
