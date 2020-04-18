#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Left1                motor         11              
// Left2                motor         1               
// Right1               motor         12              
// Right2               motor         2               
// Roller1              motor         9               
// Roller2              motor         4               
// Lift                 motor         10              
// Tray                 motor         3               
// AutoBump             bumper        H               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <math.h>

float pi = 3.1415926;
float radius = 10.5;
// 22.3
float diameter = 21;
float avgLeft;
float avgRight;
float theta;
#define setM(a, b) a.spin(fwd, b, pct);
#define setMR(a, b) a.spin(fwd, b, rpm);
using namespace vex;
competition Competition;

#include "pid.h"

int autonomousSelection = 0;

#include <actions.h>
#include <autos.h>

void pre_auton(void) {
  vexcodeInit();
  bool buttonPress = false;
  Brain.Screen.clearScreen();
  while (true) {
    if (AutoBump.pressing() && !buttonPress) {
      autonomousSelection++;
      buttonPress = true;
    }
    if (!AutoBump.pressing())
      buttonPress = false;
    if (autonomousSelection == 12)
      autonomousSelection = 0;
    if (autonomousSelection < 4)
    Brain.Screen.setFillColor(color::blue);
    else if (autonomousSelection < 8)
      Brain.Screen.setFillColor(color::red);
    else if (autonomousSelection == 8)
      Brain.Screen.setFillColor(color::purple);
    else if (autonomousSelection == 9)
      Brain.Screen.setFillColor(color::orange);
    else
      Brain.Screen.setFillColor(color::black);
    Brain.Screen.drawRectangle(0, 0, 600, 300);
    Brain.Screen.setCursor(292, 80);
    Brain.Screen.print(autonomousSelection);
    Brain.Screen.setCursor(10, 40);
    Brain.Screen.print(autos[autonomousSelection]);
    Brain.Screen.newLine();
    wait(40, msec);
  }
}

void autonomous(void) {
  log(autos[autonomousSelection]);
  if (autonomousSelection == 0) // blue
    blueFive();
  if (autonomousSelection == 1) // blue
    blueFrontFour();
  if (autonomousSelection == 2) // blue
    blueBackTower();
  if (autonomousSelection == 3) // blue
    blueMiddleTower();
  if (autonomousSelection == 4) // red
    redFive();
  if (autonomousSelection == 5) // red
    redFrontFour();
  if (autonomousSelection == 6) // red
    redBackTower();
  if (autonomousSelection == 7) // red
    redMiddleTower();
  if (autonomousSelection == 8)
    onePoint();
  if (autonomousSelection == 9)
    deploy();
  if (autonomousSelection == 10)
    prog();
}

void usercontrol(void) {
  // blueFive();
  // turnPID(.2, 2000);
  // driveForwardPID(40, 5000);

  Lift.resetRotation();
  Tray.resetRotation();

  Roller1.setBrake(brake);
  Roller2.setBrake(brake);

  bool autosEnabled = false;
  bool autoToggle = false;
  while (1) {
    //Manual Override
    // if (Controller1.ButtonR1.pressing() && Controller1.ButtonR2.pressing() &&
    //     Controller1.ButtonL1.pressing() && Controller1.ButtonL2.pressing()) {
    //   if (!autoToggle)
    //     autosEnabled = !autosEnabled;
    //   autoToggle = true;
    // } else
    //   autoToggle = false;
    //Auto Drive Code
    if (autosEnabled) {
      // arcade(10);
      tank(10);
      // Lift
      if (Controller1.ButtonUp.pressing()) {
        setM(Lift, 100);
      } else if (Controller1.ButtonDown.pressing()) {
        setM(Lift, -100);
      } else {
        setM(Lift, 0);
      }
      if (Controller1.ButtonR1.pressing() && (Tray.position(rev) < 1.9)) {
        setM(Tray, 100);
      } else if (Controller1.ButtonR1.pressing()) {
        setM(Tray, 50);
      } else if (Controller1.ButtonR2.pressing()) {
        setM(Tray, -100);
      } else if (Controller1.ButtonUp.pressing() && (Tray.position(rev) < .8)) {
        setM(Tray, 100);
      } else {
        setM(Tray, 0);
      }
      // Deploy
      if (Controller1.ButtonX.pressing()) {
        deploy();
      }
      // Lift Preset
      if (Controller1.ButtonLeft.pressing()) {
        Lift.setBrake(hold);
        if(Lift.position(rev)<0.9){
        setM(Lift, 100);
        if(Tray.position(rev) < 1.9)setM(Tray,100);
        }
      } else if (Controller1.ButtonRight.pressing()) {
        Lift.setBrake(hold);
        if(Lift.position(rev)<1.5){
        setM(Lift, 100);
        if(Tray.position(rev) < 1.7)setM(Tray,100);
        }
      } else{
        Lift.setBrake(coast);
      }
      // Roller
      if (Controller1.ButtonL1.pressing() && Lift.position(rev) > .3) {
        setM(Roller1, 30);
        setM(Roller2, 30);
      } else if (Controller1.ButtonL2.pressing() && Lift.position(rev) > .3) {
        setM(Roller1, -30);
        setM(Roller2, -30);
      } else if (Controller1.ButtonL1.pressing()) {
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
    } else {
      //Manual Code
      basic();
    }
    task::sleep(20);
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
