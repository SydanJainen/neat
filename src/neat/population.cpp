#include "neat/population.h"
#include <cmath>
#include <algorithm>

Population::Population(NeatConfig config, Rng &rng) : config(config), rng(rng) {
    for (int i = 0; i < config.population_size; i++) {
        individuals.emplace_back(new_genome(), nullptr);
    }
}

Genome Population::new_genome() {
    Genome genome{ Genome::get_next_genome_id(), config.num_inputs, config.num_outputs};
    for (int neuron_id = 0; neuron_id < config.num_outputs; neuron_id++) {
        genome.add_neuron(NeuronGene(neuron_id, 0.0, Activation(sigmoid)));
    }
    // Fully connect feed forward
    for (int input_id = 0; input_id < config.num_inputs; input_id++) {
        for (int output_id = config.num_inputs; output_id < config.num_inputs + config.num_outputs; output_id++) {
            genome.add_link(LinkGene(LinkId(input_id, output_id), 1.0, true));
        }
    }
    return genome;
}

std::vector<Individual> Population::reproduce() {
    //std::vector<Individual> old_members = sort_individuals_by_fitness(individuals);
    //int reproduction_cutoff = std::ceil(config.survival_threshold * old_members.size());
    std::vector<Individual> new_generation;
    /*
    int spawn_size = individuals.size();  // Assuming spawn size is the size of the original population
    while (spawn_size-- > 0) {
        const auto& p1 = *rng.choose_randomly(old_members.begin(), old_members.begin() + reproduction_cutoff);
        const auto& p2 = *rng.choose_randomly(old_members.begin(), old_members.begin() + reproduction_cutoff);
        Genome offspring = crossover(p1.genome, p2.genome);
        mutate(offspring);
        new_generation.emplace_back(offspring, nullptr); //change with kfitnessnotcomputed
    }*/
    return new_generation;
}

// The method update_best needs to be defined if it's mentioned.
