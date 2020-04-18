#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Left1 = motor(PORT11, ratio18_1, false);
motor Left2 = motor(PORT20, ratio18_1, false);
motor Right1 = motor(PORT1, ratio18_1, true);
motor Right2 = motor(PORT10, ratio18_1, true);
motor Roller1 = motor(PORT9, ratio18_1, false);
motor Roller2 = motor(PORT19, ratio18_1, true);
motor Lift = motor(PORT8, ratio18_1, false);
limit Deploy = limit(Brain.ThreeWirePort.D);
bumper Button = bumper(Brain.ThreeWirePort.B);
limit Back = limit(Brain.ThreeWirePort.C);
limit Front = limit(Brain.ThreeWirePort.E);
motor Lift2 = motor(PORT18, ratio18_1, true);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}