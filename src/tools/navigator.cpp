#include "navigator.h"

// PROGRAM IS UNTESTED!!! USE WITH CAUTION!!!

location navigator::locate()
{
    // size of internal autonomous: 2 ft x 2 ft
    // we will use trig to get the location
    double aiVisionObjects[aiVision.objectCount][6];
    aiVision.takeSnapshot(aivision::ALL_TAGS);
    for (size_t i{0}; i < aiVision.objectCount; ++i)
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
    // TODO: GET ACCURATE MEASUREMENT LIKE ASAP
    const double offset{0}; // offset compared to center; calculates position. + is offset right, - is offset left.

    double cenX{};
    double cenY{};
    double width{};
    double height{};
    double angle{};
    double id{};
    double xPosOffset{0};
    double yPosOffset{0};

    /*
    TODO:
    GET PROPER FIELD MEASUREMENTS
    */
   
    size_t ind{};

    double avgRot{};
    double curRot{};
    // Begin the avg loop for each object

    for (size_t i{0}; i < aiVision.objectCount; ++i)
    {
        switch(static_cast<int>(id))
        {
            case 9: case 16: // case 9 and 16 are equal
                xPosOffset = 52;
                break;
            case 10: case 15: // case 10 and 15 are equal too
                xPosOffset = 70;
                break;
            // wall 2
            case 11: case 20:
                yPosOffset = 16;
                break;
            case 12: case 19:
                yPosOffset = 52;
                break;
            case 13: case 18:
                yPosOffset = 70;
                break;
            case 14: case 17:
                yPosOffset = 88;
                break;
            default:
                continue; // in case we pick up anything else
        }
        cenX = aiVisionObjects[i][0];
        cenY = aiVisionObjects[i][1];
        width = aiVisionObjects[i][2];
        height = aiVisionObjects[i][3];
        angle = aiVisionObjects[i][4];
        id = aiVisionObjects[i][5];
        cenX += offset;

        // get the rotation
        switch (static_cast<int>(id))
        {
            // no case 0-8. We already continued out of it.
            case 9: case 10:
                curRot = 0;
                break;
            case 11: case 12: case 13: case 14:
                curRot = 90;
                break;
            case 15: case 16:
                curRot = 180;
                break;
            case 17: case 18: case 19: case 20: 
                curRot = 270;
                break;
            default:
                curRot = 0;
                break;
        }

        double distX{0};
        double distY{0};
        // if width and height are pretty close to not be considered angle
        if (!functools::isClose(width, height, 10))
        {
            if (functools::isClose(cenX, 0, 1))
            {
                distX = sizeToDist / width;
            }
            else
            // basically recenter ALL THE WAY until its close enough
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
        }
        else
        {
            
        }

        avgRot += 0; //TODO THIS
        avgX += distX;
        avgY += distY;
        ++ind;
    }

    avgX /= ind;
    avgY /= ind;

    return location(avgX, avgY, 180.0);
}