#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Tab.h"
#define sizetab 10//sizetab myTab1
#define nbElts 7//NB ELEMENTS myTab1
#define TAB2SIZE 19 //taille du tableau 2 ?

int main() {
	int myTab[sizetab],* myTab2 = NULL;
	int nbtab2 = 20,nbr=nbElts, i = 0,TAILLE= TAB2SIZE;//nbtab2=nbr de chiffre à écrire dans myTAB2

	initTab(&myTab, sizetab);// -DEBUT MYTAB1-
	printf("\nmyTab1: ");
	afficheTab(&myTab, sizetab, nbr); //Affiche les nbr premier chiffres de Mytab 
									  
									  //-FIN MY TAB1-
									  //-DEBUT MYTAB2 -
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));//Alloue l'espace demandé 

	if (myTab2 != NULL) 
		initTab(myTab2, sizetab); //Initialise MyTab2

	else {
		printf("mémoire insuffisante");
		return -1;
	}

	for ( i = 0; i <nbtab2; i++)
		*(myTab2 + i) = i + 1; //rempli le tableau de 1 à 20

	printf("\nmyTab2= ");
	afficheTab(myTab2, TAB2SIZE, nbtab2);//affiche mytab2

	myTab2=ajoutElementDansTableau(myTab2, &TAILLE, &nbtab2, 6);

	if (myTab2 == NULL) {
		printf("mémoire insuffisante");
	}
	else {
		printf("\nmyTab2 v2= ");
		afficheTab(myTab2, TAILLE, nbtab2);//Affivhe myTab2
	}
	free(myTab2);
									//-FIN MYTAB2-
	return EXIT_SUCCESS;
}