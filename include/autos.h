//Stores auto names for screen
const char *autos[] = {"red front 4",  "red 6",  "red 7",  "red 5",
                       "blue front 4", "blue 6", "blue 7", "blue 5",
                       "one",          "prog", "none"};

//Deploys robot at start of match - 1.6 seconds
void deploy() {
  drivePower(-5);
  roller(100);
  setM(Tray, 0);
  setM(Lift, 100);
  wait(350, msec);
  setM(Tray, 100);
  wait(500, msec);
  roller(100);
  setM(Lift, -100);
  setM(Tray, -100);
  wait(400, msec);
  setM(Tray, -10);
  wait(600, msec);
  roller(0);
  setM(Lift, 0);
  setM(Tray, 0);
  drivePower(0);
  // setM(Tray,100);
  // wait(500, msec);
  // setM(Tray,-100);
  // wait(500, msec);
  // setM(Tray,0);
}

//Deploys a stack into the zone
void cubeDump() {
  //get cube to correct spot
  while (RollerLine.value(pct) > cubeTune) {
    roller(20);
    wait(20, msec);
  }
  // up to five 200
  // five plus 80
  wait(40, msec);
  roller(0);
  Roller1.setBrake(hold);
  Roller2.setBrake(hold);
  drivePower(0);
  roller(10);
  //tray forward full speed
  while (Tray.position(rev) < .8) {
    setM(Tray, 100);
    wait(30, msec);
  }
  roller(0);
  //slow tray down
  while (Tray.position(rev) < 1.55) {
    setMR(Tray, 33);
    wait(30, msec);
  }
  Roller1.setBrake(coast);
  Roller2.setBrake(coast);
  setM(Tray, 0);
  drivePower(5);
  roller(60);
  wait(600, msec);
  roller(80);
  setM(Tray, -100);
  drivePower(-50);
  wait(500, msec);
  drivePower(0);
  //reset tray
  while (Tray.position(rev) > 0) {
    setM(Tray, -100);
    wait(30, msec);
  }
  setM(Tray, 0);
}

//One point preload autonomous
void onePoint() {
  drivePower(-100);
  wait(500, msec);
  drivePower(100);
  wait(500, msec);
  drivePower(0);
  wait(500, msec);
  deploy();
}

//red 4 line + preload
void redFivePreload() { // working!!!!!
  deploy();
  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(44, 1300, 60);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(.5, 400);
  driveForward(-30, 1300, 100);
  turnC(1.3, 800, 60);
  driveForward(15, 1200, 50);
  setM(Right1, -50);
  setM(Right2, -50);
  wait(200, msec);
  drivePower(50);
  wait(650, msec);
  drivePower(0);
  roller(0);
  wait(200, msec);
  cubeDump();
}

//blue 4 line + preload
void blueFivePreload() { // working!!!!!
  deploy();

  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(44, 1300, 60);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(-.4, 400);
  driveForward(-30, 1300, 100);
  turnC(-1.2, 800, 60);
  driveForward(15, 1200, 50);
  setM(Left1, -50);
  setM(Left2, -50);
  wait(200, msec);
  drivePower(50);
  wait(650, msec);
  drivePower(0);
  roller(0);
  wait(200, msec);
  cubeDump();
}

//red 4 line, tower cube + preload
void sixRedPreload() {
  deploy();
  roller(-100);
  
  setM(Lift,-50);
  setM(Tray, -10);
  driveForward(41, 1700, 40);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(-.35, 500);
  driveForward(6, 400);
  driveForward(-6, 400);
  turnC(.6, 650);

  driveForward(-32, 1300, 100);

  turnC(1.3, 800, 70);
  driveForward(15, 1200, 50);
  setM(Right1, -50);
  setM(Right2, -50);
  wait(200, msec);
  drivePower(35);
  cubeDump();
}

//blue 4 line, tower cube + preload
void sixBluePreload() {
  deploy();
  setM(Lift,-100);
  
  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(38, 1700, 40);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(.35, 500);
  driveForward(6, 400);
  driveForward(-6, 400);
  turnC(-.5, 650);

  driveForward(-32, 1300, 100);

  turnC(-1.2, 800, 70);
  driveForward(15, 1200, 50);
  setM(Left1, -50);
  setM(Left2, -50);
  wait(200, msec);
  drivePower(35);
  cubeDump();
}

//red 4 line, 2 tower cubes + preload
void sevenBluePreload() {
  deploy();

  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(37, 1400, 40);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(.4, 500);
  driveForward(6, 400);
  driveForward(-6, 400);
  turnC(-.47, 450);
  driveForward(7, 450, 40);
  turnC(-.27, 300);
  driveForward(-41, 1200, 100);

  turnC(-1.03, 800, 70);
  driveForward(15, 900, 60);
  setM(Left1, -70);
  setM(Left2, -70);
  wait(350, msec);
  drivePower(50);
  cubeDump();
}

