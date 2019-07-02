#!/bin/bash
swap(){
	c="$a"
	a="$b"
	b="$c"
		
	
}
echo "value 1: "
read a
echo "value 2: "
read b
echo "$a $b"
swap a b

echo "$a $b"
