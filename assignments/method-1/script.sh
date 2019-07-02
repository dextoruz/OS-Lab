#!/bin/bash

gcc pi.c -o output.out
pi=3.14159265358979311600
i=1

echo "Enter STEPS(min-limit=5000 max-limit=1000000000): "
read var

while [ $i -le $var ]
do
  ./output.out $i
  i=`expr $i + 250`

done

awk -F ',' -v acos="$pi" 'function abs(v) {return ((v < 0) ? v*=-1 : v)}{print $1" "$2" "$3" ",abs($4=$3-acos)}' graph.csv > abs-er.txt
awk -v acos="$pi" '{print $1 "," $2 "," $3 "," $4 ",",$5=$4/acos}' abs-er.txt > graph.csv
rm abs-er.txt

echo "STEPS       Exe-Time          Abs-Err        Reltv-Abs-Err " && echo '--------------------------------------------------' \
 && awk -F ',' '{print $1,"|",$2,"|",$4,"|",$5,"\n"}' graph.csv && echo '--------------------------------------------------'

gnuplot execution-graph.gpl && xdg-open graph.eps
gnuplot error-graph.gpl && xdg-open graph1.eps
rm graph.csv
