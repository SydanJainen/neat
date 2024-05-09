#include <iostream>
#include "neat/genome.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    //Population population {meat_config, rng};
    //ComputeFitnessFn compute_fitness{rng};
    //auto winner = population.run(compute_fitness, num_generations);
    //save(winner.genome, winner_filename);
    int id = 0;
    Genome genome = Genome(id, 2, 1, 0);
    return 0;
}