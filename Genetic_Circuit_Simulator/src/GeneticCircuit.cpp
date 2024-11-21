#include "GeneticCircuit.h"

GeneticCircuit::GeneticCircuit() : genes({}) {}

GeneticCircuit::~GeneticCircuit() {
    for (Gene* gene : genes) {
        delete gene;
    }
}

void GeneticCircuit::addGene(int geneId) {
    genes.push_back(new Gene(geneId));
}

void GeneticCircuit::addEdge(int sourceId, int targetId, int type) {
    Gene* source = getGeneById(sourceId);
    Gene* target = getGeneById(targetId);
    if (source && target) {
        source->addAdjacent(target, type);
    }
}

int GeneticCircuit::numberOfGenes() const {
    return genes.size();
}

Gene* GeneticCircuit::getGeneById(int geneId) const {
    for (Gene* gene : genes) {
        if (gene->getId() == geneId) {
            return gene;
        }
    }
    return nullptr;
}

const std::vector<Gene*>& GeneticCircuit::getGenes() const {
    return genes;
}
