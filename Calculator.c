#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double var1, var2, wynik;
	char znak;

	printf("Kalkulator\n");
	printf("Podaj liczbe: ");
	scanf("%lf", &var1);
	printf("Podaj znak: ");
	scanf(" %c", &znak);
	printf("Podaj liczbe: ");
	scanf("%lf", &var2);

	switch (znak)
	{
		case '+': wynik = var1 + var2; break;
		case '-': wynik = var1 - var2; break;
		case '*': wynik = var1 * var2; break;
		case '/': wynik = var1 / var2; break;
	}
	printf("Wynik: %.2lf", wynik);

	return 0;
}