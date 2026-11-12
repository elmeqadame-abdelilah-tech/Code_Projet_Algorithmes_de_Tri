#ifndef DONNEES_H
#define DONNEES_H

int generer_entiers_test(const char *nom_fichier, int n);

/* Lit n entiers dans le fichier. Retourne 1 si OK, 0 sinon. */
int remplir_tableau(const char *nom_fichier, int *tab, int n);

#endif