//blue 4 line, 2 tower cubes + preload
void sevenRedPreload() {
  deploy();

  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(38, 1400, 40);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(-.4, 500);
  driveForward(6, 400);
  driveForward(-6, 400);
  turnC(.45, 450);
  driveForward(7, 450, 40);
  turnC(.3, 300);
  driveForward(-41, 1100, 100);

  turnC(1.25, 800, 70);
  driveForward(16, 1000, 60);
  setM(Right1, -70);
  setM(Right2, -70);
  wait(350, msec);
  drivePower(50);
  cubeDump();
}

//red protected court 4 cube
void redFrontFour() {
  deploy();
  
  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(18, 1000, 60);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(1.2, 1000);
  driveForward(7, 800, 80);
  turnC(2.16, 1300, 50);
  driveForward(12, 800, 60);
  turnC(.61, 800);
  driveForward(19, 900, 100);
  turnC(-.74, 900);
  drivePower(0);
  drivePower(50);
  cubeDump();
}

//blue protected court 4 cube
void blueFrontFour() {
  deploy();
  setM(Lift,-50);
  setM(Tray, -10);
  roller(-100);
  driveForward(19, 1000, 60);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  turnC(-1.3, 1000);
  driveForward(7, 800, 80);
  turnC(-2.13, 1300, 90);
  driveForward(12, 800, 60);
  turnC(-.64, 800);
  driveForward(19, 900, 100);
  turnC(1.09, 900);
  drivePower(0);
  drivePower(60);
  cubeDump();
}

//programming skills - 27 points
void prog() {
  deploy();
  Tray.setBrake(hold);
  Roller1.setBrake(brake);
  Roller2.setBrake(brake);
  setM(Lift,-50);
  setM(Tray, -10);
  drivePower(-10);
  wait(1000,msec);
  setM(Tray, 0);
  setM(Lift,0);
  Tray.resetRotation();
  Lift.resetRotation();
  drivePower(0);
  wait(500,msec);
  roller(-100);
  driveForward(11, 1000, 30);
  turnC(.72, 1000, 60);
  driveForward(7, 500, 30);
  roller(30);
  wait(500, msec);
  roller(0);
  //lift up
  while (Lift.position(rev) < 0.65) {
    setM(Lift, 100);
    wait(30, msec);
  }
  setM(Lift, 0);
  driveForward(3, 500, 30);
  roller(30);
  wait(1000, msec);
  turnC(-.15,500);
  driveForward(-18, 1200, 60);
  //lift down
  while (Lift.position(rev) > -0) {
    setM(Lift, -100);
    wait(30, msec);
  }
  turnC(-.58, 1200, 80);
  roller(-100);
  driveForward(28, 2500, 40);
  turnC(-.37, 1000);
  driveForward(6, 1000, 40);
  driveForward(-13, 1000, 40);
  turnC(.42, 1000);
  driveForward(20, 1500, 30);
  turnC(-.11, 500, 60);
  driveForward(55, 3000, 45);
  turnC(.57, 1500, 60);
  driveForward(12, 1000, 40);
  //cubes out
  while (TrayLine.value(pct) > cubeTune) {
    roller(15);
    wait(20, msec);
  }
  // wait(30, msec);
  roller(0);
  // Roller1.setBrake(hold);
  // Roller2.setBrake(hold);
  drivePower(0);
  // roller(10);
  //tray fast out
  while (Tray.position(rev) < .8) {
    setM(Tray, 100);
    wait(30, msec);
  }
  roller(0);
  //tray slow out
  while (Tray.position(rev) < 1.6) {
    setMR(Tray, 33);
    wait(30, msec);
  }
  Roller1.setBrake(coast);
  Roller2.setBrake(coast);
  setM(Tray, 0);
  drivePower(5);
  roller(60);
  wait(1500, msec);
  roller(80);
  driveForward(-16, 3000, 40);
  //tray reset
  while (Tray.position(rev) > 0) {
    setM(Tray, -100);
    wait(0, msec);
  }
  setM(Tray, 0);
  driveForward(-12, 1000, 60);
  turnC(1.79, 2000, 60);
  roller(-100);
  driveForward(22, 2000, 30);
  drivePower(-30);
  wait(200, msec);
  drivePower(0);
  roller(30);
  wait(500, msec);
  roller(0);
  //lift up
  while (Lift.position(rev) < 0.65) {
    setM(Lift, 100);
    wait(30, msec);
  }
  setM(Lift, 0);
  driveForward(3, 500, 30);
  roller(30);
  wait(1000, msec);
  driveForward(-22, 1500, 60);
  //lift down
  while (Lift.position(rev) > .1) {
    setM(Lift, -100);
    wait(30, msec);
  }
}