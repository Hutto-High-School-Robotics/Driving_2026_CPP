#include "robot_config.h"

vex::controller Controller = vex::controller();
vex::brain Brain = vex::brain();
vex::aivision AiVision = vex::aivision(PORT19, aivision::ALL_TAGS);
vex::motor55 leftDrive = vex::motor55(PORT10,true);
vex::motor55 rightDrive = vex::motor55(PORT9,false);
vex::inertial inertialSensor = vex::inertial(PORT5);
vex::motor55 arm = vex::motor55(PORT8);
vex::servo claw = vex::servo(Brain.ThreeWirePort.A);