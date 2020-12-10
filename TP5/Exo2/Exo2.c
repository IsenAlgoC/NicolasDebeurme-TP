#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Exo2.h"
#define incrsizetab 50 //valeur d'incrémentation (taille tableau)
#define pos 160  //position élément a modifier
#define element 16//element a ajouter

int main() {
	TABLEAU tableau;//Initialisation de la structure
	tableau.elt = NULL;
	tableau.size = 0;
	tableau.eltsCount = 0;

	tableau=NewArray(tableau);//Initialisation du tableau

	for (int i = 0; i < tableau.size; i++) //On remplis le tableau completement
	{
		*(tableau.elt + i) = i;
	}
	displayElements(&tableau, 1, tableau.size);//Affichage

	incrementArraySize(&tableau, incrsizetab);//Augmente la taille du tableau de 50
	printf("\nLe tableau est maintenant compose de %d cases. \n ", tableau.size);

	displayElements(&tableau, 1, tableau.size);

	setElement(&tableau, pos, element);//On remplace le 160 eme élement par un '6'
	printf("\nLe tableau est maintenant compose de %d cases. \n ", tableau.size);

	displayElements(&tableau, 1, tableau.size);

	deleteElements(&tableau, 20 , 60);//On supprime tous les èlements entre le 20 ème et le 60 ème (tous les deux compris)
	printf("\nLe tableau est maintenant compose de %d cases. \n ", tableau.size);

	displayElements(&tableau, 1, tableau.size);

	free(tableau.elt);//On supprime l'allocation
	return(EXIT_SUCCESS);
}
