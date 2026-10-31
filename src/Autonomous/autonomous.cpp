#include "autonomous.h"

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    Drive::pauseDrive();
    menu::enterMenu();
}