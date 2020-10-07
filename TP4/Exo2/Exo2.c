#include <stdio.h>
#include <math.h>
#define SEPARATEUR '/' 
#define TAILLETAB1 20

int main() {
	int MyTab1[TAILLETAB1],i=0,*Myptr1;

	for ( i = 0; i < 20; i++)
	{
		MyTab1[i] = i + 1;
		printf(" %d %c", MyTab1[i], SEPARATEUR);
	}
	Myptr1 = &MyTab1[19];
	printf("\n");
	for ( i = 0; i < 20; i++)
	{
		printf(" %d %c", *Myptr1,SEPARATEUR);
		Myptr1--;
	}
}