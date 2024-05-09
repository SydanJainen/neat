#include "../include/genome.h"

Genome::Genome(int id, int num_inputs, int num_outputs, int num_hidden) : genome_id(id) {
    //let make each id unique
    for (int i = 0; i < num_inputs; ++i) {
        input_ids.push_back(i);
    }
    for (int i = 0; i < num_outputs; ++i) {
        output_ids.push_back(num_inputs + i);
    }
    for (int i = 0; i < num_hidden; ++i) {
        hidden_ids.push_back(num_inputs + num_outputs + i);
    }
}

const std::vector<LinkGene>& Genome::get_links() const {
    return links;
}

std::vector<int> Genome::make_inputs_ids() const {
    return input_ids; 
}

std::vector<int> Genome::make_outputs_ids() const {
    return output_ids; 
}

std::vector<int> Genome::make_hidden_ids() const {
    return hidden_ids; 
}


void Genome::add_neuron(const NeuronGene& neuron) {
    neurons.push_back(neuron);
}

std::optional<NeuronGene> Genome::find_neuron(int id) const {
    for (const NeuronGene& neuron : neurons) {
        if (neuron.neuron_id == id) {
            return neuron;
        }
    }
    return std::nullopt;
}

std::vector<NeuronGene> Genome::get_neurons_of_type(NeuronType type) const {
    std::vector<NeuronGene> filtered_neurons;
    for (const NeuronGene& neuron : neurons) {
        if (neuron.type == type) {
            filtered_neurons.push_back(neuron);
        }
    }
    return filtered_neurons;
}

std::optional<LinkGene> Genome::get_link(int input_id, int output_id) const {
    for (const auto& link : links) {
        if (link.link_id.input_id == input_id && link.link_id.output_id == output_id) {
            return link; // Link found
        }
    }
    return std::nullopt; // No link found
}

