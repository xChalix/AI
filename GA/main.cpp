#include <iostream>
#include <random>

#include "dummy.h"
#include "GA.h"
#include "VC.h"

using namespace std;

void test_GA_sort_population();
void test_GA_selection();
void test_GA_reproduction();

void GA_dryrun(default_random_engine generator);

void print_dummys(Dummy *population[], int size);


int main(int argc, char *argv[])
{
    default_random_engine generator;

    char mode;
    cout << "Type u for Unit Tests, d for GA dryrun, else for exit: ";
    cin >> mode;

    switch (mode) {
    case 117:
        cout    <<"\nUNIT TESTS\n"
                <<"############################\n"
                <<"############################\n";

        test_GA_sort_population();
        test_GA_selection();
        test_GA_reproduction();
        break;
    case 100:
        GA_dryrun(generator);
        break;
    }


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

    cout    <<"\n\nTest GA::sort_population\n"
            <<"############################\n";

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
    print_dummys(population,10);

    GA::sort_population(reinterpret_cast<VC**>(population), 10);

    cout    <<"\nAfter sorting:\n";
    print_dummys(population,10);
}

void test_GA_selection() {
    cout    <<"\n\nTest GA::selection\n"
            <<"############################\n";
    Dummy *population[10];

    for (int i=0;i<10;i++) {
        population[i]=0;
        population[i] = new Dummy(i+1);
        population[i]->fitness=i;
        population[i]->valid_fitness=true;
    }
    delete population[9];
    delete population[4];
    population[9]=0;
    population[4]=0;


    cout    <<"\nBefore selection:\n";
    print_dummys(population,10);

    GA::selection(reinterpret_cast<VC**>(population), 10);

    cout    <<"\nAfter selection:\n";
    print_dummys(population,10);

}

void test_GA_reproduction() {
    cout    <<"\n\nTest GA::reproduction\n"
            <<"############################\n";
    Dummy *population[10];

    for (int i=0;i<10;i++) {
        population[i]=0;
        population[i] = new Dummy(i+1);
        population[i]->fitness=i;
        population[i]->valid_fitness=true;
    }
    delete population[9];
    delete population[4];
    population[9]=0;
    population[4]=0;


    cout    <<"\nBefore reproduction:\n";
    print_dummys(population,10);

    GA::reproduction(reinterpret_cast<VC**>(population), 10);

    cout    <<"\nAfter reproduction:\n";
    print_dummys(population,10);
}

void GA_dryrun(default_random_engine generator) {
    //random weights introduced between 1 and 100
    //mutation: +- 1
    //goal: weight of 50.
    //fitness function: 1 / squared error: 1/(50-weight)*(50-weight)
    //population size: 7

    //Initializations
    int size=7;
    int counter=0; //used for IDs
    Dummy *population[size];

    //Creating first population
    uniform_int_distribution<int> uniform_hundred(1,100);
    for (int i=0;i<size;i++) {
        population[i] = new Dummy(counter++);
        population[i]->weight=uniform_hundred(generator);
    }

    cout    <<"Initial Generation: \n";
    print_dummys(population,size);

    //Running the GA:
    bool go_on = true;
    Dummy *successfull_creature=0;
    int generation_number=1;
    while(go_on) {
        //testing the population:
        for (int i=0; i<size; i++) {
            population[i]->fitness = (double)1/((50.0-(double)population[i]->weight)*(50.0-(double)population[i]->weight));
            population[i]->valid_fitness = true; // DO NOT FORGET THIS!!!
        }
        GA::selection(reinterpret_cast<VC**>(population),size);
        GA::reproduction(reinterpret_cast<VC**>(population),size);

        //print:
        cout<<generation_number++<<". Generation\n";
        print_dummys(population,size);

        //check for goal:
        for (int i=0; i<size; i++) {
            if (population[i]->weight==50) {
                go_on=false;
                successfull_creature=population[i];
                break;
            }
        }

        // I/O:
        if (go_on) {
            char input;
            cout<<"Next Step (c for continue, a for abbort): ";
            cin>>input;
            if (input==97) go_on=false;
        }

    }
    if (successfull_creature!=0) {
        cout<<"A solution was found!\n";
        successfull_creature->print();
    } else {
        cout<<"No solution was found, GA was canceled\n";
    }
}

void print_dummys(Dummy *population[],int size) {
    for (int i=0; i<size;i++) {
        if (population[i]!=0)
            population[i]->print();
        else
            cout << "Creature: NULL\n";
    }
}
