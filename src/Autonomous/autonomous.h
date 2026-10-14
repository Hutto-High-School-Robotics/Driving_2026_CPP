#pragma once
#include "robot_config.h"

class Autonomous {
    private:
        int32_t selectedFudicial;
        bool isInMenu;
        bool abort;
        bool isInAutonomous;
        void SetupMenu();
        void UpdateMenu();
    public:
        Autonomous();
        void StartAutonomous();
        void SelectAutonomous();
        void CancelMenu();
        void MoveMenuRight();
        void MoveMenuLeft();
};