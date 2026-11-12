set title "Tri rapide vs tri fusion"
set xlabel "Taille du tableau (n)"
set ylabel "Temps d'execution (secondes)"
set grid
set key left top

f = 'results/resultats_tris_2.dat'

set terminal pngcairo size 1200,800
set output 'results/resultats_2.png'
plot f using 1:2 with lines title 'Rapide', \
     f using 1:3 with lines title 'Fusion'

unset output
if (GPVAL_SYSNAME[1:7] eq "Windows") {
    set terminal windows size 1200,800 enhanced font 'Verdana,10'
} else {
    set terminal qt size 1200,800
}
replot