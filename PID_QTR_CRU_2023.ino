#define NUMSENSOR   8
#define MAXVALUE    2500
#define EMITTER_PIN   -1

#define INA2 8
#define INB2 7
#define PWM2 5
#define INA1 4
#define INB1 9
#define PWM1 6
     
int sensorPinF[NUMSENSOR] = {31,32, 33, 34, 35, 36, 37, 38};
int maxValueF[8] = {2500,2500,2500,2500,2500,2500,2500,2500};
int minValueF[8] = {312,356,356,356,360,404,412,592};


int sensorPinB[NUMSENSOR] = {41,42, 43, 44, 45, 46, 47, 49};
int maxValueB[8] = {2500,2500,2500,2500,2500,2500,2500,2500};
int minValueB[8] = {828,724,828,936,1048,1040,1260,1256};

//int maxValueB[8] = {2500,2500,2500,2500,2500,2500,2500,2500};
//int minValueB[8] = {416,572,468,472,468,416,468,736};

unsigned int sensorValuesF[8];
unsigned int sensorValuesB[8];
unsigned char i, j;

unsigned int Position = 0;
int leftPowerF, rightPowerF , leftPowerB, rightPowerB;
int error, last_error;
int PIDValue;

void setup() {
  Serial.begin(9600);
  initRobot();
  //displayValueB(800);
  //monitorSensorB();
  while(1){
  Press();
  motorControl(50 , 50); delay(1000);
  //PidTimerB(80 , 0.038 , 0.55 , 500);
  STOP();
} 
//  STOP();delay(10000000);
//  displayValueF(800);
  //monitorSensorF();
  /*while(1){
   Press();
   PidTimerF(75 , 0.035 , 0.5 , 1000); STOP();
   //PidTimerF(85 , 0.036 , 0.44 , 1000); STOP();
   //PidTimerF(95 , 0.038 , 0.45 , 1000); STOP();
  }*/
  //r1();
  Run();
  
  //ส่าย ลด kd เพิ่ม kp 
  //หน่วง ลด kp เพิ่ม kd
}

void loop() {
  STOP();
}

void initRobot(void) {
  Serial.begin(9600);
  pinMode(53,INPUT);
  for(int i=31;i<39;i++){
    pinMode(i,INPUT);
  }
}

void Press(){
  while(digitalRead(53)==1){
  }
}
