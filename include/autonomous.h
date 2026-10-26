#pragma once
#include "robot_config.h"
#include "drive.h"
#include "tools.h"

class Autonomous {
    private:
        int32_t selectedFiducial;
        bool isInMenu;
        bool abort;
        bool isInAutonomous;
        void SetupMenu();
        void UpdateMenu();
        Drive &drive;
    public:
        Autonomous(Drive &drive);
        void startAutonomous();
        void selectAutonomous();
        void cancelMenu();
        void moveMenuRight();
        void moveMenuLeft();
        bool inMenu();
};