void motorControl(int speed1, int speed2) {
  analogWrite(PWM1, abs(speed1));
  analogWrite(PWM2, abs(speed2));

  if (speed1 > 0) {
    digitalWrite(INA1, 1);
    digitalWrite(INB1, 0);
  }
  else {
    digitalWrite(INA1, 0);
    digitalWrite(INB1, 1);
  }

  if (speed2 > 0) {
    digitalWrite(INA2, 1);
    digitalWrite(INB2, 0);
  }
  else {
    digitalWrite(INA2, 0);
    digitalWrite(INB2, 1);
  }
}

void STOP() {
  digitalWrite(INA1, 1);
  digitalWrite(INB1, 1);
  digitalWrite(INA2, 1);
  digitalWrite(INB2, 1);
  analogWrite(PWM1, 0);
  analogWrite(PWM2, 0);
}
