
#include <dac.h>                  // Step/door motor 
#include <LiquidCrystal.h>        // LCD display
#include <Deque.h>                // Queue library https://github.com/Zarfab/ArduinoDeque
#include <util/atomic.h>          // For interrupt in PID

// Init, values set under "setup"
int buttonDoor, buttonToFloor1, buttonToFloor2, buttonToFloor3, buttonCallFloor1, buttonCallFloor2down, buttonCallFloor2up, buttonCallFloor3, buttonInsideSelected, callElevatorFrom, currentFloor, toFloor;
int ENCA, ENCB, PWM, BPPin, BPin, APPin, APin, DCEPin, DCPPin, DCDPin, DCCPin, floor1led, floor2led, floor3led;
int i, stepDelay, pos, target, ePrev, eIntegral, m;
boolean isDoorOpen, isDoorOpenTimer, goUp, goDown, stay; 
long prevTime;
float kp, kd, ki;
volatile int posi;                // pos for PID. In certain conditions normal ints from register can be inaccurate. To be sure, save as volatile which runs from RAM. More detailed here: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/

// Init global LCD and queue
const int rs = 41, en = 40, d4 = 37, d5 = 36, d6 = 35, d7 = 34;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Deque<int> queue;                 // Init double-ended queue list, Deque.h

void setup() {
  
  Serial.begin(9600);

  // Assign values for variables and pins
  setupPins();
  setupPinModes();
  setupDAC();
  setupVars();
  
  floorIndicator();                   // Light up starting floor at startup

  lcd.begin(16, 2);
  digitalWrite(4, HIGH);              // Sets LCD screen backlight to full
}

void loop() {

  readButtons();                      // Read button inputs, execute or add to queue
  
  executeQueue(queue.peek_front());   // Iterate queue, run if != empty

}
