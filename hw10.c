#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

struct city
{
	char name[20];
	char country[40];
	int population;
};
void clearlinefromreadbuffer(void) {
	while (getchar() != '\n');
}
int main(void) {
	struct city cities[3];
	int i;
	printf("Input three cities\n");
	for (i = 0; i < 3; i++)
	{
		printf("Name> ");
		scanf_s("%[^\n]s", cities[i].name, (unsigned)_countof(cities[i].name));
		clearlinefromreadbuffer();
		printf("Country> ");
		scanf_s("%[^\n]s", cities[i].country, (unsigned)_countof(cities[i].country));
		clearlinefromreadbuffer();
		printf("Population> ");
		scanf_s("%d", &cities[i].population);
		clearlinefromreadbuffer();
	}
	
	for (i = 0; i < 3; i++)
	{
		printf("%d. %s in %s with a population of %d people\n", i + 1, cities[i].name, cities[i].country, cities[i].population);
	}
}