void log(const char *message) {
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print(message);
}
void moveFront() {
  // 7 seconds
  while (!Front.pressing()) {
    setMR(Right1, mogoOut);
    setMR(Right2, -mogoOut);
    setMR(Left1, mogoOut);
    setMR(Left2, -mogoOut);
    wait(30, msec);
  }
  wait(100, msec);
  setM(Right1, 0);
  setM(Right2, 0);
  setM(Left1, 0);
  setM(Left2, -0);
}

void moveBack() {
  // 2.5 seconds time limit
  while (!Back.pressing()) {
    setMR(Right1, -mogoIn);
    setMR(Right2, mogoIn);
    setMR(Left1, -mogoIn);
    setMR(Left2, mogoIn);
    wait(30, msec);
  }
  setM(Right1, 0);
  setM(Right2, 0);
  setM(Left1, 0);
  setM(Left2, -0);
}
void roller(int power) {
  setM(Roller1, -power);
  setM(Roller2, -power);
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