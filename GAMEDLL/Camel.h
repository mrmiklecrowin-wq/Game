#ifndef CAMEL_H
#define CAMEL_H


#ifdef GAMEDLL_EXPRORTS
#define CAMEL_API __declspec(dllexport)
#else
#define CAMEL_API __declspec(dllimport)
#endif



class CAMEL_API Camel {

public:


	double Result_Math_Camel(double& Range);
};

#endif
