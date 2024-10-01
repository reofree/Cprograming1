#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int number, prime = 1;

    printf("Please enter a number: ");
    scanf("%d", &number);

    if (number <= 1) {
        prime = 0; 
    }
    else {
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                prime = 0; 
                break; 
            }
        }
    }

    if (prime) {
        printf("It is a prime number.\n");
    }
    else {
        printf("It is not a prime number.\n");
    }

    return 0;
}



















