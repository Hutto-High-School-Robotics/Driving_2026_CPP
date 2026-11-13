#pragma once
#include "robot_config.h"

namespace menu
{
    bool getMenuStatus();
    void enterMenu();
    void exitMenu();
    void moveMenuLeft();
    void moveMenuRight();
    int getSelection();
}
