void spinLeftF() {
  motorControl(-110, 110); delay(50);
  readLineF(380, 50);
  while (sensorValuesF[1] < 800) readLineF(220, 50);
  //motorControl(-130, 130); delay(40);
  STOP();
}

void spinRightF() {
  motorControl(110, -110); delay(50);
  readLineF(380, 50);
  while (sensorValuesF[6] < 800) readLineF(220, 50);
  //motorControl(130, -130); delay(40);
  STOP();
}

void spinLeftB() {
  motorControl(-110, 110); delay(50);
  readLineB(380, 50);
  while (sensorValuesB[1] < 800) readLineB(220, 50);
  //motorControl(130, -130); delay(40);
  STOP();
}

void spinRightB() {
  motorControl(110, -110); delay(50);
  readLineB(380, 50);
  while (sensorValuesB[6] < 800) readLineB(220, 50);
  //motorControl(-130, 130); delay(40);
  STOP();
}
