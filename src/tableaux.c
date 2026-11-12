#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tableaux.h"

int creer_tableaux(int **tab_original, int **tab_copie, int n)
{
    *tab_original = malloc((size_t)n * sizeof(int));
    if (*tab_original == NULL) {
        printf("Erreur d'allocation du tableau original.\n");
        return 0;
    }
    *tab_copie = malloc((size_t)n * sizeof(int));
    if (*tab_copie == NULL) {
        printf("Erreur d'allocation du tableau copie.\n");
        free(*tab_original);
        *tab_original = NULL;
        return 0;
    }
    return 1;
}

void copier_tableau(const int *source, int *destination, int n)
{
    memcpy(destination, source, (size_t)n * sizeof(int));
}

int tableau_trie(const int *T, int n)
{
    for (int i = 0; i < n - 1; i++)
        if (T[i] > T[i + 1]) return 0;
    return 1;
}