#include "drive.h"

void Drive::driveLoop() {
    while (true) {
        if (!isPaused) {
            leftDrive.spin(forward, 12.0 * (static_cast<double>(Controller.Axis3.position())) / 100.0, volt);
            rightDrive.spin(forward, 12.0 * (static_cast<double>(Controller.Axis2.position())) / 100.0, volt);
            if (Controller.ButtonL1.pressing())
            {
                arm.spin(forward, 12.0, volt);
            }
            else if (Controller.ButtonL2.pressing())
            {
                arm.spin(reverse, 12.0, volt);
            }
            else
            {
                arm.stop();
            }
        }
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

void Drive::turn(double degrees, double speed, vex::turnType dir) {
    double currentDir = inertialSensor.heading(vex::rotationUnits::deg);
    if (dir == right) {
        double targetDir = currentDir + degrees;
        while (!functools::isClose(currentDir, targetDir, 1)) {
            vex::task::sleep(2);
            leftDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
            rightDrive.spin(reverse, ((double) speed / 100) * 12.0, volt);
            currentDir = inertialSensor.heading(vex::rotationUnits::deg);
        }
        speed /= 4;
        while (!functools::isClose(currentDir, targetDir, 0.1)) {
            vex::task::sleep(2);
            leftDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
            rightDrive.spin(reverse, ((double) speed / 100) * 12.0, volt);
            currentDir = inertialSensor.heading(vex::rotationUnits::deg);
        }
    }
}