#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>

class GA
{
private:
    std::vector<std::vector<double> > domain;
    int radix;
    int countPopulation;
    int countGeneration;
    double probabilityMutation;
    double probabilityCrossover;
    double (*callback)(std::vector<double>);
    std::vector<std::string> population;
    size_t position;
    std::string initChromosome;
public:
    GA(double d[][2], size_t drow, int rdx = 0, int cp = 10, int cg = 100, double pm = 0.05, double pc = 0.2, double (*pf)(std::vector<double> a) = 0, std::string ic = "", size_t pos = 0);
    void generationChromosome(std::string &c);
    int random();
    double splitObject(std::string c, int n);
    void mutation();
    void crossover();
    double countSubChromosome(int i);
    int countChromosome();
    long int string2decimal(std::string c);
    double binary2decimal(std::string c, double a, double b);    
    std::vector<double> createArguments(std::string);
    std::vector<std::string> generationPopulation();
    void initDomain(double d[][2], size_t drow);
    void addDomain(double start, double end);
    void CountPopulation(int cp);
    int CountPopulation() const;
    void CountGeneration(int cg);
    int CountGeneration() const;
    void Radix(int rdx);
    int Radix() const;
    void ProbabilityMutation(double pm);
    double ProbabilityMutation() const;
    void ProbabilityCrossover(double pc);
    double ProbabilityCrossover() const;
    void CallbackFunction(double (*pf)(std::vector<double> a));
    void Position(size_t pos);
    size_t Position() const;
    void InitChromosome(std::string ic);
    std::string InitChromosome() const;
    int selectRandomIndex();
    void selection();
    std::vector<double> Probability();
    std::vector<double> CumulativeProbability();
    double eval();
    double maximumSignal();
    ~GA();
};
