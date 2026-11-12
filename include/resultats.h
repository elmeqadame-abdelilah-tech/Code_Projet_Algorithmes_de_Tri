#ifndef RESULTATS_H
#define RESULTATS_H

#include <stdio.h>  
// cest une representation d'un resultat de tris, avec le nombre d'elements et le temps pris par chaque algorithme de tri
typedef struct
{
    int n;
    double t_bulle;
    double t_insertion;
    double t_selection;
    double t_rapide;
    double t_fusion;
} ResultatsTris_1;

typedef struct
{
    int n;
    double t_rapide;
    double t_fusion;
} ResultatsTris_2;

int  ouvrir_fichiers_resultats(FILE **f_resultats_1, FILE **f_resultats_2);
void ecrire_resultats_tris_1(FILE *f, ResultatsTris_1 resultats);
void ecrire_resultats_tris_2(FILE *f, ResultatsTris_2 resultats);

#endif 
