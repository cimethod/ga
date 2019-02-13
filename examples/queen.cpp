#include <iostream>
#include "../Training.h"

using namespace std;

double f(std::vector<double> x) {
    int counter = 0;
    double moves = 24;
    for (int i = 0; i <= 7; i++) {
        /* row */
        for (int j = i + 1; j <= 7; j++)
            if (x[j] == x[i])
                return counter / moves;
        counter++;
        /* diognal */
        for (int j = i + 1; j <= 7; j++)
            if (x[j] == (x[i] + (j - i)))
                return counter / moves;
        counter++;
        /* inverse diognal */
        for (int j = i + 1; j <= 7; j++)
            if (x[j] == (x[i] - (j - i)))
                return counter / moves;
        counter++;
    }
    return counter / moves;
}

int main()
{
    double domain[][2] = {
        {0, 7}, {0, 7}, {0, 7}, {0, 7},
        {0, 7}, {0, 7}, {0, 7}, {0, 7}
    };
    
    GA *ga = new GA(domain, 8,  /* range of domain */
        0,                      /* precision of decimal */
        400,                    /* count of population */
        100,                    /* count of generation */
        0.05,                   /* probability of mutation */
        0.2,                    /* probability of crossover */
        f                       /* function of problem */
    );

    int generations[] = {400, 450, 500, 550, 600, 1000};
    double pc[] = {0.15, 0.2, 0.3, 0.4};
    double pm[] = {0.3, 0.02, 0.05, 0.1, 0.2};

    Training *t = new Training(domain, 8,
        generations, sizeof(generations) / sizeof(int),
        pc, sizeof(pc) / sizeof(double),
        pm, sizeof(pm) / sizeof(double)
    );
    t->evalTrain();
    
    return 0;
}
