#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <vector>

class GA
{
private:
    std::vector<std::vector<double> > domain;
    int radix;
    int countPopulation;

    void init(std::string &c);
    int random(std::string c);
    double splitObject(std::string c, int n);
    void mutation(std::string &c);
    void crossover(std::string &c1, std::string &c2);
    double population(int i);
    int countCromosome();
    long int bindec(std::string c);
    double binreal(std::string c, double a, double b);    
public:
    GA(double d[][2], size_t drow, int rdx = 0, int cp = 0);
    void addDomain(double start, double end);
    void CountPopulation(int cp);
    int CountPopulation() const;
    void Radix(int rdx);
    int Radix() const;
    void eval(double (*callback)(double, double));
    ~GA();
};
