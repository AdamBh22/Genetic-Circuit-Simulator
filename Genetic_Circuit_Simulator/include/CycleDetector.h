#ifndef CYCLE_DETECTOR_H
#define CYCLE_DETECTOR_H

#include "Gene.h"
#include "GeneticCircuit.h"
#include <map>
#include <vector>

class CycleDetector {
private:
    std::map<Gene*, Gene*> parent;
    std::map<Gene*, int> visited, count1, count2;
    std::vector<Gene*> cycle;
    Gene* startingGene = nullptr;

    void CycleDetectorInitializer();
    bool dfs(Gene* currentGene, int number1, int number2);

public:
    void DetectCycle(const GeneticCircuit& geneticCircuit);
    const std::vector<Gene*>& getCycle() const;
};

#endif
