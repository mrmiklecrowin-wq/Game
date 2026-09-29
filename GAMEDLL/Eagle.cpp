#include "Eagle.h"





double Eagle::Result_Math_Eagle(double &Range) {

    double Result_Time_Eagle = 0;

    double Speed = 8;
    double Reduction_Coeff = 0.06;

    double effective_range = Range * (1.0 - Reduction_Coeff);
    Result_Time_Eagle = effective_range / Speed;

    return Result_Time_Eagle;
};