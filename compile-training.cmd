@echo off
g++ -c GA.cpp Training.cpp examples/trainEquation.cpp
g++ -o trainEquation.exe GA.o Training.o trainEquation.o
del *.o
