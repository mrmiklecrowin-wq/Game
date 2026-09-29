#include "Magic_carpet.h"



double Magic_Carpet::Result_Math_Magic_Carpet(double &Range) {

    double Result_Time_MAGIC_CARPET = 0;


    double Speed = 10;
    double Reduction_Coeff = 0;


    if (Range < 1000.0) {
        Reduction_Coeff = 0.0;
    }
    else if (Range < 5000.0) {
        Reduction_Coeff = 0.03;
    }
    else if (Range < 10000.0) {
        Reduction_Coeff = 0.10;
    }
    else {
        Reduction_Coeff = 0.05;
    }

    double effective_range = Range * (1.0 - Reduction_Coeff);
    Result_Time_MAGIC_CARPET = effective_range / Speed;
    return Result_Time_MAGIC_CARPET;
};
