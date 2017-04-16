#include "GA.h"

GA::GA()
{

}


void GA::reproduction(VC *population[], int size) { //Tristan is currently working on this!!

//	sort(population,size); // sort population to push blank arrays towards the bottom of the array (size -1)

	int offset = 0;
	bool flag_offset = true;
	int empty = 0;

	for( int i = 0; i < size; i = i + 1) { //determines number of empty array values and offset
        if (population[i] == 0) {
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
}

/*
*	Selects highest fitness VC objects (Virtual creatures) and zeroes out lower
*
*	param: VC *population
*		pointer to array of VC objects
*	param: int size
*		number of Virtual Creatures in the array of VC objects
*/
void GA::selection(VC *population[], int size)
{
	
//	sort(population,size);
	
	for( int i = 0; i < size; i++ )
	{
		
	}
	
}




void GA::sort_population(VC *population[], int size) {
    //uses bubblesort -> go for quick sort and different sort algorithm later!

    if (size<=1) return;

    for (int i=1; i<size; i++) {
        //consider that an object could be NULL in this comparison:
        if
        (
            population[i-1]==0                      //if [i-1] is 0, then it is considered as smaller as [i] -> do the swap
            || (population[i]!=0                    //only if [i] exists, it can be larger
                && *population[i]>*population[i-1]) //do the comparison
        )
        {
            VC* buf = population[i];
            population[i] = population[i-1];
            population[i-1] = buf;
        }
    }
    sort_population(population, size-1);

}
