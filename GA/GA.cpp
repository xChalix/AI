#include "GA.h"

GA::GA()
{

}

static void GA::reproduction(VC *population[], int size) {

}


static void GA::sort_population(VC *population[], int size) {
    //uses bubblesort -> go for quick sort and different sort algorithm later!

    if (size<=1) return;

        for (int i=1; i<size; i++) {
            if (*population[i]<*population[i-1]) {
                char buf = population[i];
                population[i] = population[i-1];
                population[i-1] = buf;
            }
        }
        bubblesort(list, length-1);
}
