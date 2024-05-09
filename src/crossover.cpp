#include "../include/crossover.h";
#include <cstdlib> // For rand()

NeuronGene crossover_neuron(const NeuronGene& first, const NeuronGene& second) {
    int neuron_id = first.neuron_id;
    double bias = (rand() % 2) ? first.bias : second.bias;
    Activation activation = (rand() % 2) ? first.activation : second.activation;
    return NeuronGene(neuron_id, bias, activation, first.type);
}

LinkGene crossover_link(const LinkGene& first, const LinkGene& second) {
    LinkId link_id = first.link_id;
    double weight = (rand() % 2) ? first.weight : second.weight;
    bool is_enabled = (rand() % 2) ? first.is_enabled : second.is_enabled;
    return LinkGene(link_id, weight, is_enabled);
}

Genome crossover(const Individual& dominant, const Individual& recessive) {
    extern int m_genome_indexer; // Assuming this variable is declared globally elsewhere
    Genome offspring(m_genome_indexer++, dominant.genome.num_inputs, dominant.genome.num_outputs);
    for (const NeuronGene& neuron : dominant.genome.neurons) {
        std::optional<NeuronGene> recessive_neuron = recessive.genome.get_neuron(neuron.neuron_id);
        if (!recessive_neuron.has_value()) {
            offspring.add_neuron(neuron);
        } else {
            offspring.add_neuron(crossover_neuron(neuron, *recessive_neuron));
        }
    }
    for (const LinkGene& link : dominant.genome.links) {
        std::optional<LinkGene> recessive_link = recessive.genome.get_link(link.link_id.input_id, link.link_id.output_id);
        if (!recessive_link.has_value()) {
            offspring.add_link(link);
        } else {
            offspring.add_link(crossover_link(link, *recessive_link));
        }
    }
    return offspring;
}
