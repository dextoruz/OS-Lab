#!/bin/bash

a=1
while [ $a -lt 11 ]  #-ge -gt -le -eq -ne

	## [ $a -ne || -a $a -ne 12 ]
	## [ $a -ne 11 -o  $a -ne 12 ]

do 
	echo "$a"
	a=`expr $a + 1`
done
