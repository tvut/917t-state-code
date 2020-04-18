void log(const char *message) {
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(message);
}
void arcade(int threshold) {
  double turnMult = 0.3;
  if (abs(Controller1.Axis3.value()) > threshold &&
      (abs(Controller1.Axis1.value()) > threshold)) {
    setM(Left1,
         Controller1.Axis3.value() + Controller1.Axis1.value() * turnMult);
    setM(Left2,
         Controller1.Axis3.value() + Controller1.Axis1.value() * turnMult);
    setM(Right1,
         Controller1.Axis3.value() - Controller1.Axis1.value() * turnMult);
    setM(Right2,
         Controller1.Axis3.value() - Controller1.Axis1.value() * turnMult);
  } else if (abs(Controller1.Axis3.value()) > 0) {
    setM(Left1, Controller1.Axis3.value());
    setM(Left2, Controller1.Axis3.value());
    setM(Right1, Controller1.Axis3.value());
    setM(Right2, Controller1.Axis3.value());
  } else if (abs(Controller1.Axis1.value()) > threshold) {
    setM(Left1, Controller1.Axis1.value() * turnMult);
    setM(Left2, Controller1.Axis1.value() * turnMult);
    setM(Right1, -Controller1.Axis1.value() * turnMult);
    setM(Right2, -Controller1.Axis1.value() * turnMult);
  } else {
    setM(Left1, 0);
    setM(Left2, 0);
    setM(Right1, 0);
    setM(Right2, 0);
  }
}
void tank(int threshold) {
  if (abs(Controller1.Axis3.value()) > threshold) {
    setM(Left1, Controller1.Axis3.value());
    setM(Left2, Controller1.Axis3.value());
  } else {
    setM(Left1, 0);
    setM(Left2, 0);
  }
  if (abs(Controller1.Axis2.value()) > threshold) {
    setM(Right1, Controller1.Axis2.value());
    setM(Right2, Controller1.Axis2.value());
  } else {
    setM(Right1, 0);
    setM(Right2, 0);
  }
}
void roller(int power) {
  setM(Roller1, power);
  setM(Roller2, power);
}
void turn(double deg) {
  double turn = (double)deg / 360 * pi * diameter / 4;
  Left1.rotateFor(forward, turn, rev, false);
  Left2.rotateFor(forward, turn, rev, false);
  Right1.rotateFor(reverse, turn, rev, false);
  Right2.rotateFor(reverse, turn, rev, true);
}
void drive(int inch) {
  double turn = (double)inch / 360 * pi * diameter / 4;
  Left1.rotateFor(forward, turn, rev, false);
  Left2.rotateFor(forward, turn, rev, false);
  Right1.rotateFor(forward, turn, rev, false);
  Right2.rotateFor(forward, turn, rev, true);
}
void drivePower(int power) {
  setM(Left1, power);
  setM(Left2, power);
  setM(Right1, power);
  setM(Right2, power);
}
void moveFront() {
  roller(0);
  Tray.rotateTo(3.2, rev);
}

void moveBack() { Tray.rotateTo(0, rev); }

void basic() {
  tank(3);
  // Lift
  if (Controller1.ButtonUp.pressing()) {
    setM(Lift, 100);
  } else if (Controller1.ButtonDown.pressing()) {
    setM(Lift, -100);
  } else {
    setM(Lift, 0);
  }
  // Tray
  if (Controller1.ButtonR1.pressing()) {
    setM(Tray, 100);
  } else if (Controller1.ButtonR2.pressing()) {
    setM(Tray, -100);
  } else {
    setM(Tray, 0);
  }
  // Roller
  if (Controller1.ButtonL1.pressing()) {
    setM(Roller1, 100);
    setM(Roller2, 100);
  } else if (Controller1.ButtonA.pressing()) {
    setM(Roller1, -20);
    setM(Roller2, -20);
  } else if (Controller1.ButtonL2.pressing()) {
    setM(Roller1, -100);
    setM(Roller2, -100);
  } else {
    roller(0);
  }
}