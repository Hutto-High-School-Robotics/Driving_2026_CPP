#include "navigator.h"

// PROGRAM IS UNTESTED!!! USE WITH CAUTION!!!

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
        aiVisionObjects[i][5] = obj.id;
    }
    double avgX{};
    double avgY{};
    const double sizeToDist{2.5}; // calculated using the idea: size decreases by 2x as distance increases by 2x, so size is 1/d.
    const double offset{0}; // offset compared to center; calculates position. + is offset right, - is offset left.

    double cenX{};
    double cenY{};
    double width{};
    double height{};
    double angle{};
    double id{};
    double xPosOffset{0};
    double yPosOffset{0};

    for (int i{0}; i < aiVision.objectCount; ++i)
    {
        switch(static_cast<int>(id))
        {
            case 0: case 1: case 2: case 3:
            case 4: case 5: case 6: case 7:
            case 8:
                continue; // no; we dont need id 0-8, those are tables.
                // to be honest, if we saw table id, something went wrong lol
            case 9:
                xPosOffset = 200;
                break;
        }
        cenX = aiVisionObjects[i][0];
        cenY = aiVisionObjects[i][1];
        width = aiVisionObjects[i][2];
        height = aiVisionObjects[i][3];
        angle = aiVisionObjects[i][4];
        id = aiVisionObjects[i][5];
        break;
    }

    cenX += offset;

    double distX{0};
    double distY{0};
    // if center x is close to zero, then use this as the distance point.
    if (functools::isClose(cenX, 0, 1))
    {
        // use this for distance
    }
    else
    {
        distX = sizeToDist / width;
        double targ{width / 2.0};
        double leftX{cenX};
        const double centerScreen{160.0};
        while (!functools::isClose(leftX, centerScreen, targ))
        {
            if (leftX > centerScreen)
            {
                leftX -= width;
                distY += width;
                if (leftX < centerScreen)
                {
                    leftX += width / 2.0;
                    distY -= width / 2.0;
                    if (leftX > centerScreen)
                    {
                        leftX -= width / 4.0;
                        distY += width / 4.0;
                    }
                }
            }
            if (leftX < centerScreen)
            {
                leftX += width;
                distY -= width;
                if (leftX < centerScreen)
                {
                    leftX -= width / 2.0;
                    distY += width / 2.0;
                    if (leftX > centerScreen)
                    {
                        leftX += width / 4.0;
                        distY -= width / 4.0;
                    }
                }
            }
        }
    }

    return location(distX + xPosOffset, distY + yPosOffset, 180.0);
}