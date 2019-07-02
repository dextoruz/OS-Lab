#!/bin/bash
add()
{
	c=`expr $1 + $2`
	echo "addition = $c"
}

add "$1" "$2"
