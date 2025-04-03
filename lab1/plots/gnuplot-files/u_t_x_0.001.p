set terminal pngcairo size 900,900

set title "График зависимости u(t, x)"
set xlabel "x"
set ylabel "t"
set zlabel "u(t, x)"

set output "plots/pictures/u_t_x_0.001.png"
splot "plots/dat-files/u_t_x_0.001.dat" title "" with linespoints palette
