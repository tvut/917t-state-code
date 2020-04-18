#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// Left1                motor         3
// Left2                motor         2
// Right1               motor         20
// Right2               motor         12
// Roller1              motor         19
// Roller2              motor         16
// Lift                 motor         1
// Tray                 motor         11
// AutoBump             bumper        H
// TrayLine             line          A
// RollerLine           line          G
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <math.h>

float pi = 3.1415926;
// 22.3
float diameter = 14.3;
float radius = diameter / 2;
int cubeTune = 68;
int towerOuttakeSpeed = 40;
float avgLeft;
float avgRight;
float theta;
#define setM(a, b) a.spin(fwd, b, pct);
#define setMR(a, b) a.spin(fwd, b, rpm);
using namespace vex;
competition Competition;

#include "newpid.h"

int autonomousSelection = 0;

#include <actions.h>
#include <autos.h>

// sets up autonomous, used for auto selector
void pre_auton(void) {
  vexcodeInit();
  bool buttonPress = false;
  Brain.Screen.clearScreen();
  while (true) {

    // button increases variable
    if (AutoBump.pressing() && !buttonPress) {
      autonomousSelection++;
      buttonPress = true;
    }
    if (!AutoBump.pressing())
      buttonPress = false;
    if (autonomousSelection == 11)
      autonomousSelection = 0;

    // changing screen colors
    if (autonomousSelection < 4) {
      Brain.Screen.setFillColor(color::red);
    } else if (autonomousSelection < 8) {
      Brain.Screen.setFillColor(color::blue);
    } else if (autonomousSelection < 10) {
      Brain.Screen.setFillColor(color::orange);
    } else {
      Brain.Screen.setFillColor(color::black);
    }

    // printing to screen
    Brain.Screen.drawRectangle(0, 0, 600, 300);
    Brain.Screen.setCursor(292, 80);
    Brain.Screen.print(autonomousSelection);
    Brain.Screen.setCursor(5, 20);
    Brain.Screen.print(autos[autonomousSelection]);
    Brain.Screen.newLine();
    wait(40, msec);
  }
}

void autonomous(void) {
  // setup motors
  Lift.resetRotation();
  Tray.resetRotation();

  Roller1.setBrake(brake);
  Roller2.setBrake(brake);
  Lift.setBrake(hold);
  Tray.setBrake(hold);

  // call correct auto
  log(autos[autonomousSelection]);
  if (autonomousSelection == 0)
    redFrontFour();
  if (autonomousSelection == 1)
    sixRedPreload();
  if (autonomousSelection == 2)
    sevenRedPreload();
  if (autonomousSelection == 3)
    redFivePreload();
  if (autonomousSelection == 4)
    blueFrontFour();
  if (autonomousSelection == 5)
    sixBluePreload();
  if (autonomousSelection == 6)
    sevenBluePreload();
  if (autonomousSelection == 7)
    blueFivePreload();
  if (autonomousSelection == 8)
    onePoint();
  if (autonomousSelection == 9)
    prog();
}

// slew functions and variables used for threading
int slew = 40;
int L1 = 0;
int L2 = 0;
int R1 = 0;
int R2 = 0;

// left front motor thread
void LF() {
  int newTarget = 0;
  while (true) {
    if (newTarget != L1) {
      if (abs(newTarget - L1) > slew) {
        if (newTarget < L1)
          newTarget = newTarget + slew;
        else
          newTarget = newTarget - slew;
      } else
        newTarget = L1;
    }
    setM(Left1, newTarget);
    wait(40, msec);
  }
}

// left back motor thread
void LB() {
  int newTarget = 0;
  while (true) {
    if (newTarget != L2) {
      if (abs(newTarget - L2) > slew) {
        if (newTarget < L2)
          newTarget = newTarget + slew;
        else
          newTarget = newTarget - slew;
      } else
        newTarget = L2;
    }
    setM(Left2, newTarget);
    wait(40, msec);
  }
}

// right front motor thread
void RF() {
  int newTarget = 0;
  while (true) {
    if (newTarget != R1) {
      if (abs(newTarget - R1) > slew) {
        if (newTarget < R1)
          newTarget = newTarget + slew;
        else
          newTarget = newTarget - slew;
      } else
        newTarget = R1;
    }
    setM(Right1, newTarget);
    wait(40, msec);
  }
}

// right back motor thread
void RB() {
  int newTarget = 0;
  while (true) {
    if (newTarget != R2) {
      if (abs(newTarget - R2) > slew) {
        if (newTarget < R2)
          newTarget = newTarget + slew;
        else
          newTarget = newTarget - slew;
      } else
        newTarget = R2;
    }
    setM(Right2, newTarget);
    wait(40, msec);
  }
}

