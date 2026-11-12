#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "donnees.h"

static int fichier_existe(const char *nom_fichier){
    FILE *f = fopen(nom_fichier, "r");
    if (f != NULL) {
        fclose(f);
        return 1;
    }
    return 0;
}

int generer_entiers_test(const char *nom_fichier, int n) {
    int precedent = 0;
    int i, val, choix_scenario;
    char reponse;
    if (fichier_existe(nom_fichier)) {
        printf("--> Le fichier %s existe deja.\n\tVoulez-vous le regenerer ? (o/n) : ", nom_fichier);
        scanf(" %c", &reponse);
        if (reponse != 'o' && reponse != 'O'){
            printf("--> Utilisation du fichier existant.\n");
            return 1;
        }
    }
    printf("--> Generation des entiers de test...\n");

    FILE *f = fopen(nom_fichier, "w");

    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nom_fichier);
        return 0;
    }

    // Initialisation de l'aléatoire
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        choix_scenario = rand() % 12;

        switch (choix_scenario) {
            case 0:
                val = (rand() % 2000001) - 1000000;
                break;
            case 1:
                val = rand() % 1000001;
                break;
            case 2:
                val = -(rand() % 1000001);
                break;
            case 3:
                val = precedent + (rand() % 21 - 10);
                break;
            case 4:
                val = rand() % 51;
                break;
            case 5:
                val = (rand() % 2000000001);
                break;
            case 6:
                val = precedent + (rand() % 20);
                break;
            case 7:
                val = precedent - (rand() % 20);
                break;
            case 8:
                val = precedent + (rand() % 5);
                if (rand() % 10 == 0) {
                    val -= rand() % 100;
                }
                break;
            case 9:
                if (i % 2 == 0)
                    val = rand() % 100;
                else
                    val = 1000000 - (rand() % 100);
                break;
            case 10:
                if (rand() % 5 == 0)
                    val = (rand() % 2001) - 1000;
                else
                    val = 0;
                break;
            case 11:
                val = (rand() % 11) - 5;
                break;
            default:
                val = 0;
                break;
        }
        fprintf(f, "%d\n", val);
        precedent = val;
    }
    fclose(f);
    printf("Fichier '%s' genere avec succes (%d entiers).\n", nom_fichier, n);
    return 1;   
}

int remplir_tableau(const char *nom_fichier, int *tab, int n) {
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nom_fichier);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(f, "%d", &tab[i]) != 1) {
            printf("Erreur lors de la lecture du fichier %s.\n", nom_fichier);
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;
}