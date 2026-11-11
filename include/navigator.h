#include "robot_config.h"
#include "tools.h"

namespace navigator
{
    namespace
    {
        /** Gets all the objects detected on the AI Vision Sensor.
         * Array objects are:
         * 0: centerX
         * 1: centerY
         * 2: width
         * 3: height
         * 4: angle
         * 5: id
         * 6: tag x1
         * 7: tag x2
         * 8: tag x3
         * 9: tag x4
         * 10: tag y1
         * 11: tag y2
         * 12: tag y3
         * 13: tag y4
         * 14: exists
         */
        std::array<std::array<double,7>,15> GetObjects()
        {
            aiVision.takeSnapshot(aivision::ALL_TAGS);
            std::array<std::array<double, 7>,15> aiVisionObjects;
            for (size_t i{0}; i < aiVision.objectCount; ++i)
            {
                auto obj = aiVision.objects[i];
                if (obj.exists)
                {
                    aiVisionObjects[i][0] = obj.centerX;
                    aiVisionObjects[i][1] = obj.centerY;
                    aiVisionObjects[i][2] = obj.width;
                    aiVisionObjects[i][3] = obj.height;
                    aiVisionObjects[i][4] = obj.angle;
                    aiVisionObjects[i][5] = obj.id;
                    aiVisionObjects[i][6] = obj.tag.x[0];
                    aiVisionObjects[i][7] = obj.tag.x[1];
                    aiVisionObjects[i][8] = obj.tag.x[2];
                    aiVisionObjects[i][9] = obj.tag.x[3];
                    aiVisionObjects[i][10] = obj.tag.y[0];
                    aiVisionObjects[i][11] = obj.tag.y[1];
                    aiVisionObjects[i][12] = obj.tag.y[2];
                    aiVisionObjects[i][13] = obj.tag.y[3];
                    aiVisionObjects[i][14] = true;
                }
                else
                {
                    aiVisionObjects[i][14] = false;
                }
            }
            /** this is the object at hand.
            * Array objects are:
            * 0: centerX
            * 1: centerY
            * 2: width
            * 3: height
            * 4: angle
            * 5: id
            * 6: tag x1
            * 7: tag x2
            * 8: tag x3
            * 9: tag x4
            * 10: tag y1
            * 11: tag y2
            * 12: tag y3
            * 13: tag y4
            * 14: exists
            */
            return aiVisionObjects;
        }
    };
    location locate();
    double getRotation();
}