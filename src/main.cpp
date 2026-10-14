/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Zachary.Smith                                             */
/*    Created:      10/14/2026, 12:40:32 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "robot_config.h"
#include "autonomous/autonomous.h"


Drive driver = Drive(0, 1, 2);
Autonomous autonomous = Autonomous(driver);

// declare functions before calling them
void handleLeft();
void handleRight();

int setupButtonConfig() { 
    Controller.ButtonX.pressed([]() {
        autonomous.startAutonomous();
    });
    Controller.ButtonRight.pressed(handleRight);
    Controller.ButtonLeft.pressed(handleLeft);
    return 0;
}

void handleLeft() {
    if (autonomous.inMenu()) {
        autonomous.moveMenuLeft();
    }
}

void handleRight() {
    if (autonomous.inMenu()) {
        autonomous.moveMenuRight();
    }
}

int main() {
    if (setupButtonConfig() == 0) {
        Brain.Screen.print("WE ARE GOOD");
    }
    Brain.Screen.newLine();
    Brain.Screen.print("Hello V5");
    thread driveLoop = thread([]() {
        driver.driveLoop();
    });

    Brain.Screen.print("AAAAAAAAAA");
   
    while(true) {
        // Allow other tasks to run
        vex::this_thread::sleep_for(10);
    }
}
