#include <iostream>

int main()
{
    std::cout << "Hello world!" << std::endl;
    Population population {meat_config, rng};
    ComputeFitnessFn compute_fitness{rng};
    auto winner = population.run(compute_fitness, num_generations);
    save(winner.genome, winner_filename);
    return 0;
}

// protobuf to serialize genome in order to make usable for other program