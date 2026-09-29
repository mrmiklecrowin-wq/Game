#ifndef CENTAUR_H
#define CENTAUR_H


#ifdef GAMEDLL_EXPRORTS
#define CENTAUR_API __declspec(dllexport)
#else
#define CENTAUR_API __declspec(dllimport)
#endif



class CENTAUR_API Centaur {

public:

	double Result_Math_Centaur(double &Range);
};
#endif
