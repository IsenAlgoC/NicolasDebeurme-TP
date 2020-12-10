#pragma once
#define TAILLEINIT 100 //Taille initiale tableau

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;

TABLEAU NewArray(TABLEAU tab);//Creation d'un nouveau tableu (initialisation)

int incrementArraySize(TABLEAU* tab, int incrementValue);//Augmentation de la taille du tableau

int setElement(TABLEAU* tab, int pos, int element);//Insertion d'un element dans le tableau et augmentation de la taille de celui ci si besoin.

int displayElements(TABLEAU* tab, int startPos, int endPos);//Affichage du tableau en partant de 'startpos' jusqu'a 'endPos'

int deleteElements(TABLEAU* tab, int startPos, int endPos);//Suppression d'un ou plusieurs élements et compression du tableau