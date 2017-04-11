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

}
