#include "GA.h"

GA<class T>::GA(double scope[0][2], double (*pf)(std::vector<T> x),
	int population = 100, int generation = 1000,
	double pc = 0.2, double pm = 0.02): 
{
    srand(time(NULL));
}

GA<class T>::~GA() {}

void GA<class T>::init(std::string &c)
{
    for(int i = 0; i < c.length(); i++)
        c[i] = rand() % 2 + '0';
    return;
}

int GA<class T>::random(std::string c)
{
	return rand() % c.length();
}

void GA<class T>::mutation(std::string &c)
{
	int m = random(c);
	c[m] = c[m] == '0' ? '1' : '0';
	return;
}

void GA<class T>::crossover(std::string &c1, std::string &c2)
{
	int m = random(c1);
	std::string tc1 = c1.substr(m);
	std::string tc2 = c2.substr(m);
	c1.replace(m, c1.length() - m, tc2);
	c2.replace(m, c2.length() - m, tc1);
	return;
}

int GA<class T>::countCromosome(double c[], int radix, int n)
{
	double sum = 0;
	for(int j = 1; j <= n; j++)
		sum += population(c, radix, j);
	return (int)sum;
}

double GA<class T>::population(double c[], int radix, int i)
{
	return ceil(log((c[2*(i-1)+1] - c[2*(i-1)]) * pow(10.0, radix)) / log(2.0));
}

long int GA<class T>::bindec(std::string c)
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

double GA<class T>::splitObject(std::string c, double con[], int radix, int n)
{
	int ma = 0;
	for(int i = 1; i < n; i++)
		ma += population(con, radix, i);
	int mb = population(con, radix, n);
	return binreal(c.substr(ma, mb), con[2*(n-1)], con[2*(n-1)+1]);
}

double GA<class T>::binreal(std::string c, double a, double b)
{
	return a + bindec(c) * ( b - a ) / ( pow(2, c.length() ) - 1 );
}


/*
    double con[] = {-3.0,12.1,4.1,5.8};
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

*/