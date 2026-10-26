#include "autonomous.h"

Autonomous::Autonomous(Drive &drive) : drive(drive) {}

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    drive.pauseDrive();
    menu::enterMenu();
}