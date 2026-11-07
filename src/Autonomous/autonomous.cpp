#include "autonomous.h"

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    drive::pauseDrive();
    menu::enterMenu();
}