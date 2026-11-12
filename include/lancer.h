#ifndef LANCER_H
#define LANCER_H

#include <stdio.h> 

/* Serie 1 : 5 tris, n de PAS_TRIS_1 a TAILLE_MAX_TRIS_1 */
void lancer_tris_1(const int *original, int *copie, FILE *f);

/* Serie 2 : tri rapide et fusion, n de PAS_TRIS_2 a TAILLE_MAX_TRIS_2 */
void lancer_tris_2(const int *original, int *copie, FILE *f);

#endif 
