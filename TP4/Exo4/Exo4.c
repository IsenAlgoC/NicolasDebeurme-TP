#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define TAILLE 20

int main() {
	char mot[TAILLE], mot2[TAILLE]={0};
	int i = 0;

	printf("Mot: ");
	scanf_s("%s", mot, _countof(mot));
	int taille= strlen(mot);
	for ( i = 0; i <= taille; i++)
	{
		mot2[taille-i] = mot[i];
	}

	if (strcmp(mot, mot2) == 0) 
		printf("C'est un PALINDROME\n");
	else
		printf("Ce n'est pas un plalydrome..\n");



	return(EXIT_SUCCESS);
}