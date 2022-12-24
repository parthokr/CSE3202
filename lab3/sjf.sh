#! /bin/bash
echo "Enter burst times (separated by whitespace): "
read -a bt
bt=($(printf '%s\n' "${bt[@]}" | sort -n))
n=${#bt[@]}
n=$((n-1))
wt=$bt
wt[0]=0
for ((i=1;i<=$n;i++));
do
	wt[i]=$((bt[i-1]+wt[i-1]))
done
total=0
for t in ${wt[@]}
do
	total=$((total+t))
done
n=$((n+1))
echo -n "AWT: "
echo "scale=3;$total/$n"|bc


