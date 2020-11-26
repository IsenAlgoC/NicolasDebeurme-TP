#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Exo2.h"
#define incrsizetab 50 //valeur d'incrémentation (taille tableau)
#define pos 160  //position élément a modifier
#define element 16//element a ajouter

int main() {
	TABLEAU tableau;
	tableau.elt = NULL;
	tableau.size = 0;
	tableau.eltsCount = 0;

	tableau=NewArray(tableau);

	for (int i = 0; i < tableau.size; i++)
	{
		*(tableau.elt + i) = i;
	}
	displayElements(&tableau, 1, tableau.size);

	incrementArraySize(&tableau, incrsizetab);
	printf("\nLe tableau est maintenant compose de %d cases. \n ", tableau.size);

	displayElements(&tableau, 1, tableau.size);

	setElement(&tableau, pos, element);
	printf("\nLe tableau est maintenant compose de %d cases. \n ", tableau.size);

	displayElements(&tableau, 1, tableau.size);

	deleteElements(&tableau, 20 , 60);
	printf("\nLe tableau est maintenant compose de %d cases. \n ", tableau.size);

	displayElements(&tableau, 1, tableau.size);

	free(tableau.elt);
	return(EXIT_SUCCESS);
}
