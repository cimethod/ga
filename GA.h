#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>

class GA
{
    public:
    GA(void);
    ~GA(void);
    void init(std::string &c);
    int random(std::string c);
    double splitObject(std::string c, double con[], int radix, int n);
    void mutation(std::string &c);
    void crossover(std::string &c1, std::string &c2);
    double population(double c[], int radix, int i);
    int countCromosome(double c[], int radix, int n);
    long int bindec(std::string c);
    double binreal(std::string c, double a, double b);
};
