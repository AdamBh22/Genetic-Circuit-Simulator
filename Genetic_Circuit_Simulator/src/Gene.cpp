#include "Gene.h"

Gene::Gene() : geneId(0), adjList({}) {}

Gene::Gene(int geneId) : geneId(geneId), adjList({}) {}

int Gene::getId() const {
    return geneId;
}

std::vector<std::pair<Gene*, int>> Gene::getAdjList() const {
    return adjList;
}

void Gene::addAdjacent(Gene* gene, int type) {
    adjList.push_back({gene, type});
}

bool Gene::operator==(const Gene& other) const {
    return geneId == other.geneId;
}

bool Gene::operator<(const Gene& other) const {
    return this->geneId < other.geneId;
}
