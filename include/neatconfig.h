#ifndef NEAT_CONFIG_H
#define NEAT_CONFIG_H

struct NeatConfig {
    int population_size;
    int num_inputs;
    int num_outputs;
    double survival_threshold; // Proportion of population allowed to reproduce

    NeatConfig(int populationSize, int inputs, int outputs, double survivalThreshold)
        : population_size(populationSize), num_inputs(inputs), num_outputs(outputs), survival_threshold(survivalThreshold) {}
};

#endif // NEAT_CONFIG_H
