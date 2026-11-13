#pragma once
#include "robot_config.h"
#include "tools.h"

namespace drive
{
    namespace
    {
        bool isPaused;
        bool isDown;
    }
    void driveLoop();
    void pauseDrive();
    void unpauseDrive();
    void beginManualDrive(int32_t speed);
    void stopManualDrive();
    void turn(double degrees, double speed = 50, vex::turnType dir = right);
    void turn(vex::turnType dir, double time, timeUnits unit);
    void servoLoop();
};
