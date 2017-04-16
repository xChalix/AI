#include "GA.h"

GA::GA()
{

}


void GA::reproduction(VC *population[], int size) { //Tristan is currently working on this!!
    //at the moment: clones and mutates the best Creature onto the first empty space, then the second best Creature onto the second empty space, and so on
    //until all empty spaces are filled.

    sort_population(population,size); // sort population to push blank arrays towards the bottom of the array (size -1)

	int offset = 0;
	bool flag_offset = true;
	int empty = 0;

    for( int i = 0; i < size; i++) { //determines number of empty array values and offset
        if (population[i] == 0) {
			empty = empty + 1;
			if ( flag_offset ) {
				offset = i;
				flag_offset = false;
			}
		}
	}

    //note: population[n]->fitness for getting fitness value
	//note: assuming that fitness is sorted from highest to lowest	

    int i=0;//iterates through all valid objects, starting with the fittest
    for (int e=offset; e<size; e++) { //iterate through the empty places
        population[e] = population[i]->copy();
        population[e]->mutate();
        i++;
        if (i==offset) //if i reached the end, start again with the fittest object.
            i=0;
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
    //at the moment: cuts off the lower half of the population.
	
    sort_population(population,size);

    int offset = size/2;
    if (offset==0) offset=1; //ensures that at least 1 object is kept.
	
    for( int i = offset; i < size; i++ )
	{
        delete population[i];
        population[i]=0;
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
