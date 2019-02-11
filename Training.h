#include <vector>
#include "GA.h"

class Training: public GA {
    std::vector<int> setGeneration;
    std::vector<double> setCrossover;
    std::vector<double> setMutation;
public:
    Training(double d[][2], size_t drow, int sg[], size_t csg, double spc[], size_t cspc, double spm[], size_t cspm, int rdx = 0, int cp = 10, int cg = 100, double pm = 0.05, double pc = 0.2, double (*pf)(std::vector<double> a) = 0, std::string ic = "", size_t pos = 0);
    void evalTrain();
    void SetGeneration(int g);
    void SetCrossover(double pc);
    void SetMutation(double pm);
    ~Training();
};
