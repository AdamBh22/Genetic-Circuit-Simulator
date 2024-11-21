#include <gtest/gtest.h>
#include "GeneticCircuit.h"

TEST(GeneticCircuitTest, AddGene) {
    GeneticCircuit circuit;
    circuit.addGene(1);
    EXPECT_EQ(circuit.numberOfGenes(), 1);
}

TEST(GeneticCircuitTest, AddEdge) {
    GeneticCircuit circuit;
    circuit.addGene(1);
    circuit.addGene(2);
    circuit.addEdge(1, 2, 1);

    Gene* gene1 = circuit.getGeneById(1);
    auto adjList = gene1->getAdjList();
    EXPECT_EQ(adjList.size(), 1);
    EXPECT_EQ(adjList[0].first->getId(), 2);
}
