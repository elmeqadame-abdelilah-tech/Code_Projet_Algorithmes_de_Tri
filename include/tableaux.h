#ifndef TABLEAUX_H
#define TABLEAUX_H

/* Alloue deux tableaux de n entiers. Retourne 1 si OK, 0 sinon. */
int  creer_tableaux(int **tab_original, int **tab_copie, int n);

/* Copie les n premiers elements de source dans destination. */
void copier_tableau(const int *source, int *destination, int n);

/* Retourne 1 si T[0..n-1] est trie par ordre croissant, 0 sinon. */
int  tableau_trie(const int *T, int n);

#endif 
