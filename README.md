# GA Library

## Introduction
The most of problems are regarding world of industrial engineering specially productive system, complex and absolute difference for solving by techniques common techniques of optimization. The interest of instance creates industrial industry of optimization on life of creatures for solving of the most kind of problem and increasing time lapse. The simulation of natrul evolution process becomes for alive creatures leading to the stochastic optimization of techniques which it is called by evolution algorithm. These can support the common optimization of methods while using on the different real problems. Genetic algorithm is to be able to say the most famous evolution algorithms.

It allows to developer using genetic algorithm library writes solution of problem in methods of optimization on the most different conjunctive and discrete problems.

## Features
### Three operators
Three operators called by mutation, crossover and initial sub-chromosome which the latest word is new operator at GA.
### Ease to use
It allows to use custom functions and routes what you want to do like changing and modyfing initial domain to forecast what will be to do. It also has tutorial to learn how to work and doing GA. For more further, click [api cimethod](http://api.cimethod.com/) link.
### Use to application
It presetns to real problem and better solutions to solving problems like game design and the formal software application.

## How to use
This library must include to your code and running it to see how give its result, so checkout it. For example this is 3D equation which we want to find its maximum. Following for solving this problem:
```C++
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
```
This code is [here](https://github.com/cimethod/ga/blob/master/examples/equation.cpp) and training code is [here](https://github.com/cimethod/ga/blob/master/examples/trainEquation.cpp) to performance up what you choice count of generation, probability of crossover or mutation to do better.

If you use g++ compiler you can add batch file to compile faster.
```bash
@echo off
g++ -c GA.cpp examples/equation.cpp
g++ -o equation.exe GA.o equation.o
del *.o
```
Also a batch file for training mode is [here](https://github.com/cimethod/ga/blob/master/compile-training.cmd)

# Training framework
This module is inheritance of GA Library and how know being the best factories of genetic such as count of generation, probability of mutation and crossover or manipulation of crossover.

Training uses more in hard problem not knowing what paramaters of genetic mentioned in upper. [8-Queen Problem](https://github.com/cimethod/ga/blob/master/examples/queen.cpp) is one of those we said. You can use Traning framework that whole of possible values you think and you run that problem and watching which parameters act better.

For more further information click [API Documentation](http://api.cimethod.com/) link.
