#include "GA.h"

GA::GA()
{

}


/*
*	Selects highest fitness VC objects (Virtual creatures) and zeroes out lower
*
*	param: VC *population
*		pointer to array of VC objects
*	param: int size
*		number of Virtual Creatures in the array of VC objects
*/
static void GA::selection(VC *population, int size) 
{
	
	sort(population,size);
	
	for( int i = 0; i < size; i++ )
	{
		
	}
	
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
