#pragma once
#include "math.h"

class location
{
public:
    location(double x, double y, double rotationDegs);
    ~location();
    const double X;
    const double Y;
    double rotationDegrees() const;
    double rotationRadians() const;
private:
    bool isDegrees;
    const double rotation;
};