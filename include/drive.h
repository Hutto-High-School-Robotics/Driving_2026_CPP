#pragma once
#include "robot_config.h"
#include "tools.h"

namespace drive
{
    namespace
    {
        bool isPaused;
        bool isClawDown;
        bool isClawClosed;
    }
    void stabilizeClaw();
    void driveLoop();
    void pauseDrive();
    void unpauseDrive();
    void beginManualDrive(double speed);
    void stopManualDrive();
    void turn(double degrees, double speed = 50, vex::turnType dir = right);
    void turn(vex::turnType dir, double time, timeUnits unit);

    // manual arm control
    void raiseArm();
    void lowerArm();
    void stopArm();

    // manual claw control
    void openClaw();

    void closeClaw();


    void openHolder();

    void closeHolder();


    void servoLoop();
    // driving

    /**
     * The drivetrain.
     */
    void train();

    /**
     * The robot arm control
     */
    void armRun();

    /**
     * The robot claw control.
     */
    void clawRun();

    /**
     * The holder servo
     */
    void holderRun();
};
