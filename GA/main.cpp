#include <iostream>

#include "dummy.h"
#include "GA.h"

using namespace std;

int main(int argc, char *argv[])
{
    Dummy *population[10];
    for (int i=0;i<10;i++) {
        population[i]->ID=i+1;
        population[i]->fitness=i;
    }
    cout<<"\nBefore sorting:\n";
    for (int i=0; i<10;i++) {
        population[i]->print();
    }
    GA::sort_population(population, 10);
    cout<<"\nAfter sorting:\n";
    for (int i=0; i<10;i++) {
        population[i]->print();
    }
    return 0;
}
