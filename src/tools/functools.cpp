#include "functools.h"

namespace functools
{
    static bool isClose(double a, double b, double precision = 0.01)
    {
        return ((a - b) < precision) || ((a - b) > 0 - precision);
    }
}