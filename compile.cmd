@echo off
g++ -c GA.cpp examples/%1.cpp
g++ -o %1.exe GA.o %1.o
del *.o
