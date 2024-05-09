cmake_minimum_required(VERSION 3.10)
project(neat VERSION 1.0.0 DESCRIPTION "Genetic Algorithm NN library" LANGUAGES C CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_INSTALL_INCLUDEDIR include)
set(CMAKE_INSTALL_BINDIR bin)
set(CMAKE_INSTALL_LIBDIR lib)

set(HEADER_FILES
    neat/activation.h
    neat/genome.h
    neat/link.h
    neat/neurongene.h
)
    #neat/crossover.h
    #neat/individual.h
    #neat/feedforwardneuralnetwork.h
    #neat/fitnessfn.h
    #neat/linkmutator.h
    #neat/neatconfig.h
    #neat/neuron.h
    #neat/neuroninput.h
    #neat/neuronmutator.h
    #neat/population.h
    #neat/rng.h

set(SOURCE_FILES
    activation.cpp
    genome.cpp
)
    #crossover.cpp
    #feedforwardneuralnetwork.cpp
    #linkmutator.cpp
    #neuronmutator.cpp
    #population.cpp

add_library(neat STATIC SHARED ${SOURCE_FILES})

configure_file(cmake/neat.pc.in cmake/neat.pc @ONLY)

install(TARGETS neat DESTINATION bin)
install(TARGETS neat DESTINATION lib)
install(FILES ${CMAKE_BINARY_DIR}/src/neat/cmake/neat.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

    
