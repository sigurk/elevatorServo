
// Check if any button state is high. If high, add int corresponding to action to queue and remove duplicate entries. Except last two entries (buttonDoor) which is simple open/close door. 
void readButtons() {
  if (digitalRead(buttonToFloor1) == HIGH) {          
    queue.push_back(1);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonToFloor2) == HIGH) {
    queue.push_back(2);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonToFloor3) == HIGH) {
    queue.push_back(3);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonCallFloor1) == HIGH) {
    queue.push_back(6);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonCallFloor2down) == HIGH) {
    queue.push_back(4);
    delay(10);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonCallFloor2up) == HIGH) {
    queue.push_back(5);
    delay(10);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonCallFloor3) == HIGH) {
    queue.push_back(7);
    cleanQueueDuplicates();
  } else if (digitalRead(buttonDoor) == HIGH && isDoorOpen == false) {
    openDoor();
    delay(10);
    isDoorOpen = true;
  } else if (digitalRead(buttonDoor) == HIGH && isDoorOpen == true){
    closeDoor();
    delay(10);
    isDoorOpen = false;
  }
}
