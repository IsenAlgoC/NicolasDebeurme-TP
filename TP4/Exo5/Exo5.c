#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAILLE 50

int main() {
	char phrase[TAILLE];
	int i = 0, taille = 0, nbmot = 0, longu = 0;
	float moy = 0, L = 0, n = 0;
	printf("Entrez une phrase: ");
	gets_s(phrase,50);
	taille = strlen(phrase);
	for ( i = 0; i <taille ; i++)
	{
		if (phrase[i] != ' ')
			longu++;
		else
		{
			nbmot++;
			L += longu;
			n++;
			longu = 0;
		}
	}

	printf("Nombre de mots: %d\n", nbmot);
	moy = L / n;
	printf("Longueur moyenne des mots: %.2f\n", moy);
	return(EXIT_SUCCESS);
}