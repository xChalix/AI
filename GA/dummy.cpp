#include "dummy.h"

Dummy::Dummy(int ID) : ID(ID)
{

}

void Dummy::print() {
    cout << "Creature: "<<ID<<" Fitness: "<<fitness<<"\n";
}
