
// Initialize buttonpins 
int buttonToFloor1 = 22; int buttonToFloor2 = 23; int buttonToFloor3 = 24;                                                 // Buttons inside, send elevator to given floor
int buttonCallFloor1 = 25; int buttonCallFloor2down = 26; int buttonCallFloor2up = 27; int buttonCallFloor3 = 28;    // Button outside, call Elevator 
int buttonDoor = 29;  
int BPPin = A12; int BPin = A13; int APPin = A14; int APin = A15;

int i = 0;



// Initialize global variables
int buttonInsideSelected, callElevatorFrom, currentFloor, toFloor, bInsideSelected, elevatorState;
boolean isDoorOpen, isDoorOpenTimer, isMoving; 

const long interval = 4000;  
unsigned long currentMillis = 0;


#include<Stepper.h>
const int stepsPerRevolution = 10000;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
//Stepper myStepper(stepsPerRevolution, BPPin,BPin,APPin,APin); 

Stepper myStepper(stepsPerRevolution, BPPin,APPin,BPin,APin); 
// Stepper driver: BPP 23, BPin 22, APin 21, APPin 20    Side 18 AIO servo lab
// Til Arduino: A15 APin, A14 APPin, A13 BPin, A12 BPPin  Side 18 AIO servo lab


int stepCount = 0;


void setup() {
  Serial.begin(9600);
  setupVars();
  myStepper.setSpeed(40);

}

void loop() {

  // put your main code here, to run repeatedly:

readElevatorButtonInside();
readElevatorButtonOutside();
timerCloseDoor();

startmotoren();

//myStepper.step(200);

/*
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  Serial.println(motorSpeed);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }

  */

//step_motor();
//start_motor();
//startlol(); // jevn aks DC motor
///startda(); // jevn deaks DC motor

// loopenloop();

}
