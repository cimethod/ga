#include "Training.h"

Training::Training(double d[][2], size_t drow, int sg[], int csg, double spc[], int cspc, double spm[], int cspm, int rdx , int cp, int cg, double pm, double pc, double (*pf)(std::vector<double> a), std::string ic, size_t pos)
{
    GA(d, drow, rdx, cp, cg, pm, pc, pf, ic, pos);
    for(int i = 0; i < csg; i++)
        setGeneration.push_back(sg[i]);
    for(int i = 0; i < cspc; i++)
        setCrossover.push_back(spc[i]);
    for(int i = 0; i < cspm; i++)
        setMutation.push_back(spm[i]);
}

void Training::evalTrain(){
    for (int i = 0; i < setGeneration.size(); i++) {
        for (int j = 0; j < setCrossover.size(); j++) {
            for (int k = 0; k < setMutation.size(); k++) {
                CountGeneration(setGeneration[i]);
                ProbabilityCrossover(setCrossover[j]);
                ProbabilityMutation(setMutation[k]);
                double e = eval();
            }
        }
    }
}

void Training::SetCrossover(double pc){
    setCrossover.push_back(pc);
}

void Training::SetGeneration(int g){
    setGeneration.push_back(g);
}

void Training::SetMutation(double pm){
    setMutation.push_back(pm);
}

Training::~Training(){

}
