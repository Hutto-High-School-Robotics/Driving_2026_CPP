#include "autonomous.h"
#include "navigator.h"

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    isInAutonomous = true;
    drive::pauseDrive();
    //menu::enterMenu();
    //Brain.Screen.print(navigator::locate().X);
    drive::raiseArm();
    wait(2, sec);
    drive::stopArm();
    drive::beginManualDrive(50);
    wait(1,sec);
    drive::stopManualDrive();
    drive::turn(right, 0.9, sec);
    drive::beginManualDrive(50);
    wait(.75,sec);
    drive::stopManualDrive();
    drive::lowerArm();
    wait(1, sec);
    drive::stopArm();
    drive::openClaw();
    drive::openHolder();
    wait(0.5,sec);
    drive::beginManualDrive(-50);
    wait(.75, sec);
    drive::stopManualDrive();
    drive::turn(left, 0.9, sec);
    drive::beginManualDrive(-50);
    wait(1, sec);
    drive::stopManualDrive();
    postCancel();
}

bool Autonomous::isAutonomous()
{
    return isInAutonomous;
}

void Autonomous::postCancel()
{
    isInAutonomous = false;
    drive::unpauseDrive();
    Controller.Screen.clearScreen();
}

bool Autonomous::seesFiducial(int fiducial[])
{
    aiVision.takeSnapshot(aivision::ALL_TAGS);
    return false;
}

bool Autonomous::isInDangerZone(location current)
{
    double sizeLists[2][3] {
        {0, 1, 2},
        {3, 4, 5}
    };
    for (size_t i{}; i < 2; ++i)
    {
        bool isX = i == 1;

        double curPos = isX ? current.X : current.Y; // if isX, then get x. If not, then get y.

        for (auto warn : sizeLists[i])
        {
            if (func_tools::isClose(warn, curPos, robotSize))
            {
                return true;
            }
        }
    }

    return false;
}
