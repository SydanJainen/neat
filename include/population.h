#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include "Individual.h"
#include "neatconfig.h"
#include "rng.h"
#include "fitnessFn.h" 

class Population {
public:
    Population(NeatConfig config, Rng &rng);
    
    template<typename FitnessT>
    Individual run(FitnessFn<FitnessT> compute_fitness, int num_generations);

private:
    std::vector<Individual> individuals;
    NeatConfig config;
    Rng &rng;

    Genome new_genome();
    std::vector<Individual> reproduce();
    void update_best();  // Assumes definition is available or to be implemented
};

#include "../src/population.tpp"  // For template implementation

#endif // POPULATION_H
