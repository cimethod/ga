#include <vector>
#include "GA.h"

class Training: public GA {
    std::vector<int> setGeneration;
    std::vector<double> setCrossover;
    std::vector<double> setMutation;
public:
    Training(double d[][2], size_t drow,
        int sg[], size_t csg,
        double spc[], size_t cspc,
        double spm[], size_t cspm
    );
    void eval();
    void SetGeneration(int g);
    void SetCrossover(double pc);
    void SetMutation(double pm);
    ~Training();
};
