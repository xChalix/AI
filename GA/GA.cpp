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

static void GA::reproduction(VC *population, int size) {

}
