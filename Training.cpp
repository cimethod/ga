#include "Training.h"

Training::Training(double d[][2], size_t drow,
    int sg[], size_t csg,
    double spc[], size_t cspc,
    double spm[], size_t cspm
): GA(d, drow) {
    for(int i = 0; i < csg; i++)
        setGeneration.push_back(sg[i]);
    for(int i = 0; i < cspc; i++)
        setCrossover.push_back(spc[i]);
    for(int i = 0; i < cspm; i++)
        setMutation.push_back(spm[i]);
}

void Training::evalTrain(){
    std::cout << "Enter Ctrl+C to terminal\n" << std::endl;
    for (int i = 0; i < setGeneration.size(); i++) {
        for (int j = 0; j < setCrossover.size(); j++) {
            for (int k = 0; k < setMutation.size(); k++) {
                CountGeneration(setGeneration[i]);
                ProbabilityCrossover(setCrossover[j]);
                ProbabilityMutation(setMutation[k]);
                std::cout << eval() << std::endl;
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

Training::~Training(){}
