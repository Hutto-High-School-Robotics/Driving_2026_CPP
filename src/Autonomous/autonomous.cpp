#include "autonomous.h"
#include "navigator.h"

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    drive::pauseDrive();
    //menu::enterMenu();
    //Brain.Screen.print(navigator::locate().X);
    drive::beginManualDrive(10);
    wait(1,sec);
    drive::stopManualDrive();
    drive::turn(right, 1.5, sec);
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
