void stdPIDF(int BaseSpeed, float Kp, float Kd, int crossSpeed = 30) {
  Position = readLineF(380 , 50);
    int error = Position - 3500;
    PIDValue = (Kp * error) + (Kd * (error - last_error));
    last_error = error;
    if (PIDValue > BaseSpeed) PIDValue = BaseSpeed;
    if (PIDValue < -BaseSpeed) PIDValue = -BaseSpeed;
    leftPowerF = BaseSpeed + PIDValue;
    rightPowerF = BaseSpeed - PIDValue;
    if (leftPowerF >= 255) leftPowerF =  255;
    if (leftPowerF <= 10) leftPowerF = -180;
    if (rightPowerF >= 255) rightPowerF = 255;
    if (rightPowerF <= 10) rightPowerF = -180;
    motorControl(leftPowerF, rightPowerF);
}

void stdPIDB(int BaseSpeed, float Kp, float Kd, int crossSpeed = 30) {
    Position = readLineB(350, 50);
    int error = Position - 3500;
    PIDValue = (Kp * error) + (Kd * (error - last_error));
    last_error = error;
    if (PIDValue > BaseSpeed) PIDValue = BaseSpeed;
    if (PIDValue < -BaseSpeed) PIDValue = -BaseSpeed;
    leftPowerB = BaseSpeed + PIDValue;
    rightPowerB = BaseSpeed - PIDValue;
    if (leftPowerB >= 255) leftPowerB =  255;
    if (leftPowerB <= 10) leftPowerB = -180;
    if (rightPowerB >= 255) rightPowerB = 255;
    if (rightPowerB <= 10) rightPowerB = -180;
    motorControl(-leftPowerB ,-rightPowerB);
}

void PidChkCrossF(int BaseSpeed, float Kp, float Kd) {
  readLineF(380, 50);
  while (sensorValuesF[0] < 800 || sensorValuesF[7] < 800) stdPIDF(BaseSpeed, Kp, Kd);
  readLineF(380, 50);
  while (sensorValuesF[0] > 800 || sensorValuesF[7] > 800) stdPIDF(BaseSpeed, Kp, Kd);
}

void PidChkCrossB(int BaseSpeed, float Kp, float Kd) {
  readLineB(380, 50);
  while (sensorValuesB[0] < 800 || sensorValuesB[7] < 800) stdPIDB(BaseSpeed, Kp, Kd);
  readLineB(380, 50);
  while (sensorValuesB[0] > 800 || sensorValuesF[7] > 800) stdPIDB(BaseSpeed, Kp, Kd);
}
void PidStopF(int BaseSpeed, float Kp, float Kd) {
  readLineF(380, 50);
  while (sensorValuesF[0] < 800 || sensorValuesF[7] < 800) stdPIDF(BaseSpeed, Kp, Kd);
  STOP();
}

void PidStopB(int BaseSpeed, float Kp, float Kd) {
  readLineB(380, 50);
  while (sensorValuesB[0] < 800 || sensorValuesB[7] < 800) stdPIDB(BaseSpeed, Kp, Kd);
  STOP();
}


void PidChkLF(int BaseSpeed, float Kp, float Kd) {
  readLineF(380, 50);
  while (sensorValuesF[0] < 800 || sensorValuesF[1] < 800 || sensorValuesF[2] < 800) stdPIDF(BaseSpeed, Kp, Kd);
}

void PidChkRF(int BaseSpeed, float Kp, float Kd) {
  readLineF(380, 50);
  while (sensorValuesF[5] < 800 || sensorValuesF[6] < 800 || sensorValuesF[7] < 800) stdPIDF(BaseSpeed, Kp, Kd);
  STOP();
}

void PidChkLB(int BaseSpeed, float Kp, float Kd) {
  readLineB(380, 50);
  while (sensorValuesB[0] < 800 || sensorValuesB[1] < 800 || sensorValuesB[2] < 800) stdPIDB(BaseSpeed, Kp, Kd);
}

void PidChkRB(int BaseSpeed, float Kp, float Kd) {
  readLineB(380, 50);
  while (sensorValuesB[5] < 800 || sensorValuesB[6] < 800 || sensorValuesB[7] < 800) stdPIDB(BaseSpeed, Kp, Kd);
}

void PidCCF(int BaseSpeed, float Kp, float Kd, int Loop) {
  for (int i = 0; i < Loop; i++) {
    readLineF(380, 50);
    while (sensorValuesF[0] < 800 || sensorValuesF[7] < 800) stdPIDF(BaseSpeed, Kp, Kd);
    readLineF(380, 50);
    while (sensorValuesF[0] > 800 || sensorValuesF[7] > 800) stdPIDF(BaseSpeed, Kp, Kd);
  }
}

void PidCCB(int BaseSpeed, float Kp, float Kd, int Loop) {
  for (int i = 0; i < Loop; i++) {
    readLineB(380, 50);
    while (sensorValuesB[0] < 800 || sensorValuesB[7] < 800) stdPIDB(BaseSpeed, Kp, Kd);
    readLineB(380, 50);
    while (sensorValuesB[0] > 800 || sensorValuesB[7] > 800) stdPIDB(BaseSpeed, Kp, Kd);
  }
}

void PidTimerF(int BaseSpeed, float Kp, float Kd, int Timer) {
  unsigned long LastTime = millis();
  LastTime = LastTime + Timer;
  while (millis() <=  LastTime) {
    stdPIDF(BaseSpeed, Kp, Kd);
  }
}

void PidTimerB(int BaseSpeed, float Kp, float Kd, int Timer) {
  unsigned long LastTime = millis();
  LastTime = LastTime + Timer;
  while (millis() <=  LastTime) {
    stdPIDB(BaseSpeed, Kp, Kd);
  }
}
