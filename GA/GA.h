#ifndef GA_H
#define GA_H

#include "VC.h"

class GA
{
public:
    GA();
    static void selection (VC *population[], int size);
    static void reproduction (VC *population[], int size);
    static void sort_population (VC *population[], int size);
};

#endif // GA_H
