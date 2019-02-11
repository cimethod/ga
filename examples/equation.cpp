#include <iostream>
#include "../GA.h"

using namespace std;

double f(std::vector<double> x)
{
    return 21.5 + x[0] * sin(4 * M_PI * x[0]) + x[1] * sin(20 * M_PI * x[1]);
}

int main()
{
    double domain[][2] = {
        {-3.0,  12.1},
        {4.1,   5.8}
    };
    GA *ga = new GA(domain, 2,  /* range of domain */
        5,                      /* precision of decimal */
        400,                    /* count of population */
        100,                    /* count of generation */
        0.05,                   /* probability of mutation */
        0.2,                    /* probability of crossover */
    f                           /* function of problem */
    );
    cout << ga->eval() << endl; /* result by evalution */
    return 0;
}
