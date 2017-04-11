#include "VC.h"

VC::VC()
{

}


bool VC::operator> (const VC &c) {
    return fitness > c2.fitness;
}

bool VC::operator>= (const VC &c) {
    return fitness >= c.fitness;
}

bool VC::operator< (const VC &c) {
    return fitness < c.fitness;
}

bool VC::operator<= (const VC &c) {
    return fitness <= c.fitness;
}
