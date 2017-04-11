#include "GA.h"

GA::GA()
{

}


static void GA::reproduction(VC *population, int size) { //Tristan is currently working on this!!

	sort(population,size); // sort population to push blank arrays towards the bottom of the array (size -1)

	int offset = 0;
	bool flag_offset = true;
	int empty = 0;

	for( int i = 0; i < size; i = i + 1) { //determines number of empty array values and offset
		if (population[i] = 0) {
			empty = empty + 1;
			if ( flag_offset ) {
				offset = i;
				flag_offset = false;
			}
		}
	}

	//note: population[n].fitness for getting fitness value
	//note: assuming that fitness is sorted from highest to lowest	

	for( int i = 0; i < size; i = i + 1) {

		


		if ( empty > 0 ) {
			//copy(population[i], i + offset);
			population[i+offset] = population[i]->copy();
			//mutate(population[i + offset]);
			population[i+offset]->mutate();
			empty = empty - 1;
		} else {
			break;
		}
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
