#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Tab.h"
#define sizetab 10//sizetab myTab1
#define nbElts 7//NB ELEMENTS myTab1
#define TAB2SIZE 20 //taille du tableau 2 ?

int main() {
	int myTab[sizetab],* myTab2 = NULL;
	int nbr=nbElts, i = 0,TAILLE= 0;//TAILLE: taille du tableau 2

	initTab(&myTab, sizetab);// -DEBUT MYTAB1-
	printf("\nmyTab1: ");
	afficheTab(&myTab, sizetab, nbr); //Affiche les nbr premier chiffres de Mytab 
									  
									  //-FIN MY TAB1-
									  //-DEBUT MYTAB2 -
	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int));//Alloue l'espace demandé 

	if (myTab2 != NULL) 
		TAILLE=initTab(myTab2, TAB2SIZE); //Initialise MyTab2 avec des 0 et renvoie sa taille

	else {
		printf("mémoire insuffisante");
		return -1;
	}

	for ( i = 0; i <TAILLE; i++)
		*(myTab2 + i) = i + 1; //rempli le tableau 2 de 1 à 20 (donc completement rempli)
	int nbelts2 = TAILLE;//indique le nbre d'éléments dans myTab 2.

	printf("\nmyTab2= ");
	afficheTab(myTab2, TAILLE, nbelts2);//affiche mytab2

	int* test = NULL;
	if(ajoutElementDansTableau(myTab2, &TAILLE, &nbelts2, 6)!=NULL) //Ajoute 6 a la fin du tableau (besoin de l'agrandire car on dépasse la taille du tableau)
	{
		printf("\nmyTab2 v2= ");
		afficheTab(myTab2, TAILLE, nbelts2);//Affiche myTab2
	}

	free(myTab2); //destruction tableau myTab2
									//-FIN MYTAB2-
	return EXIT_SUCCESS;
}