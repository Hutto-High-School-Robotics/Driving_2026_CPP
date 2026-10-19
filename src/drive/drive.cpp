#include "drive.h"

Drive::Drive(int32_t leftDrivePort, int32_t rightDrivePort, int32_t inertialSensorPort) : leftDrive(leftDrivePort), rightDrive(rightDrivePort), inertialSensor(inertialSensorPort) {}

void Drive::driveLoop() {
    while (!isPaused) {
        leftDrive.spin(forward, 12.0 * ((double) Controller.Axis3.position() / 100), volt);
        rightDrive.spin(forward, 12.0 * ((double) Controller.Axis2.position() / 100), volt);
        vex::task::sleep(2);
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

static bool isClose(double a, double b, double precision = 0.01) {
    return a - b < precision || a - b > 0 - precision;
}

void Drive::turn(double degrees, double speed, vex::turnType dir) {
    double currentDir = inertialSensor.heading(vex::rotationUnits::deg);
    if (dir == right) {
        double targetDir = currentDir + degrees;
        while (!isClose(currentDir, targetDir, 1)) {
            vex::task::sleep(2);
            leftDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
            rightDrive.spin(reverse, ((double) speed / 100) * 12.0, volt);
            currentDir = inertialSensor.heading(vex::rotationUnits::deg);
        }
        speed /= 4;
        while (!isClose(currentDir, targetDir, 0.1)) {
            vex::task::sleep(2);
            leftDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
            rightDrive.spin(reverse, ((double) speed / 100) * 12.0, volt);
            currentDir = inertialSensor.heading(vex::rotationUnits::deg);
        }
    }
}