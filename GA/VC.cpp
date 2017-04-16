#include "VC.h"

VC::VC()
{
    fitness=0;
    valid_fitness=false;

}


bool VC::operator> (const VC &c) {
    return fitness > c.fitness;
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

bool VC::operator== (const VC &c) {
    return fitness == c.fitness;
}

bool VC::operator!= (const VC &c) {
    return fitness != c.fitness;
}


VC::~VC() {

}
