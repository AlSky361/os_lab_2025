#!/bin/bash
if [ $# -eq 0]; then
echo "Количество аргументов: 0"
echo "Среднее арифметическое: 0"
exit 0
fi

count=$#
sum=0

for num in "$@"; do
sum=$((sum+num))
done

avg=$(awk "BEGIN {printf \"%.2f\", $sum / $count}")

echo "Количество аргументов: $count"
echo "Среднее арифметическое: $avg"
