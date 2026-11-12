#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "donnees.h"
#include "tableaux.h"
#include "resultats.h"
#include "lancer.h"
#include "graphiques.h"

int main(void)
{
    int *tab_original = NULL;
    int *tab_copie = NULL;
    FILE *f_resultats_1 = NULL;
    FILE *f_resultats_2 = NULL;

    /* 1. Donnees */
    if (!generer_entiers_test(FICHIER_ENTIERS, TAILLE_MAX))
        return 1;

    /* 2. Allocation */
    if (!creer_tableaux(&tab_original, &tab_copie, TAILLE_MAX))
        return 1;

    /* 3. Fichiers de resultats */
    if (!ouvrir_fichiers_resultats(&f_resultats_1, &f_resultats_2)) {
        free(tab_original);
        free(tab_copie);
        return 1;
    }

    /* 4. Chargement */
    if (!remplir_tableau(FICHIER_ENTIERS, tab_original, TAILLE_MAX)) {
        fclose(f_resultats_1);
        fclose(f_resultats_2);
        free(tab_original);
        free(tab_copie);
        return 1;
    }

    /* 5. Mesures */
    lancer_tris_1(tab_original, tab_copie, f_resultats_1);
    lancer_tris_2(tab_original, tab_copie, f_resultats_2);

    /* 6. Fermeture + liberation */
    fclose(f_resultats_1);
    fclose(f_resultats_2);
    free(tab_original);
    free(tab_copie);

    /* 7. Graphiques */
    afficher_graphiques();

    return 0;
}