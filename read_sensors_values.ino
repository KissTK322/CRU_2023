void displayValueF(int calibrateTime) {
  int readMin[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int readMax[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int sens = 0; sens <= 7 ; sens++) {
    readMin[sens] = 2500;
    readMax[sens] = 0;
  }
  Serial.println("Press A To Calibrate");
  Press();
  Serial.println("Calibrating");
  for (int j = 0; j < calibrateTime; j++) {
    readPrivateF();
    for (int i = 0; i < 8; i++) {
      // set the max we found THIS time
      if (j == 0 || readMax[i] < sensorValuesF[i])
        readMax[i] = sensorValuesF[i];
      // set the min we found THIS time
      if (j == 0 || readMin[i] > sensorValuesF[i])
        readMin[i] = sensorValuesF[i];
    }
    delay(2);
  }
  Serial.println("Calibrated");
  Serial.print("\n");
  Serial.print("int maxValueF[8] = {");
  for (i = 0; i < 8; i++) {
    Serial.print(readMax[i]);
    if (i != 7) Serial.print(",");
    else Serial.println("};");
  }
  Serial.print("int minValueF[8] = {");
  for (i = 0; i < 8; i++) {
    Serial.print(readMin[i]);
    if (i != 7) Serial.print(",");
    else Serial.println("};");
  }
}

void displayValueB(int calibrateTime) {
  int readMin[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  int readMax[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  for (int sens = 0; sens <= 7 ; sens++) {
    readMin[sens] = 2500;
    readMax[sens] = 0;
  }
  Serial.println("Press A To Calibrate");
  Press();
  Serial.println("Calibrating");
  for (int j = 0; j < calibrateTime; j++) {
    readPrivateB();
    for (int i = 0; i < 8; i++) {
      // set the max we found THIS time
      if (j == 0 || readMax[i] < sensorValuesB[i])
        readMax[i] = sensorValuesB[i];
      // set the min we found THIS time
      if (j == 0 || readMin[i] > sensorValuesB[i])
        readMin[i] = sensorValuesB[i];
    }
    delay(2);
  }
  Serial.println("Calibrated");
  Serial.print("\n");
  Serial.print("int maxValueB[8] = {");
  for (i = 0; i < 8; i++) {
    Serial.print(readMax[i]);
    if (i != 7) Serial.print(",");
    else Serial.println("};");
  }
  Serial.print("int minValueB[8] = {");
  for (i = 0; i < 8; i++) {
    Serial.print(readMin[i]);
    if (i != 7) Serial.print(",");
    else Serial.println("};");
  }
}
