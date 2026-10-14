#include "drive.h"

Drive* Drive::instance = nullptr;

Drive::Drive(int32_t leftDrivePort, int32_t rightDrivePort, int32_t inertialSensorPort) : leftDrive(leftDrivePort), rightDrive(rightDrivePort), inertialSensor(inertialSensorPort) {
    instance = this;
}

void Drive::driveLoop() {
    while (!isPaused) {
        leftDrive.spin(forward, 12.0 * ((double) Controller.Axis3.position() / 100), volt);
        rightDrive.spin(forward, 12.0 * ((double) Controller.Axis2.position() / 100), volt);
        wait(2,msec);
    }
}

void Drive::beginDriveLoop() {
    if (instance != nullptr) {
        instance->driveLoop();
    }
}

void Drive::pauseDrive() {
    isPaused = true;
}

void Drive::unpauseDrive() {
    isPaused = false;
}

void Drive::beginManualDrive(int32_t speed) {
    if (speed <= 100 || speed >= 0) {
        leftDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
        rightDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
    }
}