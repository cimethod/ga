#include <iostream>
#include "../GA.h"

using namespace std;

double f(double x1, double x2)
{
    return 21.5 + x1 * sin(4 * M_PI * x1) + x2 * sin(20 * M_PI * x2);
}

int main()
{
    double domain[][2] = {
        {-3.0,  12.1},
        {4.1,   5.8}
    };
    GA *ga = new GA(domain, 2);
    ga->CountPopulation(1000);
    ga->Radix(6);
    ga->eval(f);
    return 0;
}
