set title "Comparaison des performances des algorithmes de tri"
set xlabel "Taille du tableau (n)"
set ylabel "Temps d'execution (secondes)"
set grid
set key left top

f = 'results/resultats_tris_1.dat'

# --- export PNG ---
set terminal pngcairo size 1200,800
set output 'results/resultats_1.png'
plot f using 1:2 with linespoints title 'Bulle', \
     f using 1:3 with linespoints title 'Insertion', \
     f using 1:4 with linespoints title 'Selection', \
     f using 1:5 with linespoints title 'Rapide', \
     f using 1:6 with linespoints title 'Fusion'

# --- affichage a l'ecran ---
unset output
if (GPVAL_SYSNAME[1:7] eq "Windows") {
    set terminal windows size 1200,800 enhanced font 'Verdana,10'
} else {
    set terminal qt size 1200,800
}
replot