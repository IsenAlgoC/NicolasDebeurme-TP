#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Tab.h"
#define sizetab 10
#define TAILLEAJOUT 50


int initTab(int *tab, int size)
{
	if (tab != NULL && size > 0) {
		int i = 0;
		for (i = 0; i < size; i++)
			*(tab + i) = 0;
		return size;
	}
	else return EXIT_FAILURE;
}

int afficheTab(int* tab, int size, int nbElts)
{
	if (tab != NULL && size > 0 && size >= nbElts) {
		int i = 0;
		for (i = 0; i < nbElts; i++)
			printf(" %d ", *(tab + i));
		return 0;
	}
	else return EXIT_FAILURE;
}

int* ajoutElementDansTableau(int* tab, int *size, int *nbElts, int element)
{
	*nbElts = *nbElts + 1;
	if (*nbElts < *size) {
		*(tab + *nbElts-1) = element;
		
		return tab;
	}
	else {
		int* tabl = NULL;
		tabl= (int*)realloc(tab, *size+TAILLEAJOUT * sizeof(int));
		if (tabl == NULL) {
			printf("m�moire insuffisante");
			return NULL;
		}
		else {
			tab = tabl;
			*(tab + *nbElts-1) = element;
			*size = *size + TAILLEAJOUT;
			return  tab ;
		}
	}
}
