void moveElevator(int toFloor) {
  if (currentFloor < toFloor) {
    Serial.print("Motor moving up\n");
    lcd.setCursor(0, 1);
    lcd.print("Motor moving up");
    moveUp();
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("Arrived           ");
    openDoor();
    delay(2000);
    closeDoor();
    lcd.clear();
     
  }else if (currentFloor == toFloor){
    if (isDoorOpen == false) {
    Serial.print("Same floor");  
    lcd.setCursor(0,0);
    lcd.print("Same floor            ");
    openDoor();
    delay(2000);
    closeDoor();
    lcd.clear();
    }  
  }else if (currentFloor > toFloor) {
    Serial.print("Motor moving down\n");
    lcd.setCursor(0, 1);
    lcd.print("Motor down");
    moveDown();
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("Arrived           ");
    openDoor();
    delay(2000);
    closeDoor();
    lcd.clear();
  }
}


void moveUp(){
  digitalWrite(DCEPin,HIGH);
  digitalWrite(DCDPin,HIGH);
  analogWrite(DCPPin,200);
  delay(4000);
  digitalWrite(DCEPin,LOW);
}

void moveDown(){
  digitalWrite(DCEPin,HIGH);
  digitalWrite(DCDPin,HIGH);
  analogWrite(DCPPin,50);
  delay(4000);
  digitalWrite(DCEPin,LOW);
}
