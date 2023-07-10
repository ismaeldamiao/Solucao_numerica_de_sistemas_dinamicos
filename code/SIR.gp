#!/usr/bin/env gnuplot

set term png size 1080, 720 font 'serif,24' enhanced;
set encoding utf8
set output 'SIR.png';
set grid;
set key box center right;
set title 'Modelo SIR';
set xlabel 'γ t';
set xrange [0:10]
set ylabel 'População percentual';
set yrange [0:1]
plot \
   'SIR.dat' u 1:2 w l lc rgb 'blue' t 'S', \
   'SIR.dat' u 1:3 w l lc rgb 'green' t 'I', \
   'SIR.dat' u 1:4 w l lc rgb 'red' t 'R';

exit
