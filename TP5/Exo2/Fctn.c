#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Exo2.h"


TABLEAU NewArray(TABLEAU tab) {
	tab.elt = (int*)malloc(TAILLEINIT * sizeof(int));
	tab.size = TAILLEINIT;
	tab.eltsCount = 0;

	if (tab.elt != NULL && tab.size > 0) {
		int i = 0;
		for (i = 0; i < tab.size; i++)
			*(tab.elt + i) = 0;
		return tab;
	}
	else {
		tab.elt = NULL;
		return tab;
	}
}

int incrementArraySize(TABLEAU* tab, int incrementValue)
{
		int* tabl = NULL;
		tabl=(int*)realloc(tab->elt, tab->size + incrementValue * sizeof(int));

		if (tabl == NULL) {
			printf("mémoire insuffisante");
			return -1;
		}

		else {
			tab->elt = tabl;
			tab->size = tab->size + incrementValue;
			return  tab->size;
		}
}

int setElement(TABLEAU* tab, int pos, int element)
{
	int taille = tab->size;
	if (pos <= tab->size) {
		*(tab->elt + pos+1) = element;
		tab->eltsCount = tab->eltsCount + 1;
		return pos;
	}
	else {
		if (incrementArraySize(&tab, pos - tab->size)== -1) //Verifie que la relocalisation se passe bien
			return 0;
		else {
			for (int i = 0; i < (pos-1); i++)
				*(tab->elt + taille + i)=0;

			*(tab->elt + taille + pos - 1) = element; //écrit l'élement
			tab->eltsCount = tab->eltsCount + 1;
			return pos;
		}
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos > 0 && endPos <= tab->size) {
		if (startPos >= endPos) {
			for (int i = startPos; i >= endPos; i--) {
				printf("%d ", *(tab->elt + i - 1));
				return 0;
			}
		}
		else {
			for (int i = startPos; i <= endPos; i++) {
				printf("%d", *(tab->elt + i - 1));
				return 0;
			}
		}
	}
	else
	return -1;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos > 0 && endPos <= tab->size) {
		if (startPos > endPos) {
			int ecart = startPos - endPos;
			for (int i = endPos; i < tab->size-ecart; i++) {
				*(tab->elt +i-1)=*(tab->elt+i+ecart);
				tab->size = tab->size - ecart - 1;
				return tab->size;
			}
		}
		if (startPos < endPos) {
			int ecart = endPos-startPos;
			for (int i = startPos; i < tab->size - ecart; i++) {
				*(tab->elt + i - 1) = *(tab->elt + i + ecart);
				tab->size = tab->size - ecart - 1;
				return tab->size;
			}
		}
		if(startPos==endPos){
			for (int i = startPos; i < tab->size; i++) {
				*(tab->elt + i - 1)=*(tab->elt+i);
				tab->size = tab->size - 1;
				return tab->size;
			}
		}
	}
	else
		return -1;
}
