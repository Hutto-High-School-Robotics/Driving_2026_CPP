#include "autonomous.h"

Autonomous::Autonomous(Drive &drive) : drive(drive) {}

void Autonomous::SetupMenu() {
    selectedFiducial = 1;
    isInMenu = true;
    // clear and print to the screen
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1,1);
    Controller.Screen.print("Select a fiducial:");
    Controller.Screen.setCursor(2,1);
    Controller.Screen.print(selectedFiducial);
    Controller.Screen.setCursor(3,1);
    Controller.Screen.print("Select with A");
}

void Autonomous::UpdateMenu() {
    Controller.Screen.setCursor(2,1);
    Controller.Screen.print(selectedFiducial);
    Controller.Screen.setCursor(3,1);
}

void Autonomous::moveMenuRight() {
    if (selectedFiducial < 9) {
        selectedFiducial++;
        UpdateMenu();
    }
}

void Autonomous::moveMenuLeft() {
    if (selectedFiducial > 1) {
        selectedFiducial--;
        UpdateMenu();
    }
}

bool Autonomous::inMenu() {
    return isInMenu;
}

void Autonomous::startAutonomous() {
    drive.pauseDrive();
    SetupMenu();
}