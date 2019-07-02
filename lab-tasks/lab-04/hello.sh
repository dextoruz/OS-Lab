#!/bin/bash

echo "enter the a val"
read a
echo "enter h value"
read b
c=`expr $a + $b`
echo "sum:"$c
c=`expr $a - $b`
echo "sub:"$c
c=`expr $a \* $b`
echo "mul:"$c
c=`expr $a / $b`
echo "div:"$c
num="1 2 3 4 5 6 7 8"
for n in $num
do
	q=`expr $n % 2`
	if [ $q -eq 0 ]
	then 
		echo "even no "
		continue
	fi
	echo "odd on"
done
