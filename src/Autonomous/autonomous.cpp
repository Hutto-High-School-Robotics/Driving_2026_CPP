#include "autonomous.h"

Autonomous::Autonomous() {

}

void Autonomous::SetupMenu() {
    selectedFudicial = 1;
    // clear and print to the screen
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1,1);
    Controller.Screen.print("Hello, world!");
    // how do you do this.
}

void Autonomous::StartAutonomous() {
    SetupMenu();
}