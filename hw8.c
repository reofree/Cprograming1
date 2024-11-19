#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

double sd(double* numbers) {
    double ave, variance = 0;
    double sum = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        sum += numbers[i];
    }
    ave = sum / 5;

    for (i = 0; i < 5; i++)
    {
        variance += pow(numbers[i] - ave, 2);
    }
    variance /= 5;
    return sqrt(variance);
}


main() {
    double inputv[5];
    int i;
    printf("Enter 5 real numbers: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%lf", &inputv[i]);
    }
    double standard_deviation = sd(inputv);
    printf("\n%lf", standard_deviation);
}















