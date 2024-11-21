# Genetic Circuit Simulator

## Description

The Genetic Circuit Simulator is a tool designed to simulate and detect cycles in genetic circuits. It models genes as nodes in a graph and edges between genes that represent interactions with different types. The tool uses depth-first search (DFS) to detect negative cycles, which are significant in genetic circuits as they might indicate undesired behaviors.

## Features

- **Gene Representation**: Genes are modeled as nodes with unique IDs and can have directed edges representing interactions.
- **Cycle Detection**: The simulator can detect negative cycles in the gene network using DFS.
- **Adjacency List**: Each gene has an adjacency list representing other genes it interacts with and the type of interaction.

## How to Use

1. **Clone the Repository**:
    ```bash
    git clone <repository_url>
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

Warning: a negative cycle detected in the genes: 1 2 3 4
