#include <iostream>
#include "../Training.h"

using namespace std;

double f(std::vector<double> x) {
    double counter = 0;
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
    
    int sg[] = {400, 450, 500, 550, 600, 1000};
    double spc[] = {0.15, 0.2, 0.3, 0.4};
    double spm[] = {0.3, 0.02, 0.05, 0.1, 0.2};

    Training *t = new Training(domain, 8,
        sg, sizeof(sg) / sizeof(int),
        spc, sizeof(spc) / sizeof(double),
        spm, sizeof(spm) / sizeof(double)
    );
    t->CallbackFunction(f);
    t->eval();
    
    return 0;
}
