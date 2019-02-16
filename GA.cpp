#include "GA.h"

/**
 * A kind of constructor of GA object
 * @param d[][2]	A set of domains what it is needed
 * @param drow		Row of domains
 * @param rdx		Optional, Decimal precision
 * @param cp		Optional, Count of population
 * @param pm		Optional, Probability of mutation
 * @param pc		Optional, Probability of crossover
 * @param (*pf)		Optional, Callback function fittness
 * @param ic		Optional, Manipulating initial sub-chromosome
 * @param pos		Optional, Position of initial sub-chromosome where it is
 * @see CountPopulation
 */
GA::GA(double d[][2], size_t drow, int rdx, int cp, int cg, double pm, double pc, double (*pf)(std::vector<double> a), std::string ic, size_t pos)
{
	srand(time(NULL));

	Radix(rdx);
	CountPopulation(cp);
	CountGeneration(cg);
	ProbabilityMutation(pm);
	ProbabilityCrossover(pc);
	CallbackFunction(pf);
	initDomain(d, drow);
}

/**
 * Inserting initial domain at constructor
 * @param d[][2]	Range of domain Nx2
 * @param drow		Value of domain row
 */
void GA::initDomain(double d[][2], size_t drow){
	for(int i = 0; i < drow; i++)
		addDomain(d[i][0], d[i][1]);
}

/**
 * Setting of count population where it is not assign at constructor
 * @param cp	A value of count population
 * @return void
 */
void GA::CountPopulation(int cp){
	countPopulation = cp;
	return;
}

/**
 * Getting of count population where it is needed
 * @return Count of population
 */
int GA::CountPopulation() const {
	return countPopulation;
}

/**
 * Setting value of count of generation to refresh evaluation
 * @param cg	Count of generation
 * @see eval()
 */
void GA::CountGeneration(int cg) {
	countGeneration = cg;
}

/**
 * Getting count of generation where you neccesary
 */
int GA::CountGeneration() const {
	return countGeneration;
}

/**
 * Setting of value of decimal pricision
 * @param rdx	A value of decimal pricision
 * @return void
 */
void GA::Radix(int rdx){
	radix = rdx;
	return;
}

/**
 * Getting of value of decimal pricision
 * @return a value of decimal pricision
 */
int GA::Radix() const {
	return radix;
}

/**
 * Setting of value demonstrates level of probability of mutation
 * @param pm value of probability of mutation
 * @return void
 */
void GA::ProbabilityMutation(double pm){
	probabilityMutation = pm;
	return;
}

/**
 * Getting of value what it is
 * @return A value of probability of mutation
 */
double GA::ProbabilityMutation() const {
	return probabilityMutation;
}

/**
 * Setting value of probability of crossover level
 * @param pc value of probability
 * @return void
 */
void GA::ProbabilityCrossover(double pc){
	probabilityCrossover = pc;
	return;
}

/**
 * Getting value of probability of crossover level
 * @return value of probability of crossover
 */
double GA::ProbabilityCrossover() const {
	return probabilityCrossover;
}

/**
 * Seeting logical function for fittness
 * @param (*pf)	a logical function. it is ought to be have an argument of std::vector<double> that each of inputs are in it.
 */
void GA::CallbackFunction(double (*pf)(std::vector<double> a)){
	callback = pf;
	return;
}

/**
 * Appending range from start of domain to end of domain
 * @param start	A value that is lesser than end
 * @param end	A value of end of domain
 * @return void
 */
void GA::addDomain(double start, double end)
{
	std::vector<double> sd;
	sd.push_back(start);
	sd.push_back(end);
	domain.push_back(sd);
}

/**
 * Create generation of chromosome stochasticly
 * @param c		empty string to generate chromosme
 */
void GA::generationChromosome(std::string &c)
{
    for(int i = 0; i < c.length(); i++)
        c[i] = rand() % 2 + '0';
}

/**
 * Producing random number at range of string
 * @return random of length string
 */
int GA::random()
{
	return rand() % countChromosome();
}

/**
 * One of operators of Genetic Algorithm. In addition of common behavior,
 * it has a new feature: not allocating at range of initial sub-chromosome.
 * it prevents to modify bits at that.
 */
void GA::mutation()
{
	for(int i = 0; i < population.size(); i++){
		std::string c = population[i];
		for (int j = 0; j < countChromosome(); j++) {
			double r = random() / (double)countChromosome();
			if (j < Position() || j >= ( Position() + InitChromosome().length() ) && r < ProbabilityMutation()) {
				int m = random();
				c[m] = c[m] == '0' ? '1' : '0';
				population[i] = c;
			}
		}
	}
}


