using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Left1;
extern motor Left2;
extern motor Right1;
extern motor Right2;
extern motor Roller1;
extern motor Roller2;
extern motor Lift;
extern limit Deploy;
extern bumper Button;
extern limit Back;
extern limit Front;
extern motor Lift2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );