#include <stdlib.h>
#include "graphiques.h"
#include "config.h"

void afficher_graphiques(void)
{
#ifdef _WIN32
    system("start gnuplot -persist " SCRIPT_GRAPHE_1);
    system("start gnuplot -persist " SCRIPT_GRAPHE_2);
#else
    system("gnuplot -persist " SCRIPT_GRAPHE_1 " &");
    system("gnuplot -persist " SCRIPT_GRAPHE_2 " &");
#endif
}