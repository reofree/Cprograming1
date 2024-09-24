#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	float km, miles;
	printf("Please enter kilometers: ");
	scanf(" %f", &km);
	miles = km * 0.621371;
	printf("%.1f km is equal to %.1f miles", km, miles);
}



















