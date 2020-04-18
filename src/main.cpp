#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// Left1                motor         11
// Left2                motor         20
// Right1               motor         1
// Right2               motor         10
// Roller1              motor         9
// Roller2              motor         19
// Lift                 motor         8
// Deploy               limit         D
// Button               bumper        B
// Back                 limit         C
// Front                limit         E
// Lift2                motor         18
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

int slewRate = 30;
int driveSpeed = 0;

double turnMult = .30;

int forThresh = 10;
int turnThresh = 5;
int mogoIn = 70;
int mogoOut = 22;

int autonomousSelection = 0;

#include <actions.h>
#include <autos.h>

void pre_auton(void) {
  vexcodeInit();
  bool buttonPress = false;
  Brain.Screen.clearScreen();
  while (true) {
    if (Button.pressing() && !buttonPress) {
      autonomousSelection++;
      buttonPress = true;
    }
    if (!Button.pressing())
      buttonPress = false;
    if (autonomousSelection == 11)
      autonomousSelection = 0;
    Brain.Screen.setFillColor(color::blue);
    if (autonomousSelection > 3)
      Brain.Screen.setFillColor(color::red);
    if (autonomousSelection > 7)
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

int stickSlew() {
  bool slewOn = false;
  while (true) {
    int con = Controller1.Axis3.value();
    if (abs(con) < forThresh)
      con = 0;
    if (slewOn || abs(driveSpeed - con) > 120) {
      slewOn = true;
      if (abs(driveSpeed - con) < 40) {
        slewOn = false;
        driveSpeed = con;
      } else if (con - driveSpeed > slewRate)
        driveSpeed += slewRate;
      else if (con - driveSpeed < -slewRate)
        driveSpeed -= slewRate;
      else
        driveSpeed = con;
      slewOn = false;
    } else {
      driveSpeed = con;
    }
    wait(20, msec);
  }
}

void autonomous(void) {
  // redFive();
  log(autos[autonomousSelection]);
  if (autonomousSelection == 0){
    blueEight();
  }
  if (autonomousSelection == 1){
    blueFive();
  }
  if (autonomousSelection == 2){
    blueTower();
  }
  if (autonomousSelection == 3){
    onePoint();
  }
  if (autonomousSelection == 4){
    redEight();
  }
  if (autonomousSelection == 5){
    redFive();
  }
  if (autonomousSelection == 6){
    redTower();
  }
  if (autonomousSelection == 7){
    onePoint();
  }
  if (autonomousSelection == 8){
      deploy();
  }
  if(autonomousSelection==9){
    prog();
  }
}

void usercontrol(void) {
  
  task slewTask = task(stickSlew);

  Lift.resetRotation();
  Lift2.resetRotation();
  Roller1.setBrake(brake);
  Roller2.setBrake(brake);
  Roller1.resetRotation();
  Roller2.resetRotation();

  while (1) {
    // Arcade
    if (abs(driveSpeed) > 0 && (abs(Controller1.Axis1.value()) > turnThresh)) {
      setM(Left1, driveSpeed + Controller1.Axis1.value() * turnMult);
      setM(Left2, driveSpeed + Controller1.Axis1.value() * turnMult);
      setM(Right1, driveSpeed - Controller1.Axis1.value() * turnMult);
      setM(Right2, driveSpeed - Controller1.Axis1.value() * turnMult);
    } else if (abs(driveSpeed) > 0) {
      setM(Left1, driveSpeed);
      setM(Left2, driveSpeed);
      setM(Right1, driveSpeed);
      setM(Right2, driveSpeed);
    } else if (abs(Controller1.Axis1.value()) > turnThresh) {
      setM(Left1, Controller1.Axis1.value() * turnMult);
      setM(Left2, Controller1.Axis1.value() * turnMult);
      setM(Right1, -Controller1.Axis1.value() * turnMult);
      setM(Right2, -Controller1.Axis1.value() * turnMult);
    } else if (Controller1.ButtonR1.pressing()) {
      setMR(Right1, mogoOut);
      setMR(Right2, -mogoOut);
      setMR(Left1, mogoOut);
      setMR(Left2, -mogoOut);
    } else if (Controller1.ButtonR2.pressing()) {
      setMR(Right1, -mogoIn);
      setMR(Right2, mogoIn);
      setMR(Left1, -mogoIn);
      setMR(Left2, mogoIn);
    } else {
      setM(Right1, 0);
      setM(Right2, 0);
      setM(Left1, 0);
      setM(Left2, 0);
    }
    // Lift
    if (Controller1.ButtonUp.pressing()) {
      setM(Lift, 100);
      setM(Lift2, 100);
    } else if (Controller1.ButtonDown.pressing()) {
      setM(Lift, -100);
      setM(Lift2, -100);
    } else {
      setM(Lift, 0);
      setM(Lift2, 0);
    }
    // Deploy{
    if (Controller1.ButtonX.pressing()) {
      deploy();
    }
    // if (Controller1.ButtonA.pressing()) {
    //   moveBack();
    // }
    // if (Controller1.ButtonY.pressing()) {
    //   moveFront();
    // }
    // Lift Preset
    while (Controller1.ButtonLeft.pressing() && Lift.rotation(rev) < 2.4) {
      int rampOut = 30;
      setMR(Right1, rampOut);
      setMR(Right2, -rampOut);
      setMR(Left1, rampOut);
      setMR(Left2, -rampOut) setM(Lift, 100);
      setM(Lift2, 100);
    }
    while (Controller1.ButtonRight.pressing() && Lift.rotation(rev) < 3.4) {
      int rampOut = 30;
      setMR(Right1, rampOut);
      setMR(Right2, -rampOut);
      setMR(Left1, rampOut);
      setMR(Left2, -rampOut) setM(Lift, 100);
      setM(Lift2, 100);
    }
    // Roller
    if (Controller1.ButtonB.pressing()) {
      setMR(Roller1, 20);
      setMR(Roller2, 20);
    } else if (Controller1.ButtonL2.pressing()) {
      setM(Roller1, 100);
      setM(Roller2, 100);
    } else if (Controller1.ButtonL1.pressing()) {
      setM(Roller1, -100);
      setM(Roller2, -100);
    } else {
      setM(Roller1, 0);
      setM(Roller2, 0);
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
