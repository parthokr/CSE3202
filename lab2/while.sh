#! /bin/bash
i=1
while [ $i -le 10 ]
do
	if [ $((i%2)) -eq 0 ]
	then
	echo $i
fi
((i++))
done
