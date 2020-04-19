#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller;
bumper Ramp = vex::bumper(Brain.ThreeWirePort.D);
motor Left1(vex::PORT11, vex::gearSetting::ratio18_1, false);
motor Left2(vex::PORT20, vex::gearSetting::ratio18_1, false);
motor Right1(vex::PORT1, vex::gearSetting::ratio18_1, true);
motor Right2(vex::PORT10, vex::gearSetting::ratio18_1, true);

motor Roller1(vex::PORT9, vex::gearSetting::ratio18_1, false);
motor Roller2(vex::PORT19, vex::gearSetting::ratio18_1, true);
motor Lift(vex::PORT8, vex::gearSetting::ratio18_1, false); = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}