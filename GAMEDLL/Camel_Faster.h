#ifndef CAMEL_FASTER_H
#define CAMEL_FASTER_H


#ifdef GAMEDLL_EXPRORTS
#define CAMEL_FASTER_API __declspec(dllexport)
#else
#define CAMEL_FASTER_API __declspec(dllimport)
#endif


class CAMEL_FASTER_API Camel_Faster {

public:

	double Result_Math_Camel_Faster(double &Range);
};

#endif
