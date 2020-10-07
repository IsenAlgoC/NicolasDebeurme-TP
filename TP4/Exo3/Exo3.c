#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 20


int main() {
	char nom[TAILLE],prenom[TAILLE],SEXE='N';
	int _getch(void);
	printf("Nom: ");
	scanf_s("%s", nom, _countof(nom));
	printf("Prenom: ");
	scanf_s("%s", prenom, _countof(prenom));
	printf("Sexe (Homme:H,Femme:F): ");
	SEXE=_getch();
	if (SEXE == 'H')
	{
		printf("\n Monsieur");
		printf(" %s %s", prenom, nom);
	}
	else {
		printf("\nMadame ");
		printf("%s %s", prenom, nom);
	}


	return(EXIT_SUCCESS);
}