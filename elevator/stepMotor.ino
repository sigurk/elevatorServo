
// Close door if open 
void closedDoorCheck(){
    if(isDoorOpen == true){
    lcd.setCursor(0, 1);
    lcd.print("Closing door...");
    closeDoor();
    delay(500);
    lcd.clear();
  }
}

// Open door 2 revs
void openDoor() {
  lcd.setCursor(0, 1);
  lcd.print("Opening door...");
  for (i = 1; i <= 100; i++) {
    readButtons();
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

// Close door 2 revs
void closeDoor() {
  lcd.setCursor(0, 1);
  lcd.print("Closing door...");
  for (i = 1; i <= 100; i++) {
    readButtons();
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
