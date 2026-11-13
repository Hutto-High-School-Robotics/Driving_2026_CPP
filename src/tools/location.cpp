#include "location.h"

location::location(double x, double y, double rotationDegrees) : X(x), Y(y), rotation(rotationDegrees)
{
    isDegrees = true;
}

location::location(double x, double y) : X(x), Y(y), rotation(0.0)
{
    isDegrees = true;
}

double location::rotationDegrees() const
{
    return isDegrees ? rotation : rotation * (M_PI/180.0);
}

double location::rotationRadians() const
{
    return isDegrees ? rotation * (180.0/M_PI) : rotation;
}
