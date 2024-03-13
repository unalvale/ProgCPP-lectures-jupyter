set term pdf
set out "plot.pdf"
set log x
set log y
plot 'datos.txt' u 1:2 w lp t 'f', '' u 1:3 w lp t 'c' , '' u 1:4 w lp t 'rf', '' u 1:5  w lp t 'rc' 
