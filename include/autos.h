const char *autos[] = {"five back",
                       "four front",
                       "back tower",
                       "middle tower",
                       "five back",
                       "four front",
                       "back tower",
                       "middle tower",
                       "One Point"
                       "deploy",
                       "prog",
                       "none"};

void deploy() {
  roller(-100);
  setM(Lift, 100);
  wait(1400, msec);
  roller(0);
  // drivePower(30);
  setM(Lift, 0);
  setM(Tray, 0);
  wait(700, msec);
  // drivePower(0);
  setM(Lift, 100);
  setM(Tray, 100);
  wait(400, msec);
  drivePower(-100);
  setM(Tray, -100);
  setM(Lift, -100);
  wait(1100, msec);
  setM(Tray, 0);
  setM(Lift, 0);
  drivePower(0);
  // wait(400,msec);
  // roller(10);
  // setM(Lift,0);
  // wait(700,msec);
  // setM(Lift,100);
  // setM(Tray,100);
  // wait(700,msec);
  // Tray.rotateTo(0,rev,false);
  // Lift.rotateTo(0,rev);
  // setM(Lift,0);
  // setM(Tray,0);

  // wait(50,msec);
  // roller(-100);
  // setM(Lift,100);
  // setM(Tray,0);
  // wait(300,msec);
  // setM(Lift,0);
  // wait(400,msec);
  // setM(Lift,100);
  // wait(1000,msec);
  // setM(Lift,-100);
  // setM(Tray,-50);
  // wait(100,msec);
  // setM(Tray,0);
  // wait(400,msec);
  // setM(Lift,0);
}

void cubeDump() {
  roller(-15);
  wait(200, msec);
  roller(0);
  while (Tray.position(rev) < 3.2)
    setM(Tray, 90);
  setM(Tray, 0);
  drivePower(60);
  wait(120, msec);
  drivePower(0);
  wait(300, msec);
  drivePower(-100);
  wait(600, msec);
  drivePower(0);
  roller(0);
  moveBack();
}

// void blueEight() {
//   deploy();
//   log("auto start");
//   roller(100);
//   drivePower(30);
//   wait(300, msec);
//   drivePower(35);
//   wait(1800, msec);
//   drivePower(0);
//   wait(50, msec);
//   turn(6.5);
//   driveForwardPID(-6.1, 1200);
//   turn(-7.5);
//   wait(50, msec);
//   drivePower(55);
//   wait(1500, msec);
//   roller(20);
//   turn(-30.6);
//   drivePower(0);
//   wait(50, msec);
//   drivePower(100);
//   wait(700, msec);
//   drivePower(30);
//   wait(600, msec);
//   roller(-12);
//   drivePower(15);
//   wait(25, msec);
//   moveFront();
//   roller(-35);
//   drivePower(-45);
//   wait(1200, msec);
//   roller(0);
//   drivePower(0);
//   moveBack();
//   log("done");
// }
// void blueFive() {
//   deploy();
//   log("auto start");
//   roller(100);
//   drivePower(20);
//   wait(500, msec);
//   drivePower(35);
//   wait(2500, msec);
//   roller(20);
//   turn(-30.6);
//   drivePower(0);
//   wait(50, msec);
//   drivePower(100);
//   wait(700, msec);
//   drivePower(30);
//   wait(900, msec);
//   roller(-18);
//   drivePower(30);
//   wait(25, msec);
//   moveFront();
//   roller(-35);
//   drivePower(-45);
//   wait(1200, msec);
//   roller(0);
//   drivePower(0);
//   moveBack();
//   log("done");
// }

// void blueTower() {
//   deploy();
//   roller(80);
//   drivePower(20);
//   wait(1400, msec);
//   drive(0);
//   wait(700, msec);
//   roller(-20);
//   wait(700, msec);
//   roller(0);
//   turn(-19);
//   drivePower(30);
//   wait(650, msec);
//   while (Lift.rotation(rev) < 3.2) {
//     int rampOut = 30;
//     setMR(Right1, rampOut);
//     setMR(Right2, -rampOut);
//     setMR(Left1, rampOut);
//     setMR(Left2, -rampOut) setM(Lift, 100);
//     setM(Lift2, 100);
//   }
//   drivePower(30);
//   setM(Lift, 0);
//   setM(Lift2, 0);
//   wait(300, msec);
//   roller(-100);
//   wait(1000, msec);
//   roller(0);
//   drive(-30);
//   wait(500, msec);
//   drive(0);
//   setM(Lift, -30);
//   setM(Lift2, -30);
//   wait(300, msec);
//   setM(Lift, 0);
//   setM(Lift2, 0);
// }

