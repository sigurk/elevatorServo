void openDoor(){
  Serial.print("opening door \n");
    lcd.setCursor(0, 1);
    lcd.print("Opening door...");
    
  for(i=1; i <= 100; i++){
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


void closeDoor(){
  Serial.print("closing door \n");
  lcd.setCursor(0, 1);
  lcd.print("Closing door...");
  
  for(i=1; i <= 100; i++){
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
