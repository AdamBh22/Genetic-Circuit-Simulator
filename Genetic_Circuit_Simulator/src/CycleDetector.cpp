#include "CycleDetector.h"
#include <algorithm>

void CycleDetector::CycleDetectorInitializer() {
    visited.clear();
    cycle.clear();
    startingGene = nullptr;
}

bool CycleDetector::dfs(Gene* currentGene, int number1, int number2) {
    visited[currentGene] = 1;
    count1[currentGene] = number1;
    count2[currentGene] = number2;

    const std::vector<std::pair<Gene*, int>>& adjList = currentGene->getAdjList();
    bool cycleDetected = false;

    for (const auto& element : adjList) {
        Gene* gene = element.first;
        int type = element.second;
        int numberGene1 = number1;
        int numberGene2 = number2;
        parent[gene] = currentGene;

        if (type == 1)
            numberGene1++;
        else
            numberGene2++;

        if (visited[gene] == 1 && numberGene2 - count2[gene] >= numberGene1 - count1[gene]) {
            startingGene = gene;
            return true;
        } else if (visited[gene] == 0) {
            cycleDetected |= dfs(gene, numberGene1, numberGene2);
        }
    }
    return cycleDetected;
}

void CycleDetector::DetectCycle(const GeneticCircuit& geneticCircuit) {
    const std::vector<Gene*>& genes = geneticCircuit.getGenes();
    bool cycleFound = false;
    CycleDetectorInitializer();

    for (Gene* gene : genes) {
        parent[gene] = gene;
    }

    for (Gene* gene : genes) {
        if (!visited[gene]) {
            if (dfs(gene, 0, 0)) {
                cycleFound = true;
                break;
            }
        }
    }

    if (cycleFound) {
        for (size_t i = 0; i < genes.size(); i++) {
            startingGene = parent[startingGene];
        }
        cycle.push_back(startingGene);
        Gene* gene = parent[startingGene];
        while (gene != startingGene) {
            cycle.push_back(gene);
            gene = parent[gene];
        }
        cycle.push_back(gene);
        std::reverse(cycle.begin(), cycle.end());
    }
}

const std::vector<Gene*>& CycleDetector::getCycle() const {
    return cycle;
}
