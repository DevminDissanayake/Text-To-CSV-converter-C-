#!/bin/bash
clear

gcc -c convert_to_csv.c read_csv.c main.c
gcc convert_to_csv.c read_csv.c main.c
./a.out

echo "Execution has ended successfully"
