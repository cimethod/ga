@echo off
g++ -c GA.cpp examples/equation.cpp
g++ -o equation.exe GA.o equation.o
del *.o
