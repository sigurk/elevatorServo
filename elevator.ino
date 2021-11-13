#include <dac.h>
#include <LiquidCrystal.h>

// Initialize buttonpins: 
int buttonToFloor1 = 23; int buttonToFloor2 = 24; int buttonToFloor3 = 25;                                                  // Buttons inside, send elevator to given floor
int buttonCallFloor1 = 26; int buttonCallFloor2down = 27; int buttonCallFloor2up = 28; int buttonCallFloor3 = 29;           // Button outside, call Elevator 
int buttonDoor = 22;  

//Initialize led lights:
int floor1led = 48; 
int floor2led = 47;
int floor3led = 46;

//Initialize lcd pins;:  
const int rs = 41, en = 40, d4 = 37, d5 = 36, d6 = 35, d7 = 34;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Initialize Step and DC motor pins:
int BPPin = 66; int BPin = 67; int APPin = 68; int APin = 69; // Step-motor Pins
int DCEPin = 7; int DCPPin = 6; int DCDPin = 5; int DCCPin = A3; // DC-motor Pins

int i = 0;
int stepDelay = 5;

// Initialize global variables
int buttonInsideSelected, callElevatorFrom, currentFloor, toFloor, bInsideSelected, elevatorState;
boolean isDoorOpen, isDoorOpenTimer, isMoving; 



void setup() {

  ///    encoder pins er 20 og 21, (feil i dokumentasjon)
  Serial.begin(9600);
  pinMode(floor1led,OUTPUT);
  pinMode(floor2led,OUTPUT);
  pinMode(floor3led,OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH); //sets LCD screen backlight to full.
  
  setupVars();
  floorIndicator();
  dac_init();
  set_dac(4095,4095);
  setupStepVars();
  
}

void loop() {
readElevatorButtonInside();
readElevatorButtonOutside();



}
