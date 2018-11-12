@echo off
g++ -c GA.cpp
g++ -shared -o GA.dll GA.o -Wl,--out-implib,ga.a
g++ -c main.cpp
g++ -o main.exe main.o GA.dll