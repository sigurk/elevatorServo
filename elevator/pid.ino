
// Calculate PID values, executed in moveElevator() until posi reaches setpoint
void pid() {
  readButtons();

  // Time diff for u(t) calc
  long currT = micros();
  float deltaT = ((float) (currT - prevTime)) / ( 1.0e6 );
  prevTime = currT;

  // Atomic block used to ensure pos gets counted correctly, and not interfered by other code running
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = -posi;
  }

  // Error
  int e = -pos + target;
  // Derivative
  float dedt = (e - ePrev) / (deltaT);
  // Integral
  eIntegral = eIntegral + e * deltaT;

  // u(t) = kp + kd + ki. Kp kd and ki initialized in setup
  float u = kp * e + kd * dedt + ki * eIntegral;

  // Motor speed, setting max to 255 as we are only using Arduino
  float mSpeed = fabs(u);
  if ( mSpeed > 255 ) {
    mSpeed = 255;
  }

  // Motor direction
  int dir = 1;
  if (u < 0) {
    dir = -1;
  }

  // Motor CW or CCW depending on direction ( u(t) )
  analogWrite(PWM, mSpeed);
  if (goUp == true) {
    if (dir == -1) {
      digitalWrite(DCPPin, HIGH);
      digitalWrite(DCEPin, LOW);
    }
    else if (dir == 1) {
      digitalWrite(DCPPin, LOW);
      digitalWrite(DCEPin, HIGH);
    }
    else {
      digitalWrite(DCPPin, LOW);
      digitalWrite(DCEPin, LOW);
    }
  } else if (goDown == true) {
    if (dir == -1) {
      digitalWrite(DCPPin, HIGH);
      digitalWrite(DCEPin, LOW);
    }
    else if (dir == 1) {
      digitalWrite(DCPPin, HIGH);
      digitalWrite(DCEPin, HIGH);
    }
    else {
      digitalWrite(DCPPin, LOW);
      digitalWrite(DCEPin, LOW);
    }
  }


  // Previous error for next iteration
  ePrev = e;

  // Serial prints for plot of PID 
  //Serial.print(target);
  //Serial.print(pos);
}

// Int b start value encoder b, counts posi with rotation of encoder
void readEncoder() {
  int b = digitalRead(ENCB);
  if (b > 0) {
    posi = posi + 1;
  }
  else {
    posi = posi - 1;
  }
}
