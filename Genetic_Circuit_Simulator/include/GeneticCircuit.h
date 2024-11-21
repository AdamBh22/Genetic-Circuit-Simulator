#ifndef GENETIC_CIRCUIT_H
#define GENETIC_CIRCUIT_H

#include "Gene.h"
#include <vector>

class GeneticCircuit {
private:
    std::vector<Gene*> genes;

public:
    GeneticCircuit();
    ~GeneticCircuit();

    void addGene(int geneId);
    void addEdge(int sourceId, int targetId, int type);

    int numberOfGenes() const;
    Gene* getGeneById(int geneId) const;
    const std::vector<Gene*>& getGenes() const;
};

#endif
