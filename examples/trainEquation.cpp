#include <iostream>
#include "../Training.h"

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
    int sg[] = {400, 450, 500, 550, 600, 1000};
    double spc[] = {0.15, 0.2, 0.3, 0.4};
    double spm[] = {0.3, 0.02, 0.05, 0.1, 0.2};
    Training *t = new Training(domain, 2,
        sg, sizeof(sg) / sizeof(int),
        spc, sizeof(spc) / sizeof(double),
        spm, sizeof(spm) / sizeof(double)
    );
    t->CallbackFunction(f);
    t->evalTrain();
    return 0;
}
