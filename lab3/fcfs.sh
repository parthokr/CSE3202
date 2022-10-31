#! /bin/bash
echo "Enter bt: "
read -a bt
# bt=($(printf '%s\n' "${bt[@]}" | sort -n))

# for t in ${bt[@]}
# do
# 	echo $t
# done
n=${#bt[@]}
n=$((n-1))
wt=(0 0 0 0 0 0 0 0)
# echo $n
for ((i=1;i<=$n;i++));
do
	wt[i]=$((bt[i-1]+wt[i-1]))
done
total=0
for t in ${wt[@]}
do
	# echo $t
	total=$((total+t))
done
# awt=$((total/3))
n=$((n+1))
echo "awt"
echo  "scale=3;$total/$n"|bc

