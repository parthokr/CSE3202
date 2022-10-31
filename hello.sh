#!/bin/bash

VAR1="Linuxize"
VAR2="Ubuntu"

if [[ "$VAR1" > "$VAR2" ]]; then
    echo "${VAR1} is lexicographically greater then ${VAR2}."
elif [[ "$VAR1" < "$VAR2" ]]; then
    echo "${VAR2} is lexicographically greater than ${VAR1}."
else
    echo "Strings are equal"
fi
