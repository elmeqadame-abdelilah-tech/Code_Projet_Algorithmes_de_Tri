#include <stdio.h>
#include <time.h>
#include "lancer.h"
#include "config.h"
#include "tris.h"
#include "tableaux.h"
#include "resultats.h"

typedef enum {BULLE, INSERTION, SELECTION, RAPIDE, FUSION} TypeTri;

static double tester_tri(const int *original, int *copie, int n, TypeTri type){

    copier_tableau(original, copie, n);

    clock_t debut = clock();
    switch (type){
        case BULLE:     tri_bulle(copie, n);
                        break;
        case INSERTION: tri_insertion(copie, n);
                        break;
        case SELECTION: tri_selection(copie, n);
                        break;
        case RAPIDE:    tri_rapide(copie, 0, n - 1);
                        break;
        case FUSION:    tri_fusion(copie, 0, n - 1);
                        break;
        default:
                        return -1.0;
    }
    double temps = (double)(clock() - debut) / CLOCKS_PER_SEC;

    if (!tableau_trie(copie, n)){
        printf("Erreur : le tri %d a produit un resultat incorrect pour n = %d.\n",
               type, n);
        return -1.0;
    }

    return temps;
}

static void mesurer_tris_2(const int *original, int *copie, int n, FILE *f){

    ResultatsTris_2 resultats;

    resultats.n        =            n;
    resultats.t_rapide =            tester_tri(original, copie, n, RAPIDE);
    resultats.t_fusion =            tester_tri(original, copie, n, FUSION);

    ecrire_resultats_tris_2(f, resultats);
}

static void mesurer_tris_1(const int *original, int *copie, int n, FILE *f){
    ResultatsTris_1 resultats;

    resultats.n                     = n;
    resultats.t_bulle               =tester_tri(original, copie, n, BULLE);
    resultats.t_insertion           =tester_tri(original, copie, n, INSERTION);
    resultats.t_selection           =tester_tri(original, copie, n, SELECTION);
    resultats.t_rapide              =tester_tri(original, copie, n, RAPIDE);
    resultats.t_fusion              =tester_tri(original, copie, n, FUSION);

    ecrire_resultats_tris_1(f, resultats);
}


void lancer_tris_1(const int *original, int *copie, FILE *f){
    int n;
    for (n = PAS_TRIS_1;n <= TAILLE_MAX_TRIS_1;n += PAS_TRIS_1){
        printf("--> Tris N 1: Mesure des tris pour n = %d\n", n);
        mesurer_tris_1(original, copie, n, f);
    }
}

void lancer_tris_2(const int *original, int *copie, FILE *f){
    int n;

    for (n = PAS_TRIS_2;n <= TAILLE_MAX_TRIS_2;n += PAS_TRIS_2){
        printf("--> Tris N 2: Mesure des tris pour n = %d\n", n);
        mesurer_tris_2(original, copie, n, f);
    }
}
