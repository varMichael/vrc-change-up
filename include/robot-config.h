using namespace vex;

extern brain Brain;

// VEXcode devices

extern controller Controller1;
extern smartdrive Drivetrain;
extern motor lowercenterintake;
extern motor upperflywheel;
extern motor intakept1;
extern motor intakept2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );