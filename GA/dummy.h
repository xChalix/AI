#ifndef DUMMY_H
#define DUMMY_H

#include <iostream>

#include "VC.h"

class Dummy : VC
{
public:
    Dummy(int ID=0);
    int ID;
    void print();
};

#endif // DUMMY_H
