#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tris.h"

#define SEUIL 24   /* en dessous, tri par insertion */

static void permuter(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Tri par insertion sur T[g..d] (sert aussi aux petits segments). */
static void insertion_plage(int T[], int g, int d)
{
    for (int i = g + 1; i <= d; i++) {
        int valeur = T[i];
        int j = i - 1;
        while (j >= g && T[j] > valeur) {
            T[j + 1] = T[j];
            j--;
        }
        T[j + 1] = valeur;
    }
}

void tri_bulle(int T[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int echange = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] > T[j + 1]) {
                permuter(&T[j], &T[j + 1]);
                echange = 1;
            }
        }
        if (!echange) break;
    }
}

void tri_selection(int T[], int n){
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (T[j] < T[min]) min = j;
        if (min != i) permuter(&T[i], &T[min]);
    }
}

void tri_insertion(int T[], int n)
{
    insertion_plage(T, 0, n - 1);
}

/* Tri rapide : pivot = mediane de trois, insertion sur petits segments,
   recursion sur la plus petite partie (profondeur de pile en O(log n)). */
void tri_rapide(int T[], int gauche, int droite)
{
    while (droite - gauche >= SEUIL) {
        int milieu = gauche + (droite - gauche) / 2;
        int i = gauche, j = droite, pivot;

        if (T[milieu] < T[gauche])  permuter(&T[milieu], &T[gauche]);
        if (T[droite] < T[gauche])  permuter(&T[droite], &T[gauche]);
        if (T[droite] < T[milieu])  permuter(&T[droite], &T[milieu]);
        pivot = T[milieu];

        while (i <= j) {
            while (T[i] < pivot) i++;
            while (T[j] > pivot) j--;
            if (i <= j) {
                permuter(&T[i], &T[j]);
                i++;
                j--;
            }
        }
        if (j - gauche < droite - i) {
            tri_rapide(T, gauche, j);
            gauche = i;
        } else {
            tri_rapide(T, i, droite);
            droite = j;
        }
    }
    insertion_plage(T, gauche, droite);
}

/* Fusion : seule la moitie gauche est copiee dans tmp. */
static void fusion_rec(int T[], int tmp[], int g, int d)
{
    int m, nl, i, j, k;

    if (d - g < SEUIL) {
        insertion_plage(T, g, d);
        return;
    }
    m = g + (d - g) / 2;
    fusion_rec(T, tmp, g, m);
    fusion_rec(T, tmp, m + 1, d);

    if (T[m] <= T[m + 1]) return;   /* deja ordonne */

    nl = m - g + 1;
    memcpy(tmp, T + g, (size_t)nl * sizeof(int));
    i = 0; j = m + 1; k = g;
    while (i < nl && j <= d)
        T[k++] = (tmp[i] <= T[j]) ? tmp[i++] : T[j++];
    while (i < nl)
        T[k++] = tmp[i++];
    /* le reste de la moitie droite est deja a sa place */
}

void tri_fusion(int T[], int gauche, int droite)
{
    int *tmp;
    if (gauche >= droite) return;

    tmp = malloc((size_t)((droite - gauche) / 2 + 2) * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "Erreur d'allocation memoire dans tri_fusion.\n");
        exit(EXIT_FAILURE);
    }
    fusion_rec(T, tmp, gauche, droite);
    free(tmp);
}