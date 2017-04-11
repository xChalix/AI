#include "VC.h"

VC::VC()
{

}


bool VC::operator> (const VC &c1, const VC &c2)
{
    return c1.fitness > c2.fitness;
}

bool VC::operator>= (const VC &c1, const VC &c2)
{
    return c1.fitness >= c2.fitness;
}

bool VC::operator< (const VC &c1, const VC &c2)
{
    return c1.fitness < c2.fitness;
}

bool VC::operator<= (const VC &c1, const VC &c2)
{
    return c1.fitness <= c2.fitness;
}
