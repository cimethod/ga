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
    double probabilityMutation;
    double probabilityCrossover;
    double (*callback)(std::vector<double>);
    std::vector<std::string> population;

    void generationChromosome(std::string &c);
    int random(std::string c);
    double splitObject(std::string c, int n);
    void mutation(std::string &c);
    void crossover(std::string &c1, std::string &c2);
    double countSubChromosome(int i);
    int countCromosome();
    long int string2decimal(std::string c);
    double binary2decimal(std::string c, double a, double b);    
    std::vector<double> createArguments(std::string);
    void generationPopulation();
public:
    GA(double d[][2], size_t drow, int rdx = 0, int cp = 0, double pm = 0.05, double pc = 0.2, double (*pf)(std::vector<double> a) = 0);
    void initDomain(double d[][2], size_t drow);
    void addDomain(double start, double end);
    void CountPopulation(int cp);
    int CountPopulation() const;
    void Radix(int rdx);
    int Radix() const;
    void ProbabilityMutation(double pm);
    double ProbabilityMutation() const;
    void ProbabilityCrossover(double pc);
    double ProbabilityCrossover() const;
    void CallbackFunction(double (*pf)(std::vector<double> a));
    void eval();
    ~GA();
};
