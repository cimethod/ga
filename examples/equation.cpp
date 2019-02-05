#include <iostream>
#include "../GA.h"

using namespace std;

double f(std::vector<double> x)
{
    cout << x[0] << " " << x[1] << endl;
    return 21.5 + x[0] * sin(4 * M_PI * x[0]) + x[1] * sin(20 * M_PI * x[1]);
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
    ga->CallbackFunction(f);
    ga->eval();
    return 0;
}
