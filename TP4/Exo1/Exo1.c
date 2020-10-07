#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp4.h"

int main() {
	HEURE HeureDebut, HeureFin,Duree;
	HeureDebut.heure = 10;
	HeureDebut.minute = 30;
	Duree.heure = 0;
	Duree.minute = 45;
	HeureFin.minute = HeureDebut.minute + Duree.minute;
	if (HeureFin.minute > 60) {
		HeureFin.minute = HeureFin.minute % 60;
		HeureFin.heure = HeureDebut.heure + Duree.heure+1;
	}
	else HeureFin.heure = HeureDebut.heure+Duree.heure;

	printf("\nHeurefin= %d:%d\n", HeureFin.heure, HeureFin.minute);
	printf("\nHeuredebut= %d:%d\n", HeureDebut.heure, HeureDebut.minute);
	printf("\nDuree= %d:%d\n", Duree.heure, Duree.minute);

}
