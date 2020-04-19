#include "vex.h"
#include <math.h>
float pi = 3.1415926;
float radius = 5.78125;
float diameter = 11.5625; 
float avgLeft; 
float avgRight; 
float theta; 
#define setM(a,b) a.spin(directionType::fwd,b,velocityUnits::pct);

using namespace vex;

vex::brain Brain;
vex::competition Competition;
vex::controller Controller;

// vex::bumper Bumper = vex::bumper(Brain.ThreeWirePort.H);
vex::motor Left1 (vex::PORT11, vex::gearSetting::ratio18_1, false);
vex::motor Left2 (vex::PORT20, vex::gearSetting::ratio18_1, false);
vex::motor Right1 (vex::PORT1, vex::gearSetting::ratio18_1, true);
vex::motor Right2 (vex::PORT10, vex::gearSetting::ratio18_1, true);

vex::motor Roller1 (vex::PORT9, vex::gearSetting::ratio18_1, false);
vex::motor Roller2 (vex::PORT19, vex::gearSetting::ratio18_1, true);
vex::motor Lift (vex::PORT8, vex::gearSetting::ratio18_1, false);
// vex::motor DRFB2 (vex::PORT9, vex::gearSetting::ratio18_1, false);
// vex::motor claw (vex::PORT8, vex::gearSetting::ratio18_1, false);

#include "pid.h"
#include "autoselect.h"


void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

bool rollerOut=false;
void resetRoller(){
  Roller1.rotateTo(-550, rotationUnits::deg);
      Roller2.rotateTo(-550, rotationUnits::deg);
      rollerOut=true;
}

void autonomous( void ) {
  if(autonomousSelection==0);
  if(autonomousSelection==1);
  if(autonomousSelection==2);
  if(autonomousSelection==3);
  if(autonomousSelection==4);
  if(autonomousSelection==5);
  if(autonomousSelection==6);
  if(autonomousSelection==7);
}

void usercontrol( void ) {
  Roller1.setBrake(brakeType::brake);
  Roller2.setBrake(brakeType::brake);
  Roller1.resetRotation();
  Roller2.resetRotation();
  int threshold = 10;
  int mogo = 30;
  while (1) {
    // if(Bumper.pressing()){
    //   DRFB1.resetRotation();
    // }
    //Tank
    if((abs(Controller.Axis3.value())>threshold)&&(abs(Controller.Axis2.value())>threshold)){
      setM(Left1,Controller.Axis3.value());
      setM(Left2,Controller.Axis3.value());
      setM(Right1,Controller.Axis2.value());
      setM(Right2,Controller.Axis2.value());
    } else if(abs(Controller.Axis3.value())>threshold){
      setM(Left1,Controller.Axis3.value());
      setM(Left2,Controller.Axis3.value());
    } else if(abs(Controller.Axis2.value())>threshold){
      setM(Right1,Controller.Axis2.value());
      setM(Right2,Controller.Axis2.value());
    } else if(Controller.ButtonR1.pressing()){
      // if(!rollerOut)resetRoller();
      Right1.spin(directionType::fwd,mogo,velocityUnits::pct);
      Right2.spin(directionType::fwd,-mogo,velocityUnits::pct);
      Left1.spin(directionType::fwd,mogo,velocityUnits::pct);
      Left2.spin(directionType::fwd,-mogo,velocityUnits::pct);
    } else if(Controller.ButtonR2.pressing()){
      Right1.spin(directionType::fwd,-mogo,velocityUnits::pct);
      Right2.spin(directionType::fwd,mogo,velocityUnits::pct);
      Left1.spin(directionType::fwd,-mogo,velocityUnits::pct);
      Left2.spin(directionType::fwd,mogo,velocityUnits::pct);
    } else{
      setM(Right1,0);
      setM(Right2,0);
      setM(Left1,0);
      setM(Left2,0);
    }
    //Lift
      if(Controller.ButtonUp.pressing()){
        setM(Lift, 100);
      } else if(Controller.ButtonDown.pressing()){
        setM(Lift, -100);
      } else{
        setM(Lift, 0);
      }
    //Roller
    if(Controller.ButtonL1.pressing()){
      rollerOut=false;
      setM(Roller1, 100);
      setM(Roller2, 100);
    } else if(Controller.ButtonL2.pressing()){
      rollerOut=false;
      setM(Roller1, -100);
      setM(Roller2, -100);
    } else{
      setM(Roller1, 0);
      setM(Roller2, 0);
    }
    vex::task::sleep(20);
  }
}

int main() {
    Brain.Screen.pressed( userTouchCallbackPressed );
    Brain.Screen.released( userTouchCallbackReleased );
    // background
    Brain.Screen.setFillColor( vex::color(0x400000) );
    Brain.Screen.setPenColor( vex::color(0x400000) );
    Brain.Screen.drawRectangle( 0, 0, 480, 120 );
    Brain.Screen.setFillColor( vex::color(0x000040) );
    Brain.Screen.setPenColor( vex::color(0x000040) );
    Brain.Screen.drawRectangle( 0, 120, 480, 120 );
    // initial display
    displayButtonControls( 0, false );

    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
                       
    while(1) {
      vex::task::sleep(100);
    }    
       
}