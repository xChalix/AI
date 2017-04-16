#ifndef DUMMY_H
#define DUMMY_H

#include <iostream>

using namespace std;

#include "VC.h"

class Dummy : public VC
{
public:
    Dummy(int ID=0);
    int ID, weight;
    void print();

    void mutate();
    VC* copy();

};

#endif // DUMMY_H
