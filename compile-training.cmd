@echo off
g++ -c GA.cpp Training.cpp examples/%1.cpp
g++ -o %1.exe GA.o Training.o %1.o
del *.o
