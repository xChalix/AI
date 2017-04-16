#include "dummy.h"

Dummy::Dummy(int ID) : ID(ID)
{
    weight=0;
}

void Dummy::print() {
    cout << "Creature: "<<ID<<" Fitness: "<<fitness<<"\n";
}

void Dummy::mutate() {
    weight+=1;
}

VC* Dummy::copy() {
    Dummy *c = new Dummy(ID);
    c->fitness=fitness;
    c->weight=weight;
    return c;
}


