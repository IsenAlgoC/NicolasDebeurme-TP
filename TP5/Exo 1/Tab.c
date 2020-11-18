#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "Tab.h"
#define sizetab 10


int main (){
	int myTab[sizetab] = NULL;

	initTab(&myTab, sizetab);

}

int initTab(int *tab, int size)
{
	if (tab != NULL && size > 0) {
		int i = 0;
		for (i = 0; i < size; i++)
			*(tab + i) = 0;
		return size;
	}
	else return -1;
}
