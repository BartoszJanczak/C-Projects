#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE* file;
    char filename[100];
    char c;
    int num_chars = 0, num_words = 0, num_lines = 0, in_word = 0, num_whitespace = 0;;

    printf("Podaj nazwe pliku: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Nie udalo sie otworzyc pliku.\n");
        exit(1);
    }

    while ((c = fgetc(file)) != EOF)
    {
        num_chars++;

        if (c == '\n')
        {
            num_lines++;
        }

        if (isspace((unsigned char)c))
        {
            num_whitespace++;
            if (in_word)
            {
                num_words++;
                in_word = 0;
            }
        }
        else
        {
            in_word = 1;
        }
    }

    if (in_word)
    {
        num_words++;
    }

    printf("Liczba znakow (bez spacji): %d\n", num_chars - num_whitespace);
    printf("Liczba slow: %d\n", num_words);
    printf("Liczba linii: %d\n", num_lines + 1);

    fclose(file);

    return 0;
}