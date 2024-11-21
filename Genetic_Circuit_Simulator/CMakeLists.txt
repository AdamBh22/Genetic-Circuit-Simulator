cmake_minimum_required(VERSION 3.10)
project(GeneticCircuit)

set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(include)

# Add source files
set(SOURCES
        src/main.cpp
        src/Gene.cpp
        src/GeneticCircuit.cpp
        src/CycleDetector.cpp
)

# Create the main executable
add_executable(GeneticCircuit ${SOURCES})

# Enable testing
enable_testing()

# Add test files
add_executable(runTests
        tests/test_CycleDetector.cpp
        tests/test_Gene.cpp
        tests/test_GeneticCircuit.cpp
        src/main.cpp
        src/Gene.cpp
        src/GeneticCircuit.cpp
        src/CycleDetector.cpp
)

# Find Google Test package
find_package(GTest REQUIRED)

# Link GoogleTest to the test executable
target_link_libraries(runTests GTest::GTest GTest::Main)

# Register the tests with CTest
add_test(NAME GeneticCircuitTests COMMAND runTests)
