#include <gtest/gtest.h>
#include "CycleDetector.h"
#include "GeneticCircuit.h"

TEST(CycleDetectorTest, DetectCycle) {
    GeneticCircuit circuit;
    circuit.addGene(1);
    circuit.addGene(2);
    circuit.addGene(3);
    circuit.addEdge(1, 2, 1);
    circuit.addEdge(2, 3, 2);
    circuit.addEdge(3, 1, 2);

    CycleDetector detector;
    detector.DetectCycle(circuit);

    const std::vector<Gene*>& cycle = detector.getCycle();
    EXPECT_EQ(cycle.size(), 4); 
}

TEST(CycleDetectorTest, NoCycleDetected) {
    GeneticCircuit circuit;
    circuit.addGene(1);
    circuit.addGene(2);
    circuit.addEdge(1, 2, 1);

    CycleDetector detector;
    detector.DetectCycle(circuit);

    const std::vector<Gene*>& cycle = detector.getCycle();
    EXPECT_EQ(cycle.size(), 0); 
}