# Genetic Circuit Simulator

## Description

The Genetic Circuit Simulator is a tool designed to simulate and detect cycles in genetic circuits. It models genes as nodes in a graph and edges between genes that represent interactions with different types. The tool uses depth-first search (DFS) to detect negative cycles, which are significant in genetic circuits as they might indicate undesired behaviors.

## Features

- **Gene Representation**: Genes are modeled as nodes in a directed graph, where each gene has a unique ID. Interactions between genes are represented as directed edges with associated types.

- **Graph Theory Basis**: The simulator uses concepts from graph theory to represent genetic circuits. Nodes (genes) and directed edges (interactions) form a graph structure. The problem of detecting negative cycles in the circuit translates into finding specific substructures in the graph where the cumulative "type difference" leads to undesirable behavior.

- **Cycle Detection**: The simulator employs a depth-first search (DFS)-based algorithm to traverse the graph and detect negative cycles. Negative cycles are identified by tracking the difference between two types of interactions along paths.

- **Adjacency List**: Each gene maintains an adjacency list that records its outgoing edges. Each edge points to a connected gene and includes a type identifier, which the algorithm uses to compute type balances during traversal.

- **Algorithm Description**: The cycle detection algorithm:
  1. Initializes a `visited` map and tracks the parent of each node for cycle reconstruction.
  2. Traverses the graph using DFS, maintaining counts of the two interaction types (`type1` and `type2`) along the traversal path.
  3. Checks for back edges during DFS. If a back edge is encountered, it verifies whether the cumulative difference in interaction types (`type2 - type1`) satisfies the negative cycle condition.
  4. If a negative cycle is detected, it reconstructs the cycle using the parent map and outputs the sequence of genes forming the cycle.

This approach ensures efficient detection of cycles and provides clear insight into the graph structure and interaction patterns within genetic circuits.


## How to Use

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/AdamBh22/Genetic-Circuit-Simulator.git
    cd GeneticCircuit
    ```

2. **Build the Project**:
    To compile the project, you need to have CMake installed. After cloning the repository, navigate to the project folder and run the following commands:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Program**:
    Once the project is built, you can run the executable:
    ```bash
    ./GeneticCircuit
    ```

    The program will prompt you to enter the number of genes and edges, followed by the gene interactions.

4. **Run Unit Tests** (Optional):
    To run the unit tests for the project:
    ```bash
    make runTests
    ```

## Example

**Input:**  and **Output**
  ```bash
  4 4
  1 2 1  
  2 3 1
  3 4 2
  4 1 2

Warning: a negative cycle detected in the genes: 1 2 3 4 1
