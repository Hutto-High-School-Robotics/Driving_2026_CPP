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

Autonomous autonomous;

int setupButtonConfig() { 
    Controller.ButtonX.pressed([]() {
        autonomous.StartAutonomous();
    });
    return 0;
}

int main() {
    if (setupButtonConfig() == 1) {
        
    }
    Brain.Screen.printAt( 10, 50, "Hello V5" );
   
    while(true) {
        // Allow other tasks to run
        vex::this_thread::sleep_for(10);
    }
}
