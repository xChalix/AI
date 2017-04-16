#include <iostream>

#include "dummy.h"
#include "GA.h"
#include "VC.h"

using namespace std;

void test_GA_sort_population();
void test_GA_selection();
void test_GA_reproduction();

int main(int argc, char *argv[])
{
    cout    <<"\nUNIT TESTS\n"
            <<"############################\n"
            <<"############################\n\n";

    test_GA_sort_population();
    test_GA_selection();
    test_GA_reproduction();

    return 0;
}

void test_GA_sort_population() {
    /*
    VC*test1[10];
    Dummy*test2[10];
    for (int i=0;i<10;i++) {
        test2[i] = new Dummy(i+1);
        test2[i]->fitness=i;
    }for (int i=0;i<10;i++) {
        test1[i] = test2[i]; //WORKS -> use reinterpret cast!

    }
    //test1 = test2; //DOES NOT WORK
    */

    cout    <<"Test GA::sort_population\n"
            <<"############################\n\n";

    //create population
    Dummy *population[10];

    for (int i=0;i<10;i++) {
        population[i]=0;
        population[i] = new Dummy(i+1);
        population[i]->fitness=i;
    }
    delete population[9];
    delete population[4];
    population[9]=0;
    population[4]=0;


    cout    <<"\nBefore sorting:\n";
    for (int i=0; i<10;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }

    GA::sort_population(reinterpret_cast<VC**>(population), 10);

    cout    <<"\nAfter sorting:\n";
    for (int i=0; i<10;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }
}

void test_GA_selection() {
    Dummy *population[10];

    for (int i=0;i<10;i++) {
        population[i]=0;
        population[i] = new Dummy(i+1);
        population[i]->fitness=i;
    }
    delete population[9];
    delete population[4];
    population[9]=0;
    population[4]=0;


    cout    <<"\nBefore selection:\n";
    for (int i=0; i<10;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }

    GA::selection(reinterpret_cast<VC**>(population), 10);

    cout    <<"\nAfter selection:\n";
    for (int i=0; i<10;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }

}

void test_GA_reproduction() {
    Dummy *population[10];

    for (int i=0;i<10;i++) {
        population[i]=0;
        population[i] = new Dummy(i+1);
        population[i]->fitness=i;
    }
    delete population[9];
    delete population[4];
    population[9]=0;
    population[4]=0;


    cout    <<"\nBefore reproduction:\n";
    for (int i=0; i<10;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }

    GA::reproduction(reinterpret_cast<VC**>(population), 10);

    cout    <<"\nAfter reproduction:\n";
    for (int i=0; i<10;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }
}
