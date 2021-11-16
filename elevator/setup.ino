
// Variables
void setupVars() {
  currentFloor = 1;
  i = 0;
  stepDelay = 5;
  isDoorOpen = false;
  goUp = false;
  goDown = false;
  stay = false;

  prevTime = 0;
  pos = 0;
  posi = 0;
  target = 2048;
  ePrev = 0;
  eIntegral = 0;
  kp = 0.8;
  kd = 0.06;
  ki = 0;
}

// Setup DAC for step motor
void setupDAC() {
  dac_init();
  set_dac(4095, 4095);
}

// Pin numberes used for read/write
void setupPins() {
  buttonDoor = 22;
  buttonToFloor1 = 23;
  buttonToFloor2 = 24;
  buttonToFloor3 = 25;
  buttonCallFloor1 = 26;
  buttonCallFloor2down = 27;
  buttonCallFloor2up = 28;
  buttonCallFloor3 = 29;

  ENCA = 21;
  ENCB = 22;
  PWM = 5;
  DCEPin = 7;
  DCPPin = 6;
  DCDPin = 5;
  DCCPin = A3;
  BPPin = 66;
  BPin = 67;
  APPin = 68;
  APin = 69;

  floor1led = 48;
  floor2led = 47;
  floor3led = 46;
}

// Init pins 
void setupPinModes() {
  pinMode(floor1led, OUTPUT);
  pinMode(floor2led, OUTPUT);
  pinMode(floor3led, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  pinMode(PWM, OUTPUT);
  pinMode(DCPPin, OUTPUT);
  pinMode(DCEPin, OUTPUT);

  pinMode(BPPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(APPin, OUTPUT);
  pinMode(APin, OUTPUT);
  digitalWrite(BPPin, HIGH);
  digitalWrite(BPin, HIGH);
  digitalWrite(APPin, HIGH);
  digitalWrite(APin, HIGH);
}
