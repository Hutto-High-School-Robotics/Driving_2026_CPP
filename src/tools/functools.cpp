#include "functools.h"

namespace func_tools
{
    static bool isClose(double a, double b, double precision)
    {
        return ((a - b) < precision) || ((a - b) > 0 - precision);
    }
}
