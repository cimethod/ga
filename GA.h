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
public:
    GA(double d[][2], size_t drow, int rdx);
    ~GA(void);
    void addDomain(double start, double end);
    void init(std::string &c);
    int random(std::string c);
    double splitObject(std::string c, int n);
    void mutation(std::string &c);
    void crossover(std::string &c1, std::string &c2);
    double population(int i);
    int countCromosome();
    long int bindec(std::string c);
    double binreal(std::string c, double a, double b);
    void eval(double (*callback)(double, double));
};
