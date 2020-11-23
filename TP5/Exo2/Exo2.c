#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Exo2.h"
#define incrsizetab 50 //valeur d'incrémentation (taille tableau)
#define pos 50  //position élément
#define element 16//element a ajouter
int main() {
	TABLEAU tableau;

	NewArray(tableau);

	incrementArraySize(&tableau, incrsizetab);

	setElement(&tableau, pos, element);

	displayElements(&tableau, 20, 60);


	deleteElements(&tableau, 20 , 60);

}
