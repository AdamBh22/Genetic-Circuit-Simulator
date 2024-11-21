#include "GeneticCircuit.h"
#include "CycleDetector.h"
#include <iostream>

int main() {
    int numberGenes, numberEdges;
    std::cin >> numberGenes >> numberEdges;

    GeneticCircuit geneticCircuit;

    for (int i = 1; i <= numberGenes; i++) {
        geneticCircuit.addGene(i);
    }

    for (int i = 1; i <= numberEdges; i++) {
        int geneId1, geneId2, type;
        std::cin >> geneId1 >> geneId2 >> type;
        geneticCircuit.addEdge(geneId1, geneId2, type);
    }

    CycleDetector detector;
    detector.DetectCycle(geneticCircuit);

    const std::vector<Gene*>& cycle = detector.getCycle();
    if (!cycle.empty()) {
        std::cout << "Warning: a negative cycle detected in the genes: ";
        for (Gene* gene : cycle) {
            std::cout << gene->getId() << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No negative cycle detected: considered as a positive genetic circuit." << std::endl;
    }

    return 0;
}
