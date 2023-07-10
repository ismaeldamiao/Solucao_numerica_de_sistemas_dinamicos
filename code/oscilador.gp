#!/usr/bin/env gnuplot

set term png size 1080, 720 font 'serif,24' enhanced;
set encoding utf8
set output 'oscilador.png';
set grid;
set key off;
set title 'Oscilador vertical amortecido';
set xlabel 'ω t';
set xrange [0:10]
set ylabel '-k / mg  y';
plot 'oscilador.dat' u 1:2 w l lc rgb 'black'

set output 'oscilador_PS.png';
unset xrange;
set xlabel 'Q';
set ylabel 'P';
plot 'oscilador.dat' u 2:3 w l lc rgb 'black'

exit
