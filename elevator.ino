
#include<dac.h>

// Initialize buttonpins 
int buttonToFloor1 = 22; int buttonToFloor2 = 23; int buttonToFloor3 = 24;                                                  // Buttons inside, send elevator to given floor
int buttonCallFloor1 = 25; int buttonCallFloor2down = 26; int buttonCallFloor2up = 27; int buttonCallFloor3 = 28;           // Button outside, call Elevator 
int buttonDoor = 29;  
int BPPin = A12; int BPin = A13; int APPin = A14; int APin = A15;

int i = 0;
int stepDelay = 5;

// Initialize global variables
int buttonInsideSelected, callElevatorFrom, currentFloor, toFloor, bInsideSelected, elevatorState;
boolean isDoorOpen, isDoorOpenTimer, isMoving; 

const long interval = 4000;  // Timer MS
unsigned long currentMillis = 0;


void setup() {
  Serial.begin(9600);
  setupVars();
//  dac_init();
//  set_dac(4095,4095);
  setupStep();
}

void loop() {

readElevatorButtonInside();
readElevatorButtonOutside();
timerCloseDoor();

 stepmotorOpen(stepDelay);   // 1 revolution clockwise
 stepmotorClose(stepDelay); // 1 revolution counterclockwise


}
