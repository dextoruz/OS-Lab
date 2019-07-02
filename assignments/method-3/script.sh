#!/bin/bash

a=1
while [ $a -le 100000 ]
do
  gcc pi.c -o out && ./out $a
  a=`expr $a + 150`
done

awk 'function foo(x) {if(x < 0) return x = -1 * x; else return x;}{print $0,foo($4=$3-3.14159265358979311600)}' data.txt > temp.txt
awk '{print $0,$5=$4/3.14159265358979311600}' temp.txt > data.txt

a=1
echo "Step       Time          Abs-Err        Relative-Abs-Err " && echo '__________________________________________________' \
 && awk '{print $1,"\t|",$2,"\t|",$4,"\t|",$5,"\n"}' data.txt && echo '__________________________________________________'

gnuplot graph.gpl && xdg-open graph.png
gnuplot graph1.gpl && xdg-open graph1.png
rm data.txt 
