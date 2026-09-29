#ifndef MAGIC_CARPET_H
#define MAGIC_CARPET_H

#ifdef GAMEDLL_EXPRORTS
#define MAGIC_CARPET_API __declspec(dllexport)
#else
#define MAGIC_CARPET_API __declspec(dllimport)
#endif

class MAGIC_CARPET_API Magic_Carpet {
 
public:


    double Result_Math_Magic_Carpet(double &Range);
};



#endif