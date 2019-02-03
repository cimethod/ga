#include "GA.h"

GA::GA()
{
    srand(time(NULL));
}

GA::~GA() {}

void GA::init(string &c)
{
    for(int i = 0; i < c.length(); i++)
        c[i] = rand() % 2 + '0';
    return;
}

int GA::random(string c)
{
	return rand() % c.length();
}

void GA::mutation(string &c)
{
	int m = random(c);
	c[m] = c[m] == '0' ? '1' : '0';
	return;
}

void GA::crossover(string &c1, string &c2)
{
	int m = random(c1);
	string tc1 = c1.substr(m);
	string tc2 = c2.substr(m);
	c1.replace(m, c1.length() - m, tc2);
	c2.replace(m, c2.length() - m, tc1);
	return;
}

int GA::countCromosome(double c[], int radix, int n)
{
	double sum = 0;
	for(int j = 1; j <= n; j++)
		sum += population(c, radix, j);
	return (int)sum;
}

double GA::population(double c[], int radix, int i)
{
	return ceil(log((c[2*(i-1)+1] - c[2*(i-1)]) * pow(10.0, radix)) / log(2.0));
}

long int GA::bindec(string c)
{
	signed long p = c.length() - 1;
	long int dec = 0;
	while(p >= 0)
	{
		dec += ( c[p] - '0' ) * pow(2, c.length() - p - 1);
		p--;
	}
	return dec;
}

double GA::splitObject(string c, double con[], int radix, int n)
{
	int ma = 0;
	for(int i = 1; i < n; i++)
		ma += population(con, radix, i);
	int mb = population(con, radix, n);
	return binreal(c.substr(ma, mb), con[2*(n-1)], con[2*(n-1)+1]);
}

double GA::binreal(string c, double a, double b)
{
	return a + bindec(c) * ( b - a ) / ( pow(2, c.length() ) - 1 );
}
