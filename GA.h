#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>

using namespace std;

class __declspec(dllexport) GA
{
    public:
    GA(void);
    ~GA(void);
    void init(string &c);
    int random(string c);
    double splitObject(string c, double con[], int radix, int n);
    void mutation(string &c);
    void crossover(string &c1, string &c2);
    double population(double c[], int radix, int i);
    int countCromosome(double c[], int radix, int n);
    long int bindec(string c);
    double binreal(string c, double a, double b);
};
