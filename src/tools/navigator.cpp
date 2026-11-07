#include "navigator.h"

location navigator::locate()
{
    // size of internal autonomous: 2 ft x 2 ft
    // we will use trig to get the location
    double aiVisionObjects[aiVision.objectCount][5];
    aiVision.takeSnapshot(aivision::ALL_TAGS);
    for (int i{0}; i < aiVision.objectCount; ++i)
    {
        auto obj = aiVision.objects[i];
        aiVisionObjects[i][0] = obj.centerX;
        aiVisionObjects[i][1] = obj.centerY;
        aiVisionObjects[i][2] = obj.width;
        aiVisionObjects[i][3] = obj.height;
        aiVisionObjects[i][4] = obj.angle;
    }
    double avgX{};
    double avgY{};
    const double sizeToDist{2.5}; // calculated using the idea: size decreases by 2x as distance increases by 2x, so size is 1/d.
    const double offset{0};

    double cenX = aiVisionObjects[0][0];
    double cenY = aiVisionObjects[0][1];
    double width = aiVisionObjects[0][2];
    double height = aiVisionObjects[0][3];
    double angle = aiVisionObjects[0][4];
    // TODO: find the ratio of size to distance (our x)
    cenX += offset;

    // if center x is close to zero, then use this as the distance point.
    if (functools::isClose(cenX, 0, 1))
    {
        // use this for distance
    }
    else
    {
        // use this for distance
    }

    //use this distance to get a rough estimate.
    double dist = sizeToDist * width;
    // use distance to return a new location

    return location(avgX, avgY, 180.0);
}