void monitorSensorF() {
  while (1) {
    Serial.print(readLineF(380, 50)); Serial.print("\t");
    for (int k = 0; k < 8; k++) {
      Serial.print(sensorValuesF[k]); Serial.print("\t");
    }
    Serial.print("\n");
    delay(10);
  }
}

void monitorSensorB() {
  while (1) {
    Serial.print(readLineB(350, 50)); Serial.print("\t");
    for (int k = 0; k < 8; k++) {
      Serial.print(sensorValuesB[k]); Serial.print("\t");
    }
    Serial.print("\n");
    delay(10);
  }
}
