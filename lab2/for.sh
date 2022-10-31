#! /bin/bash
# a program generating odd numbers from 1 to 10
i=1
for i in {1..10}
do
	if [ $((i%2)) -eq 1 ]
	then
	echo $i
fi
((i++))
done

