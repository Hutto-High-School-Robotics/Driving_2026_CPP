#pragma once
#include "vex.h"

using namespace vex;

// get the global config
extern brain Brain;
extern controller Controller;
extern aivision aiVision;
extern motor55 leftDrive;
extern motor55 rightDrive;
extern motor55 arm;
extern servo claw;
extern servo holder;

/** Robot size, in inches. Assumes the robot is one big square. */
const double robotSize = 20;