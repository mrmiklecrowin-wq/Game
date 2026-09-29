#ifndef BOOTS_H
#define BOOTS_H

#ifdef GAMEDLL_EXPRORTS
#define BOOTS_API __declspec(dllexport)
#else
#define BOOTS_API __declspec(dllimport)
#endif


class BOOTS_API Boots {

public:
		
	double Result_Math_Boots(double& Range);
};

#endif
