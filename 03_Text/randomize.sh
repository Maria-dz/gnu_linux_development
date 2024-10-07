#!/bin/bash

declare -A matrix_x
declare -A matrix_y
declare -A matrix_ch
declare -A matrix_index


row=0
index_i=0

if [ -n "$1" ]; then
    sleep_time=$1
else
    sleep_time=0
fi

while  IFS= read -r line; do
  for (( i=0; i<${#line}; i++ )); do
  index_i=$((index_i + 1))
  matrix_index["$index_i"]="$index_i"
  matrix_x[$index_i]="$i"
  matrix_y["$index_i"]="$row"
  matrix_ch["$index_i"]="${line:$i:1}"
  done
  index_i=$((index_i + 1))
  matrix_x["$index_i"]="$i"
  matrix_y["$index_i"]="$row"
  matrix_ch["$index_i"]="${line:$i:1}"
  row=$((row + 1))
done


shuffled_matrix=$(echo "$matrix_index" | shuf)
tput clear
for index in "${!matrix_index[@]}"; do
    sleep $sleep_time
    tput cup "${matrix_y[$index]}" "${matrix_x[$index]}"
    printf "${matrix_ch[$index]}"
done

tput cup $row
