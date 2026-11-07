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
        void SetupMenu();
        void UpdateMenu();
    };
    namespace internalNavigation
    {
    };
    void startAutonomous();
    void selectAutonomous();
    void cancelMenu();
    void moveMenuRight();
    void moveMenuLeft();
    bool inMenu();
};