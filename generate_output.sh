#!/bin/bash

#This is a comment

cd C-JuliaSets

make clean

make

./julia -2 2 -2 2 1000 1000 -1.037 0.17 > juliaset.csv

cd ..

cd Cpp-Mandelbrot

make clean

make

./mandelbrot -2 2 -2 2 1000 1000 > mandelbrot.csv



