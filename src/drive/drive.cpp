#include "drive.h"
#include "navigator.h"
#include "autonomous.h"

void drive::driveLoop()
{
    isClawClosed = true;
    thread finger = thread(servoLoop);
    thread driving = thread(train);
    thread armControl = thread(armRun);
    thread clawControl = thread(clawRun);
    thread holderControl = thread(holderRun);
}

void drive::train()
{
    while (true) {
        if (!isPaused)
        {
            leftDrive.spin(forward, 12.0 * (static_cast<double>(Controller.Axis3.position())) / 100.0, volt);
            rightDrive.spin(forward, 12.0 * (static_cast<double>(Controller.Axis2.position())) / 100.0, volt);
        }
        else
        {
            if (!Autonomous::isAutonomous())
            {
                leftDrive.stop();
                rightDrive.stop();
            }
        }
        vex::task::sleep(5);
    }
}

void drive::armRun()
{
    while (true)
    {
        if (!isPaused)
        {
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
        }
        else
        {
            if (!Autonomous::isAutonomous())
            {
                arm.stop();
            }
        }
        vex::task::sleep(5);
    }
}

void drive::clawRun()
{
    while (true)
    {
        if (!isPaused)
        {
            if (Controller.ButtonR1.pressing())
            {
                isClawDown = false;
            }
            else if (Controller.ButtonR2.pressing())
            {
                isClawDown = true;
            }
        }
        vex::task::sleep(5);
    }
}

void drive::holderRun()
{
    while (true)
    {
        if (!isPaused)
        {
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
        vex::task::sleep(5);
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
            claw.setPosition(-50,degrees);
            while (timer > 0)
            {
                wait(5,msec);
                timer -= 5;
                if (!isClawDown) // abort it if it turns into up
                {
                    break;
                }
            }
            if (isClawDown) claw.setPosition(50,degrees); else continue;
            wait(5, msec);
        }
        else
        {
            claw.setPosition(50,degrees);
        }
        vex::task::sleep(5);
    }
}

void drive::pauseDrive() {
    isPaused = true;
}

void drive::unpauseDrive() {
    isPaused = false;
}

void drive::beginManualDrive(double speed) {
    if (speed <= 100 && speed >= -100) {
        leftDrive.spin(forward, (speed / 100.0) * 12.0, volt);
        rightDrive.spin(forward, (speed / 100.0) * 12.0, volt);
    }
}

void drive::stopManualDrive()
{
    leftDrive.stop();
    rightDrive.stop();
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
        leftDrive.spin(forward,2.0,volt);
        rightDrive.spin(reverse,2.0,volt);
    }
    else if (dir == left)
    {
        leftDrive.spin(forward,2.0,volt);
        rightDrive.spin(reverse,2.0,volt);
    }
    wait(time, unit);
    leftDrive.stop();
    rightDrive.stop();
}

void drive::raiseArm()
{
    arm.spin(forward, 12.0, volt);
}

void drive::lowerArm()
{
    arm.spin(reverse, 12.0, volt);
}

void drive::stopArm()
{
    arm.stop();
}

void drive::openClaw()
{
    isClawDown = false;
}

void drive::closeClaw()
{
    isClawDown = true;
}

void drive::openHolder()
{
    isClawClosed = false;
}

void drive::closeHolder()
{
    isClawClosed = true;
}
