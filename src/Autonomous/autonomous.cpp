#include "autonomous.h"
#include "navigator.h"

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    drive::pauseDrive();
    menu::enterMenu();
    Brain.Screen.print(navigator::locate().X);
}