void GA::InitChromosome(std::string ic){
	initChromosome = ic;
}

std::string GA::InitChromosome() const {
	return initChromosome;
}

void GA::Position(size_t pos){
	position = pos;
	return;
}

size_t GA::Position() const{
	return position;
}

/**
 * It is one of operators of Genetic Algorithms it allows swap value of 2 chromosomes at cutting of random
 */
void GA::crossover()
{
	for(int i = 0; i < population.size(); i++){
		double r = random() / (double)countChromosome();
		if (i < Position() || i >= ( Position() + InitChromosome().length() ) && r < ProbabilityCrossover()) {
			int i1 = selectRandomIndex();
			int i2 = selectRandomIndex();
			std::string c1 = population[i1],
				c2 = population[i2];
			int m = random();
			std::string tc1 = c1.substr(m);
			std::string tc2 = c2.substr(m);
			c1.replace(m, c1.length() - m, tc2);
			c2.replace(m, c2.length() - m, tc1);
			population[i1] = c1;
			population[i2] = c2;
		}
	}
}

/**
 * Selecting random index from population list
 * @return index
 */
int GA::selectRandomIndex(){
	return rand() % population.size();
}

int GA::countChromosome()
{
	double sum = 0;
	for(int j = 0; j < domain.size(); j++)
		sum += countSubChromosome(j);
	return (int)sum;
}

double GA::countSubChromosome(int i)
{
	return ceil(log((domain[i][1] - domain[i][0]) * pow(10.0, radix)) / log(2.0));
}

long int GA::string2decimal(std::string c)
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

double GA::splitObject(std::string c, int n)
{
	int ma = 0;
	for(int i = 0; i < n; i++)
		ma += countSubChromosome(i);
	int mb = countSubChromosome(n);
	return binary2decimal(c.substr(ma, mb), domain[n][0], domain[n][1]);
}

double GA::binary2decimal(std::string c, double a, double b)
{
	return a + string2decimal(c) * ( b - a ) / ( pow(2, c.length() ) - 1 );
}

std::vector<double> GA::createArguments(std::string s){
	std::vector<double> x;
	for(int i = 0; i < domain.size(); i++)
		x.push_back(splitObject(s, i));
	return x;
}

std::vector<std::string> GA::generationPopulation(){
	for(int i = 0; i < CountPopulation(); i++)
    {
        std::string s(countChromosome(), '0');
        generationChromosome(s);
		population.push_back(s);
    }
	return population;
}

std::vector<double> GA::Probability(){
	std::vector<double> p;
	double sum = 0;
	for (int i = 0; i < population.size(); i++) {
		std::vector<double> args = createArguments(population[i]);
		p.push_back(callback(args));
		sum += p[i];
	}
	for(int i = 0; i < population.size(); i++){
		p[i] /= sum;
	}
	return p;
}

std::vector<double> GA::CumulativeProbability(){
	std::vector<double> q, p = Probability();
	for(int i = 0; i < population.size(); i++){
		q.push_back(0.0);
		for(int j = i; j <= i; j++){
			q[i] += p[j];
		}
	}
	return q;
}

void GA::selection(){
	std::vector<double> q = CumulativeProbability();
	std::vector<std::string> s;
	for (int i = 0; i < population.size(); i++) {
		double r = random() / (double)countChromosome();
		if (r < q[0]) s.push_back(population[0]);
		for (int j = 0; j < q.size() - 1; j++) {
			if (r >= q[j]) {
				s.push_back(population[ j + 1 ]);
				break;
			}
		}
	}
}

/**
 * Processing of evaluating fittness chromosome level with selection, mutation and crossover.
 * @return maximum value of chromosome at domain-based
 */
double GA::eval()
{
	generationPopulation();
	for(int i = 0; i < CountGeneration(); i++){
		selection();
		mutation();
		crossover();
	}
	return maximumSignal();
}

double GA::maximumSignal(){
	std::vector<double> args = createArguments(population[0]);
	double maxSignal = callback(args);
	for(int i = 1; i < CountPopulation(); i++){
		args = createArguments(population[i]);
		double signal = callback(args);
		if(signal > maxSignal)
			maxSignal = signal;
	}
	return maxSignal;
}

GA::~GA() {}
