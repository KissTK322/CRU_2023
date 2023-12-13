void r1(){
  //เดินหน้าเลี้ยวซ้ายุจุดดแรก
  PidTimerF(90 , 0.038 , 0.47 , 300); STOP();
  PidStopF(75 , 0.038 , 0.47 ); 
  //motorControl(-90 , -90);delay(20);
  STOP();delay(30);
  spinLeftF();STOP();delay(15);
}

void r2(){
  //เดินหน้าเลี้ยวขวา
  PidTimerF(90 , 0.038 , 0.5 , 450); STOP();
  PidChkRF(75 , 0.038 , 0.5); STOP();delay(20);
  spinRightF();STOP();delay(30);
}

void r3(){
  //ดเดินหน้าเลี้ยวขวา
  PidTimerF(80 , 0.038 , 0.5 , 90); STOP();
  PidTimerF(95 , 0.039 , 0.5 , 130); STOP();
  PidTimerF(115 , 0.038 , 0.5 , 210); STOP();
  PidTimerF(95 , 0.039 , 0.5 , 130); STOP();
  PidChkRF(75 , 0.038 , 0.5); STOP();delay(20);
  
  spinRightF();STOP();delay(30);
}


//ใน loop for 2 รอบ
void r4(){
  //เดินหน้าหยุดรอของ
  PidStopF(75 , 0.042 , 0.46);
  STOP();delay(1000);
} 

void r5(){
  //รับของ
}

void r6(){
  //ถอยหลังเลี้ยวขวา
  PidTimerB(80 , 0.038 , 0.55 , 250); STOP();
 // PidStopB(80 , 0.038 , 0.47); STOP();delay(20);
  //motorControl(110 , 110);delay(30);
  //spinRightB();STOP();delay(30);//ถอยหลังเลี้ยวขวา
}

void r7(){
  //เดินหน้าเลี้ยวขวา
  PidTimerB(100 , 0.038 , 0.47 , 300); STOP();
  PidChkRB(100 , 0.038 , 0.47 ); STOP();delay(20);
  spinRightB(); STOP();delay(30);
}

void r8(){
  //เดินหน้าเลี้ยวซ้าย
  PidChkLB(100 , 0.038 , 0.47 ); STOP();delay(20);
  spinLeftB(); STOP();delay(30);
}

void r9(){
  //เดินหน้าหยุุด
  PidTimerB(100 , 0.038 , 0.47 , 300); STOP();
  PidStopB(100 , 0.038 , 0.47 ); STOP();delay(20);
}

void r10(){
  //โค้งวงกลมใหญ
  PidTimerB(100 , 0.038 , 0.47 , 200); STOP();
  PidStopB(105 , 0.05 , 0.65 ); STOP();delay(20);
}

void r11(){
 //เดินหน้าเลี้ยวซ้าย
  PidTimerB(100 , 0.038 , 0.47 , 300); STOP();
  PidChkLB(100 , 0.038 , 0.47 ); STOP();delay(20);
  spinLeftB(); STOP();delay(30); 
}

void r12(int i){
 //ส่งของ
  PidChkRB(100 , 0.038 , 0.47 ); STOP();delay(20);
  if(i == 2) {
    PidChkLB(100 , 0.038 , 0.47 ); STOP();delay(20);
    PidChkLF(100 , 0.038 , 0.47); STOP();delay(20);
    PidTimerF(100 , 0.038 , 0.47 , 200); STOP();
  } 
}

void r13(){
  //เดินหน้าเลี้ยวขวา
  PidStopF(100 , 0.038 , 0.47); STOP();delay(20);
  spinRightF();STOP();delay(30);
}

void r14(){
  //เดินหน้าเลี้ยวซ้าย
  PidTimerF(100 , 0.038 , 0.47 , 150); STOP();
  PidStopF(90 , 0.038 , 0.47 ); STOP();delay(20);
  spinLeftF();STOP();delay(30);
}

void r15(){
  //เดินหน้าเลี้ยวขวา
  PidTimerF(100 , 0.038 , 0.47 , 150); STOP();
  PidChkRF(100 , 0.038 , 0.47); STOP();delay(20);
  spinRightF();STOP();delay(30);
}

void r16(){
  //เดินหน้าเลี้ยวซ้าย
  PidTimerF(100 , 0.038 , 0.47, 150); STOP();
  PidChkLF(100 , 0.038 , 0.47); STOP();delay(20);
  spinLeftF();STOP();delay(30);
}

void r17(){
  //เดินหน้าเลี้ยวซ้าย
  PidTimerF(100 , 0.038 , 0.47, 150); STOP();
  PidChkLF(100 , 0.038 , 0.47); STOP();delay(20);
  spinLeftF();STOP();delay(30);
}

void r18(){
  //หยุดรอ
  PidStopF(90 , 0.038 , 0.47); STOP();delay(25);
}
