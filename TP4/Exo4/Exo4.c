#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define TAILLE 20

int main() {
	char mot[TAILLE];
	int i = 0;
	mot[0] = 0;
	printf("Mot: ");
	scanf_s("%s", mot, _countof(mot));
	int taille= strlen(mot);
	taille;
	for ( i = 0; i < taille/2; i++)
	{
		if (mot[taille - i] == mot[i])
			;
		else
		{
			printf("Ce n'est pas un palindrome..\n");
			break;
		}
	} 
		printf("C'est un PALINDROME\n");



	return(EXIT_SUCCESS);
}