#ifndef GENE_H
#define GENE_H

#include <vector>
#include <utility>

class Gene {
private:
    int geneId;
    std::vector<std::pair<Gene*, int>> adjList;

public:
    Gene();
    Gene(int geneId);

    int getId() const;
    std::vector<std::pair<Gene*, int>> getAdjList() const;
    void addAdjacent(Gene* gene, int type);

    bool operator==(const Gene& other) const;
    bool operator<(const Gene& other) const;
};

#endif
