#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Left1 = motor(PORT3, ratio18_1, false);
motor Left2 = motor(PORT2, ratio18_1, false);
motor Right1 = motor(PORT20, ratio18_1, true);
motor Right2 = motor(PORT12, ratio18_1, true);
motor Roller1 = motor(PORT19, ratio18_1, true);
motor Roller2 = motor(PORT16, ratio18_1, false);
motor Lift = motor(PORT1, ratio36_1, false);
motor Tray = motor(PORT11, ratio36_1, false);
bumper AutoBump = bumper(Brain.ThreeWirePort.H);
line TrayLine = line(Brain.ThreeWirePort.A);
line RollerLine = line(Brain.ThreeWirePort.G);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}