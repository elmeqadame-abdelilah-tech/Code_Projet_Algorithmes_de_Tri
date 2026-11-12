#include <stdio.h>
#include "resultats.h"
#include "config.h"

int ouvrir_fichiers_resultats(FILE **f_resultats_1, FILE **f_resultats_2) {
    *f_resultats_1 = fopen(FICHIER_RESULTATS_1, "w");
    if (*f_resultats_1 == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", FICHIER_RESULTATS_1);
        return 0;
    }

    *f_resultats_2 = fopen(FICHIER_RESULTATS_2, "w");
    if (*f_resultats_2 == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", FICHIER_RESULTATS_2);
        fclose(*f_resultats_1);
        return 0;
    }
    return 1;
}

void ecrire_resultats_tris_1(FILE *f, ResultatsTris_1 resultats){

    fprintf(f, "%d %f %f %f %f %f\n", resultats.n, resultats.t_bulle, resultats.t_insertion, resultats.t_selection, resultats.t_rapide, resultats.t_fusion);
}

void ecrire_resultats_tris_2(FILE *f, ResultatsTris_2 resultats){
    fprintf(f, "%d %f %f\n", resultats.n, resultats.t_rapide, resultats.t_fusion);
}
