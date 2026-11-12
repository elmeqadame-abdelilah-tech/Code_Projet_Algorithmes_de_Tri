#ifndef CONFIG_H
#define CONFIG_H

#define TAILLE_MAX          10000000 // 10 millions d'entiers

#define TAILLE_MAX_TRIS_1   100000 //taille maximale pour les tris 1 (bulle, insertion, selection, rapide, fusion)
#define PAS_TRIS_1          10000

#define TAILLE_MAX_TRIS_2   10000000 //taille maximale pour les tris 2 (rapide, fusion)
#define PAS_TRIS_2          500000
//cest juste des nom pour les chemins des fichiers de resultats et des scripts gnuplot, pour que ce soit plus facile a changer si besoin
#define FICHIER_ENTIERS      "data/les_entiers.bin"
#define FICHIER_RESULTATS_1  "results/resultats_tris_1.dat"
#define FICHIER_RESULTATS_2  "results/resultats_tris_2.dat"
#define SCRIPT_GRAPHE_1      "graphs/graphe_1.gp"
#define SCRIPT_GRAPHE_2      "graphs/graphe_2.gp"

#endif
