#include "drive.h"
#include "navigator.h"

void drive::driveLoop() {
    thread finger = thread([]() {
        servoLoop();
    });
    while (true) {
        if (!isPaused) {
            leftDrive.spin(forward, 12.0 * (static_cast<double>(Controller.Axis3.position())) / 100.0, volt);
            rightDrive.spin(forward, 12.0 * (static_cast<double>(Controller.Axis2.position())) / 100.0, volt);
            if (Controller.ButtonL1.pressing())
            {
                arm.spin(forward, 12.0, volt);
            }
            else if (Controller.ButtonL2.pressing())
            {
                arm.spin(reverse, 12.0, volt);
            }
            else
            {
                arm.stop();
            }
            if (Controller.ButtonR1.pressing())
            {
                isClawDown = false;
            }
            else if (Controller.ButtonR2.pressing())
            {
                isClawDown = true;
            }
            if (Controller.ButtonLeft.pressing())
            {
                isClawClosed = true;
                holder.setPosition(10,degrees);
            }
            else if(Controller.ButtonRight.pressing())
            {
                isClawClosed = false;
                holder.setPosition(50,degrees);
            }
            if (Controller.ButtonB.pressing())
            {
                stabilizeClaw();
            }
        }
        else
        {
            leftDrive.stop();
            rightDrive.stop();
            arm.stop();
        }
        vex::task::sleep(2);
    }
}

void drive::stabilizeClaw()
{
    if (isClawClosed)
    {
        holder.setPosition(11, degrees);
        wait(250,msec);
        holder.setPosition(12, degrees);
        wait(250,msec);
        holder.setPosition(11, degrees);
        wait(250,msec);
        holder.setPosition(10,degrees);
    }
    if (!isClawClosed)
    {
        holder.setPosition(49, degrees);
        wait(100,msec);
        holder.setPosition(48, degrees);
        wait(100,msec);
        holder.setPosition(49, degrees);
        wait(100,msec);
        holder.setPosition(50,degrees);
    }
}

void drive::servoLoop()
{
    int16_t timer = 1000;
    while (true)
    {
        if (isClawDown)
        {
            timer = 1000;
            claw.setPosition(-180,degrees);
            while (timer > 0)
            {
                wait(5,msec);
                timer -= 5;
                if (!isClawDown) // abort it if it turns into up
                {
                    break;
                }
            }
            if (!isClawDown) claw.setPosition(0,degrees); else continue;
            wait(5, msec);
        }
        else
        {
            claw.setPosition(50,degrees);
        }
    }
}

void drive::pauseDrive() {
    isPaused = true;
}

void drive::unpauseDrive() {
    isPaused = false;
}

void drive::beginManualDrive(int32_t speed) {
    if (speed <= 100 || speed >= 0) {
        leftDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
        rightDrive.spin(forward, ((double) speed / 100) * 12.0, volt);
    }
}

/**
 * ! DO NOT USE !
 * ! BROKEN FUNCTIONALITY !
 */
void drive::turn(double degrees, double speed, vex::turnType dir) {
    leftDrive.spin(forward, ((speed/100.0) * 12.0), volt);
}

void drive::turn(vex::turnType dir, double time, timeUnits unit) {
    if (dir == right)
    {
        leftDrive.spin(forward,6.0,volt);
        rightDrive.spin(reverse,6.0,volt);
    }
    wait(time, unit);
    leftDrive.stop();
    rightDrive.stop();
}
