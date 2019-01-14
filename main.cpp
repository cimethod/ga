#include <iostream>
//#include "GA.h"
#include <vector>
#include <cmath>

using namespace std;

double f(vector<double>);
double g(vector<int>);

int main()
{
    /* A Discerte 3D Equalation */
    GA *ga1 = new GA<double>({{-3.0, 12.1},{4.1, 5.8}}, f, 100, 1000, 0.2, 0.01);

    ga1->eval();

    /* 8-Queen */
    GA *ga2 = new GA<int>({{0,7},{0,7},{0,7},{0,7},{0,7},{0,7},{0,7},{0,7}}, g);
    ga2->population(500);
    ga2->pcrossover(0.2)
        ->pmitution(0.02)
        ->generation(1000); /* Also can use that member either chain or separatly */
    ga2->eval();

    ga2->population(1000); /* Being able to reset any member to use evalation */
    ga2->eval();
    return 0;
}

double f(vector<double> x)
{
    return 21.5 + x[0] * sin(4 * M_PI * x[0]) + x[1] * sin(20 * M_PI * x[1]);
}

double g(vector<int> x){
    int counter = 0;
    int moves = 24;
    for (int i = 0; i <= 7; i++) {
        // row
        for (int j = i + 1; j <= 7; j++) {
            if (x[j] == x[i]) {
                return counter / moves;
            }
        }
        counter++;
        // diognal
        for (int j = i + 1; j <= 7; j++) {
            if (x[j] == (x[i] + (j - i))) {
                return counter / moves;
            }
        }
        counter++;
        // inverse diognal
        for (int j = i + 1; j <= 7; j++) {
            if (x[j] == (x[i] - (j - i))) {
                return counter / moves;
            }
        }
        counter++;
    }
    return counter / moves;
}
