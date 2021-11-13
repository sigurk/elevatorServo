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
