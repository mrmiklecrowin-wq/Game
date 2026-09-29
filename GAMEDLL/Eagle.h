#ifndef EAGLE_H
#define EAGLE_H

#ifdef GAMEDLL_EXPRORTS
#define EAGLE_API __declspec(dllexport)
#else
#define EAGLE_API __declspec(dllimport)
#endif


class EAGLE_API Eagle {

public:

    double Result_Math_Eagle(double &Range);
};
#endif
