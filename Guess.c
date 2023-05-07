#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // inicjujemy generator liczb pseudolosowych
    int secret_number = rand() % 100 + 1; // losujemy liczbe z zakresu 1-100
    int guess;
    int num_guesses = 0;
    printf("Zgadnij liczbe z zakresu 1-100\n");

    do {
        printf("Podaj swoja propozycje: ");
        scanf("%d", &guess);
        num_guesses++;
        if (guess < secret_number) {
            printf("Za mala liczba\n");
        }
        else if (guess > secret_number) {
            printf("Za duza liczba\n");
        }
        else {
            printf("Gratulacje! Zgadles liczbe %d w %d probach.\n", secret_number, num_guesses);
        }
    } while (guess != secret_number);

    return 0;
}