void usercontrol(void) {
  Brain.Screen.clearScreen();
  // start threads
  
  vex::thread LFthread = vex::thread(LF);
  vex::thread LBthread = vex::thread(LB);
  vex::thread RFthread = vex::thread(RF);
  vex::thread RBthread = vex::thread(RB);

  Roller1.setBrake(brake);
  Roller2.setBrake(brake);
  Lift.setBrake(hold);
  Tray.setBrake(hold);

  // blueFrontFour();

  // button and macro varaibles
  bool autosEnabled = true;
  bool autoToggle = false;
  bool lowToggle = false;
  bool moveLow = false;
  bool highToggle = false;
  bool moveHigh = false;
  bool resetToggle = false;
  bool liftDown = false;
  bool lowDownToggle = false;
  bool lowDown = false;
  bool cubeAligned = false;
  bool trytoAlign = false;
  int time = 0;
  while (1) {
    // Manual Override key combo
    if (Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() &&
        Controller1.ButtonL1.pressing() && Controller1.ButtonL2.pressing()) {
      Tray.resetRotation();
      Lift.resetRotation();
    }
    // Auto Drive Code
    if (autosEnabled) {
      // drive code
      int L = Controller1.Axis3.value();
      int R = Controller1.Axis2.value();
      if (abs(L) < 5)
        L = 0;
      if (abs(R) < 5)
        R = 0;
      // decreases difference between joysticks
      int diff = (L - R) / 3;
      // temp override code
      if (Right2.temperature() > 65 || Left2.temperature() > 65) {
        diff = 0;
      } else if (diff > 30)
        diff = 30;
      else if (diff < -30)
        diff = -30;
      if (R > 120) {
        R1 = 100;
        R2 = 100;
      } else if (R < -120) {
        R1 = -100;
        R2 = -100;
      } else {
        R1 = .6 * (R + diff);
        R2 = .6 * (R + diff);
      }

      if (L > 120) {
        L1 = 100;
        L2 = 100;
      } else if (L < -120) {
        L1 = -100;
        L2 = -100;
      } else {
        L1 = .6 * (L - diff);
        L2 = .6 * (L - diff);
      }

      // Lift Preset toggle buttons
      if (Lift.rotation(rev) < .3) { // lift down macros
        resetToggle = false;
        lowDownToggle = false;

        // low tower
        if (Controller1.ButtonRight.pressing()) {
          if (lowToggle == false) {
            moveLow = !moveLow;
            cubeAligned = false;
            moveHigh = false;
            trytoAlign = false;
            lowDown = false;
          }
          lowToggle = true;
        } else
          lowToggle = false;

        // high tower
        if (Controller1.ButtonY.pressing()) {
          if (highToggle == false) {
            moveHigh = !moveHigh;
            cubeAligned = false;
            moveLow = false;
            lowDown = false;
            trytoAlign = false;
          }
          highToggle = true;
        } else
          highToggle = false;
      } else { // lift up macros

        // low tower down and outtake
        if (Controller1.ButtonY.pressing()) {
          if (resetToggle == false) {
            liftDown = !liftDown;
            moveLow = false;
            lowDown = false;
            moveHigh = false;
            trytoAlign = false;
          }
          resetToggle = true;
        } else
          resetToggle = false;

        // high tower down
        if (Controller1.ButtonRight.pressing()) {
          if (lowDownToggle == false) {
            lowDown = !lowDown;
            moveLow = false;
            liftDown = false;
            moveHigh = false;
            trytoAlign = false;
          }
          lowDownToggle = true;
        } else
          lowDownToggle = false;
      }

      // override macros with user control
      if (Controller1.ButtonDown.pressing() || Controller1.ButtonB.pressing() ||
          Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing()) {
        moveHigh = false;
        moveLow = false;
        liftDown = false;
        lowDown = false;
      }

      // activating macros

      // low tower
      if (moveLow) {

        // outtake cube
        if (!cubeAligned) {
          roller(towerOuttakeSpeed);
          if (RollerLine.value(pct) < cubeTune) {
            cubeAligned = true;
            roller(-100);
            wait(120, msec);
            roller(0);
          }
        } else {
          // set lift
          if (Lift.position(rev) < 0.65) {
            setM(Lift, 100);
          } else if (Lift.position(rev) > 0.7) {
            setM(Lift, -50);
          } else
            moveLow = false;
        }
      }

      // high tower
      if (moveHigh) {

        // outtake cube
        if (!cubeAligned) {
          roller(towerOuttakeSpeed);
          if (RollerLine.value(pct) < cubeTune) {
            cubeAligned = true;
            roller(-100);
            wait(120, msec);
            roller(0);
          }
        } else {
          // set cube
          if (Lift.position(rev) < 0.95) {
            setM(Lift, 100);
          } else
            moveHigh = false;
        }
      }

      // reset lift down
      if (liftDown) {
        if (Lift.position(rev) > -.3) {
          setM(Lift, -100);
        } else
          liftDown = false;
      }

      // reset lift and outtake
      if (lowDown) {
        roller(50);
        if (Lift.position(rev) > 0) {
          setM(Lift, -100);
        } else
          lowDown = false;
      }

      // Lift manual control
      if (Controller1.ButtonB.pressing()) {
        setM(Lift, 100);
      } else if (Controller1.ButtonDown.pressing()) {
        setM(Lift, -100);
      } else if (!moveLow && !moveHigh && !liftDown && !lowDown) {
        setM(Lift, 0);
      }

      // Tray control
      if (Controller1.ButtonR1.pressing() && (Tray.position(rev) < .40)) {
        setM(Tray, 100);
        // slows down if far enough out
      } else if (Controller1.ButtonR1.pressing()) {
        setMR(Tray, 35);
      } else if (Controller1.ButtonR2.pressing()) {
        setM(Tray, -100);
      } else {
        setM(Tray, 0);
      }

      // change tray brake mode if far enough out
      if (Tray.position(rev) < .3)
        Tray.setBrake(hold);
      else
        Tray.setBrake(coast);
      // Roller manual control

      // lift is down
      if (Lift.position(rev) < .25) {
        // slow when tray is out
        if (Controller1.ButtonL1.pressing() && Tray.position(rev) > .3) {
          roller(50);
        } else if (Controller1.ButtonL1.pressing()) {
          roller(100);
        } else if (Controller1.ButtonL2.pressing()) {
          roller(-100);
          // don't do anything if macros running
        } else if (!trytoAlign && !((moveLow || moveHigh || lowDown) &&
                                    TrayLine.value(pct) > cubeTune)) {
          roller(0);
        }
        // lift is raised
      } else {
        if (Controller1.ButtonL1.pressing() &&
            Controller1.ButtonL2.pressing()) {
          roller(100);
        } else if (Controller1.ButtonL2.pressing()) {
          roller(-100);
        } else if (Controller1.ButtonL1.pressing()) {
          // rollers go out slower
          roller(50);
        } else if (!lowDown) {
          roller(0);
        }
      }

      // outtake cubes to line sensor with A button
      if (Controller1.ButtonA.pressing()) {
        trytoAlign = true;
      }
      if (Controller1.ButtonL1.pressing() || Controller1.ButtonL2.pressing()) {
        trytoAlign = false;
      }
      if (trytoAlign) {
        roller(20);
        wait(20, msec);
        if (TrayLine.value(pct) < cubeTune) {
          wait(120, msec);
          roller(0);
          trytoAlign = false;
        }
      }
      // Deploy button
      if (Controller1.ButtonX.pressing()) {
        deploy();
      }
    } else {
      // Manual Code
      basic();
    }
    task::sleep(40);
    // Print temps on brain
    if (time == 600) {
      time = 0;
      Brain.Screen.setCursor(1, 1);
      Brain.Screen.print("Left 1: ");
      Brain.Screen.print(Left1.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Left 2: ");
      Brain.Screen.print(Left2.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Right 1: ");
      Brain.Screen.print(Right1.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Right 2: ");
      Brain.Screen.print(Right2.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Lift: ");
      Brain.Screen.print(Lift.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Tray: ");
      Brain.Screen.print(Tray.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Roller 1: ");
      Brain.Screen.print(Roller1.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Roller 2: ");
      Brain.Screen.print(Roller2.temperature());
      Brain.Screen.newLine();
      Brain.Screen.print("Lift: ");
      Brain.Screen.print(Lift.rotation(rev));
      Brain.Screen.newLine();
      Brain.Screen.print("Tray: ");
      Brain.Screen.print(Tray.rotation(rev));
      Brain.Screen.newLine();
      Brain.Screen.print("Tray Line: ");
      Brain.Screen.print(TrayLine.value(pct));
      Brain.Screen.newLine();
      Brain.Screen.print("Roller Line: ");
      Brain.Screen.print(RollerLine.value(pct));
    }
    time += 40;
  }
}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}