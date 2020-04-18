const char *autos[] = {"b back 8", "b back 5", "b front tower", "one point",
                       "r back 8", "r back 5", "r front tower", "one point",
                       "deploy",   "prog","none"};

void deploy() {
  drivePower(20);
  wait(300, msec);
  drivePower(0);
  setM(Roller1, 100);
  setM(Roller2, 100);
  setMR(Right1, 50);
  setMR(Right2, -50);
  setMR(Left1, 50);
  setMR(Left2, -50);
  wait(600, msec);
  setM(Right1, 0);
  setM(Right2, 0);
  setM(Left1, 0);
  setM(Left2, 0);
  setMR(Right1, -50);
  setMR(Right2, 50);
  setMR(Left1, -50);
  setMR(Left2, 50);
  wait(300, msec);
  setM(Lift, 100);
  setM(Lift2, 100);
  wait(1000, msec);
  setM(Lift, -100);
  setM(Lift2, -100);
  wait(300, msec);
  setM(Lift, -100);
  setM(Lift2, -100);
  wait(1000, msec);
  setM(Roller1, 0);
  setM(Roller2, 0);
  setM(Right1, 0);
  setM(Right2, 0);
  setM(Left1, 0);
  setM(Left2, 0);
  setM(Lift, 0);
  setM(Lift2, 0);
  // while(!Deploy.pressing())wait(30, msec);
  // log("back");
  // wait(400, msec);
  // drivePower(-70);
  // wait(500, msec);
  // drivePower(0);
}

void blueEight() {
  deploy();
  log("auto start");
  roller(100);
  drivePower(30);
  wait(300, msec);
  drivePower(35);
  wait(1800, msec);
  drivePower(0);
  wait(50, msec);
  turn(6.5);
  driveForwardPID(-6.1, 1200);
  turn(-7.5);
  wait(50, msec);
  drivePower(55);
  wait(1500, msec);
  roller(20);
  turn(-30.6);
  drivePower(0);
  wait(50, msec);
  drivePower(100);
  wait(700, msec);
  drivePower(30);
  wait(600, msec);
  roller(-12);
  drivePower(15);
  wait(25, msec);
  moveFront();
  roller(-35);
  drivePower(-45);
  wait(1200, msec);
  roller(0);
  drivePower(0);
  moveBack();
  log("done");
}
void blueFive() {
  deploy();
  log("auto start");
  roller(100);
  drivePower(20);
  wait(500, msec);
  drivePower(35);
  wait(2500, msec);
  roller(20);
  turn(-30.6);
  drivePower(0);
  wait(50, msec);
  drivePower(100);
  wait(700, msec);
  drivePower(30);
  wait(900, msec);
  roller(-18);
  drivePower(30);
  wait(25, msec);
  moveFront();
  roller(-35);
  drivePower(-45);
  wait(1200, msec);
  roller(0);
  drivePower(0);
  moveBack();
  log("done");
}

void blueTower() {
  deploy();
  roller(80);
  drivePower(20);
  wait(1400, msec);
  drive(0);
  wait(700, msec);
  roller(-20);
  wait(700, msec);
  roller(0);
  turn(-19);
  drivePower(30);
  wait(650, msec);
  while (Lift.rotation(rev) < 3.2) {
    int rampOut = 30;
    setMR(Right1, rampOut);
    setMR(Right2, -rampOut);
    setMR(Left1, rampOut);
    setMR(Left2, -rampOut) setM(Lift, 100);
    setM(Lift2, 100);
  }
  drivePower(30);
  setM(Lift, 0);
  setM(Lift2, 0);
  wait(300, msec);
  roller(-100);
  wait(1000, msec);
  roller(0);
  drive(-30);
  wait(500, msec);
  drive(0);
  setM(Lift, -30);
  setM(Lift2, -30);
  wait(300, msec);
  setM(Lift, 0);
  setM(Lift2, 0);
}

void redEight() {
  deploy();
  log("auto start");
  roller(100);
  drivePower(30);
  wait(300, msec);
  drivePower(25);
  wait(3000, msec);
  drivePower(0);
  wait(50, msec);
  turn(-6.5);
  driveForwardPID(-6.5, 1200);
  turn(7.5);
  drivePower(-30);
  wait(300, msec);
  drivePower(55);
  wait(2000, msec);
  roller(20);
  turn(30.6);
  drivePower(0);
  wait(50, msec);
  drivePower(100);
  wait(900, msec);
  drivePower(30);
  wait(600, msec);
  roller(-16);
  drivePower(15);
  wait(25, msec);
  moveFront();
  roller(-35);
  drivePower(-45);
  wait(1200, msec);
  roller(0);
  drivePower(0);
  moveBack();
  log("done");
}
void redFive() {
  deploy();
  log("auto start");
  roller(100);
  drivePower(20);
  wait(500, msec);
  drivePower(35);
  wait(3000, msec);
  roller(20);
  turn(30.6);
  drivePower(0);
  wait(50, msec);
  drivePower(100);
  wait(900, msec);
  drivePower(30);
  wait(900, msec);
  roller(-18);
  drivePower(30);
  wait(25, msec);
  moveFront();
  roller(-35);
  drivePower(-45);
  wait(1200, msec);
  roller(0);
  drivePower(0);
  moveBack();
  log("done");
}

void redTower() {
  deploy();
  roller(80);
  drivePower(20);
  wait(1400, msec);
  drive(0);
  wait(700, msec);
  roller(-20);
  wait(700, msec);
  roller(0);
  turn(19);
  drivePower(30);
  wait(650, msec);
  while (Lift.rotation(rev) < 3.2) {
    int rampOut = 30;
    setMR(Right1, rampOut);
    setMR(Right2, -rampOut);
    setMR(Left1, rampOut);
    setMR(Left2, -rampOut) setM(Lift, 100);
    setM(Lift2, 100);
  }
  drivePower(30);
  setM(Lift, 0);
  setM(Lift2, 0);
  wait(300, msec);
  roller(-100);
  wait(1000, msec);
  roller(0);
  drive(-30);
  wait(500, msec);
  drive(0);
  setM(Lift, -30);
  setM(Lift2, -30);
  wait(300, msec);
  setM(Lift, 0);
  setM(Lift2, 0);
}

void onePoint(){
  drivePower(-100);
  wait(500,msec);
  drivePower(100);
  wait(500,msec);
  drivePower(0);
  deploy();
  // drivePower(100);
  // wait(1000,msec);
}

void prog(){
  blueEight();
}