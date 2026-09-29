#ifndef BROOMSTICK_H
#define BROOMSTICK_H

#ifdef GAMEDLL_EXPRORTS
#define BROOMSTICK_API __declspec(dllexport)
#else
#define BROOMSTICK_API __declspec(dllimport)
#endif

class BROOMSTICK_API Broomstick {

public:

    double Result_Math_Broomstick(double& Range);
};


#endif
