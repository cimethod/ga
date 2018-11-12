#include <iostream>
#include "GA.h"

using namespace std;

double f(double x1, double x2)
{
    return 21.5 + x1 * sin(4 * M_PI * x1) + x2 * sin(20 * M_PI * x2);
}

int main()
{
    double con[] = {-3.0,12.1,4.1,5.8};
    GA ga;
    int cc = ga.countCromosome(con, 5, sizeof(con) / ( 2 * sizeof(double)));
    printf("%d\n", cc);
    for(int i = 1; i <= 100; i++)
    {
        string s(cc, '0');
        ga.init(s);
        double x1 = ga.splitObject(s, con, 5, 1);
        double x2 = ga.splitObject(s, con, 5, 2);
        printf("f(%f,%f)=%f\n", x1, x2, f(x1, x2));
    }
    return 0;
}
