cmake_minimum_required(VERSION 3.10)
project(GeneticCircuit)

set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(include)

# Add source files
set(SOURCES
    src/Gene.cpp
    src/GeneticCircuit.cpp
    src/CycleDetector.cpp
)

# Create the main executable
add_executable(GeneticCircuit src/main.cpp ${SOURCES})

# Enable testing
enable_testing()

# Add test executable
add_executable(runTests
    tests/test_CycleDetector.cpp
    tests/test_Gene.cpp
    tests/test_GeneticCircuit.cpp
    ${SOURCES} # Add source files except `main.cpp`
)

# Link GoogleTest to the test executable
find_package(GTest REQUIRED)
target_link_libraries(runTests GTest::GTest GTest::Main)
