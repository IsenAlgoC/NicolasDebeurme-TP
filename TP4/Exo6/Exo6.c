#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 100

int main() {
	int* pointeur, nb = 0, tab[taille] = { 0 }, i = 0, N = 0,Nb=0;
	pointeur = &tab[0];
	for ( i = 0; i < taille; i++)
	{
		tab[i] = rand() % 21;
	}
	printf("Entrez la valeur recherchee: ");
	scanf_s("%d", &N);
	printf("La valeur %d a ete trouvee en", N);
	i = 0;
	do {
		if (*pointeur == N && Nb == 0){
			printf(" %d", i);
			Nb++;}
		else {
			if (*pointeur == N) {
				printf(",puis en %d", i);
			}
			else
				printf("La valeur que vous avez demandé n'a pas ete trouvee.");
		}
		i++;
		pointeur++;
	} while (i<taille);
	printf(".");

}