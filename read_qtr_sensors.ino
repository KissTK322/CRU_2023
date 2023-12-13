void readPrivateF() {
  int i;
  for (i = 0; i < 8; i++) {
    sensorValuesF[i] = MAXVALUE;
    digitalWrite(sensorPinF[i], HIGH);
    pinMode(sensorPinF[i], OUTPUT);
  }
  delayMicroseconds(10);
  for (i = 0; i < NUMSENSOR; i++) {
    pinMode(sensorPinF[i], INPUT);
    digitalWrite(sensorPinF[i], LOW);
  }
  unsigned long _startTime = micros();
  while (micros() - _startTime < MAXVALUE) {
    unsigned int time = micros() - _startTime;
    for (i = 0; i < NUMSENSOR; i++) {
      if (digitalRead(sensorPinF[i]) == LOW && time < sensorValuesF[i]) sensorValuesF[i] = time;
    }
  }
}

void readPrivateB() {
  int i;
  for (i = 0; i < 8; i++) {
    sensorValuesB[i] = MAXVALUE;
    digitalWrite(sensorPinB[i], HIGH);
    pinMode(sensorPinB[i], OUTPUT);
  }
  delayMicroseconds(10);
  for (i = 0; i < NUMSENSOR; i++) {
    pinMode(sensorPinB[i], INPUT);
    digitalWrite(sensorPinB[i], LOW);
  }
  unsigned long _startTime = micros();
  while (micros() - _startTime < MAXVALUE) {
    unsigned int time = micros() - _startTime;
    for (i = 0; i < NUMSENSOR; i++) {
      if (digitalRead(sensorPinB[i]) == LOW && time < sensorValuesB[i]) sensorValuesB[i] = time;
    }
  }
}

void readCalibratedF() {
  readPrivateF();
  for ( i = 0; i < 8 ; i++) {
    unsigned int calmin, calmax;
    unsigned int denominator;
    calmax = maxValueF[i];
    calmin = minValueF[i];
    denominator = calmax - calmin;
    signed int x = 0;
    if (denominator != 0)
      x = (((signed long)sensorValuesF[i]) - calmin) * 1000 /denominator;
    x = (x < 0 ? 0 : x);
    //x = x  / denominator;
    if (x > 1000) x = 1000;
    sensorValuesF[i] = x ;
  }
}

void readCalibratedB() {
  readPrivateB();
  for ( i = 0; i < 8 ; i++) {
    unsigned int calmin, calmax;
    unsigned int denominator;
    calmax = maxValueB[i];
    calmin = minValueB[i];
    denominator = calmax - calmin;
    signed int x = 0;
    if (denominator != 0)
      x = (((signed long)sensorValuesB[i]) - calmin) * 1000 /denominator;
    x = (x < 0 ? 0 : x);
    //x = x  / denominator;
    if (x > 1000) x = 1000;
    sensorValuesB[i] = x ;
  }
}

int readLineF(int keep_track, int noise_threshold ) {
  unsigned char i, on_line = 0;
  unsigned long avg; // this is for the weighted total, which is long
  unsigned int sum; // this is for the denominator which is <= 64000
  static int last_value = 0; // assume initially that the line is left.
  readCalibratedF();
  avg = 0;
  sum = 0;
  for (i = 0 ; i < 8 ; i++) {
    int value = sensorValuesF[i];   //////cambio de flanco
    if (value > keep_track) {
      on_line = 1;
    }
    if (value > noise_threshold) { ///estaba en 50
      avg += (long)(value) * (i * 1000);
      sum += value;
    }
  }
  if (!on_line) {
    if (last_value < 3500)
      return 0;
    else
      return 7000;
  }
  last_value = avg / sum;
  return last_value;
}

int readLineB(int keep_track, int noise_threshold ) {
  unsigned char i, on_line = 0;
  unsigned long avg; // this is for the weighted total, which is long
  unsigned int sum; // this is for the denominator which is <= 64000
  static int last_value = 0; // assume initially that the line is left.
  readCalibratedB();
  avg = 0;
  sum = 0;
  for (i = 0 ; i < 8 ; i++) {
    int value = sensorValuesB[i];   //////cambio de flanco
    if (value > keep_track) {
      on_line = 1;
    }
    if (value > noise_threshold) { ///estaba en 50
      avg += (long)(value) * (i * 1000);
      sum += value;
    }
  }
  if (!on_line) {
    if (last_value < 3500)
      return 0;
    else
      return 7000;
  }
  last_value = avg / sum;
  return last_value;
}
