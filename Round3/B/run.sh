#!/bin/bash

g++ -O3 -std=c++17 -Wall -Wextra -pedantic -o solve solve.cpp

./solve < input.txt > output.txt

cat output.txt