// void redEight() {
//   deploy();
//   log("auto start");
//   roller(100);
//   drivePower(30);
//   wait(300, msec);
//   drivePower(25);
//   wait(3000, msec);
//   drivePower(0);
//   wait(50, msec);
//   turn(-6.5);
//   driveForwardPID(-6.5, 1200);
//   turn(7.5);
//   drivePower(-30);
//   wait(300, msec);
//   drivePower(55);
//   wait(2000, msec);
//   roller(20);
//   turn(30.6);
//   drivePower(0);
//   wait(50, msec);
//   drivePower(100);
//   wait(900, msec);
//   drivePower(30);
//   wait(600, msec);
//   roller(-16);
//   drivePower(15);
//   wait(25, msec);
//   moveFront();
//   roller(-35);
//   drivePower(-45);
//   wait(1200, msec);
//   roller(0);
//   drivePower(0);
//   moveBack();
//   log("done");
// }
// void redFive() {
//   deploy();
//   log("auto start");
//   roller(100);
//   drivePower(20);
//   wait(500, msec);
//   drivePower(35);
//   wait(3000, msec);
//   roller(20);
//   turn(30.6);
//   drivePower(0);
//   wait(50, msec);
//   drivePower(100);
//   wait(900, msec);
//   drivePower(30);
//   wait(900, msec);
//   roller(-18);
//   drivePower(30);
//   wait(25, msec);
//   moveFront();
//   roller(-35);
//   drivePower(-45);
//   wait(1200, msec);
//   roller(0);
//   drivePower(0);
//   moveBack();
//   log("done");
// }

// void redTower() {
//   deploy();
//   roller(80);
//   drivePower(20);
//   wait(1400, msec);
//   drive(0);
//   wait(700, msec);
//   roller(-20);
//   wait(700, msec);
//   roller(0);
//   turn(19);
//   drivePower(30);
//   wait(650, msec);
//   while (Lift.rotation(rev) < 3.2) {
//     int rampOut = 30;
//     setMR(Right1, rampOut);
//     setMR(Right2, -rampOut);
//     setMR(Left1, rampOut);
//     setMR(Left2, -rampOut) setM(Lift, 100);
//     setM(Lift2, 100);
//   }
//   drivePower(30);
//   setM(Lift, 0);
//   setM(Lift2, 0);
//   wait(300, msec);
//   roller(-100);
//   wait(1000, msec);
//   roller(0);
//   drive(-30);
//   wait(500, msec);
//   drive(0);
//   setM(Lift, -30);
//   setM(Lift2, -30);
//   wait(300, msec);
//   setM(Lift, 0);
//   setM(Lift2, 0);
// }
void five(double turnV) {
  deploy();
  roller(100);
  drivePower(33);
  wait(3100, msec);
  drivePower(0);
  wait(200, msec);
  roller(5);
  // roller(100);
  // drive(35);
  // roller(40);
  // drive(25);
  // roller(100);
  // wait(500,msec);
  // drive(10);
  // turn in
  // drivePower(-100);
  // wait(950,msec);
  // roller(0);
  // drivePower(0);
  // wait(200,msec);
  // driveForwardPID(4,500);
  // turn(turnV);
  // driveForwardPID(12.5,1300);
  turn(turnV);
  drivePower(95);
  wait(800, msec);
  drivePower(0);
  cubeDump();
}
void redFive() {
  five(23.5);
  // 19
}
void redEight() {}
void redBackTower() {}
void redMiddleTower() {}

void blueFive() {
  five(-23);
  //-19
}
void blueEight() {}
void blueBackTower() {}
void blueMiddleTower() {
  roller(100);
  drive(30);
  turn(-14);
  roller(-20);
  wait(1000, msec);
  roller(0);
  Lift.setBrake(hold);
  Tray.rotateTo(1.4,rev,false);
  Lift.rotateTo(2.4,rev,false);
  wait(3400,msec);
  drive(20);
  roller(-40);
  wait(1000,msec);
  drive(-20);
  Lift.setBrake(coast);
  Lift.stop();
}

void onePoint() {
  drivePower(100);
  wait(500, msec);
  drivePower(-100);
  wait(500, msec);
  drivePower(0);
  wait(500, msec);
  deploy();
}

void blueFrontFour(){
  deploy();
  roller(90);
  driveForwardPID(21, 1300);
  turn(-16);
  drive(20);
  turn(2);
  roller(50);
  driveForwardPID(-5, 1200);
  turn(26);
  drive(35);
  turn(7);
  drivePower(100);
  wait(250,msec);
  drivePower(0);
  roller(-50);
  wait(400,msec);
  roller(0);
  cubeDump();
}

void redFrontFour(){
  deploy();
  roller(90);
  driveForwardPID(21, 1300);
  turn(16);
  drive(20);
  turn(-2);
  roller(50);
  driveForwardPID(-5, 1200);
  turn(-26);
  drive(35);
  turn(-7);
  drivePower(100);
  wait(250,msec);
  drivePower(0);
  roller(-50);
  wait(400,msec);
  roller(0);
  cubeDump();
}

void prog() {
  //   blueEight();
}