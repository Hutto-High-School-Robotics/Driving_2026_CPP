#pragma once
#include "robot_config.h"
#include "drive.h"
#include "tools.h"

namespace Autonomous
{
    namespace
    {
        int32_t selectedFiducial;
        bool isInMenu;
        bool abort;
        bool isInAutonomous;
        void setupMenu();
        void updateMenu();
    };
    bool isInDangerZone(location current);
    void startAutonomous();
    void selectAutonomous();
    void cancelMenu();
    void moveMenuRight();
    void moveMenuLeft();
    bool inMenu();
    bool seesFiducial(int fiducial[]);
};
