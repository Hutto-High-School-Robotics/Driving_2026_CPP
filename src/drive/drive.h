#pragma once
#include "../robot_config.h"

class Drive {
    private:
        bool isPaused;
        motor55 leftDrive;
        motor55 rightDrive;
        inertial inertialSensor;
    public:
        Drive(int32_t leftDrivePort, int32_t rightDrivePort, int32_t inertialSensorPort);
        void driveLoop();
        void pauseDrive();
        void unpauseDrive();
        void beginManualDrive(int32_t speed);
        void stopManualDrive();
        void turn(double degrees, double speed = 50, vex::turnType dir = right);
};