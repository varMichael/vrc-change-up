/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    5, 10, 9        
// lowercenterintake    motor         16              
// upperflywheel        motor         17              
// intakept1            motor         20              
// intakept2            motor         14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftDriveSmart = motor(PORT6, ratio18_1, false);
motor LeftDriveSmart2= motor(PORT5, ratio18_1, false);
motor_group leftDrive= motor_group(LeftDriveSmart,LeftDriveSmart2);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);
motor RightDriveSmart2 = motor(PORT1, ratio18_1, true);
motor_group rightDrive= motor_group(RightDriveSmart2, RightDriveSmart); 
inertial TurnGyroSmart = inertial(PORT9);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart, 319.19, 320, 40, mm, 1.5);
motor lowercenterintake = motor(PORT16, ratio18_1, false);
motor upperflywheel = motor(PORT17, ratio6_1, false);
motor intakept1 = motor(PORT20, ratio18_1, false);
motor intakept2 = motor(PORT14, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);
  TurnGyroSmart.calibrate();
  Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  while (TurnGyroSmart.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}

using namespace vex;


void score(void) {
  upperflywheel.setVelocity(100, pct);
  lowercenterintake.setVelocity(100, pct);
  leftDrive.setVelocity(50, pct);
  rightDrive.setVelocity(50, pct);
  intakept1.setVelocity(100, pct);  
  intakept2.setVelocity(100, pct);
  
  // First Goal, Prep for 2nd Goal
  leftDrive.rotateFor(forward, 0.25, rev, false);
  rightDrive.rotateFor(forward, 0.25, rev, true);
  intakept1.rotateFor(forward, 10, rev, false);
  intakept2.rotateFor(forward, 10, rev, true);
  lowercenterintake.rotateFor(reverse, 3, rev, false);
  leftDrive.rotateFor(forward, 0.5, rev, false);
  rightDrive.rotateFor(forward, 0.5, rev, true);
  intakept1.rotateFor(forward, 10, rev, false);
  intakept2.rotateFor(forward, 10, rev, false); 
  upperflywheel.rotateFor(reverse, 12, rev, false);
  lowercenterintake.rotateFor(reverse, 5, rev, true);
  leftDrive.rotateFor(reverse, 0.25, rev, false);
  rightDrive.rotateFor(reverse, 0.75, rev, true);
  leftDrive.rotateFor(reverse, 0.75, rev, false);
  rightDrive.rotateFor(reverse, 2, rev, true);

  // Second Goal
  leftDrive.rotateFor(forward, 2, rev, false);
  rightDrive.rotateFor(forward, 2, rev, true);
  lowercenterintake.rotateFor(forward, 2, rev, false);
  upperflywheel.rotateFor(forward, 10, rev, true);  
  rightDrive.rotateFor(forward, 1.25, rev, true);
  leftDrive.rotateFor(forward, 1.5, rev, true);
  lowercenterintake.rotateFor(forward, 5, rev, false);
  upperflywheel.rotateFor(forward, 15, rev, false);
} 







// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
// score();
score();

  
  
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the jo
    LeftDriveSmart.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(), percent);
    LeftDriveSmart2.spin(forward, Controller1.Axis3.position() + Controller1.Axis1.position(), percent);
    
    RightDriveSmart.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), percent);
    RightDriveSmart2.spin(forward, Controller1.Axis3.position() - Controller1.Axis1.position(), percent);





    if (Controller1.ButtonR1.pressing()) {
      intakept1.spin(forward, 600, pct);
      intakept2.spin(forward, 600, pct);
      lowercenterintake.spin(reverse, 600, pct);
    }

    else if (Controller1.ButtonR2.pressing()) {
      intakept1.spin(reverse, 300, pct);
      intakept2.spin(reverse, 300, pct);
      lowercenterintake.spin(forward, 300, pct);
    }

    else {
      intakept1.stop(brake);
      intakept2.stop(brake);
      lowercenterintake.stop(brake);
    }





    /* if (Controller1.ButtonL1.pressing()) {
      lowercenterintake.spin(forward, 200, pct);
    }
    else if (Controller1.ButtonL2.pressing()) {
      lowercenterintake.spin(reverse, 200, pct);
    }

    else {
      lowercenterintake.stop(brake);
      lowercenterintake.stop(brake);
    } */





    if (Controller1.ButtonL1.pressing()) {
      upperflywheel.spin(reverse, 600, pct);
    }
    else if (Controller1.ButtonL2.pressing()) {
      upperflywheel.spin(forward, 600, pct);
    }

    else {
      upperflywheel.stop(brake);
      upperflywheel.stop(brake);
    }
    //........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
