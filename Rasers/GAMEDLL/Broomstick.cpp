#include "Broomstick.h"




double Broomstick::Result_Math_Broomstick(double &Range) {
    double Result_Time_BROOMSTICK = 0;

    double Speed = 20;

    int thousands = static_cast<int>(Range / 1000.0);
    double coeff = thousands * 0.01;

    double effective_range = Range * (1.0 - coeff);
    Result_Time_BROOMSTICK = effective_range / Speed;

    return Result_Time_BROOMSTICK;
};
