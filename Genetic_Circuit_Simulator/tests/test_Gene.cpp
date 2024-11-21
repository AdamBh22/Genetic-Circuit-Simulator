#include <gtest/gtest.h>
#include "Gene.h"

TEST(GeneTest, ConstructorAndGetId) {
    Gene gene(1);
    EXPECT_EQ(gene.getId(), 1);
}

TEST(GeneTest, AddAdjacentGene) {
    Gene gene1(1);
    Gene gene2(2);
    gene1.addAdjacent(&gene2, 1);

    auto adjList = gene1.getAdjList();
    EXPECT_EQ(adjList.size(), 1);
    EXPECT_EQ(adjList[0].first->getId(), 2);
}

TEST(GeneTest, OperatorEquality) {
    Gene gene1(1);
    Gene gene2(1);
    EXPECT_TRUE(gene1 == gene2);

    Gene gene3(2);
    EXPECT_FALSE(gene1 == gene3);
}

TEST(GeneTest, OperatorLessThan) {
    Gene gene1(1);
    Gene gene2(2);
    EXPECT_TRUE(gene1 < gene2);
    EXPECT_FALSE(gene2 < gene1);
}
