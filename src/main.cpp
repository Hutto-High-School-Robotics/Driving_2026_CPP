/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Zachary.Smith                                             */
/*    Created:      10/14/2026, 12:40:32 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "robot_config.h"
#include "autonomous.h"
#include "tools.h"

// declare functions before calling them
void handleLeft();
void handleRight();

thread autonomous = thread();

int setupButtonConfig() {
    Controller.ButtonX.pressed([]() {
        wait(1, sec);
        if (Controller.ButtonX.pressing() && !Autonomous::isAutonomous())
        {
            autonomous = thread([]() {
                Controller.Screen.clearScreen();
                Controller.Screen.setCursor(1,1);
                Controller.Screen.print("PUT CONTROLLER");
                Controller.Screen.setCursor(2,1);
                Controller.Screen.print("DOWN NOW");
                wait(2,sec);
                Autonomous::startAutonomous(); // * USE!!!
            });
        }
    });
    Controller.ButtonRight.pressed(handleRight);
    Controller.ButtonLeft.pressed(handleLeft);
    Controller.ButtonB.pressed([]() {
        if (Autonomous::isAutonomous())
        {
            autonomous.interrupt();
            Autonomous::postCancel();
        }
    });
    return 0;
}

void handleLeft() {
    if (drive::isPaused)
    {
        menu::moveMenuLeft();
    }
}

void handleRight() {
    if (drive::isPaused)
    {
        menu::moveMenuRight();
    }
}

int main() {
    if (setupButtonConfig() == 0) {
        Brain.Screen.print("WE ARE GOOD");
    }
    Brain.Screen.newLine();
    Brain.Screen.print("Hello V5");
    thread driveLoop = thread([]() {
        drive::driveLoop();
    });

    while(true) {
        // Allow other tasks to run
        vex::this_thread::sleep_for(10);
    }
}
