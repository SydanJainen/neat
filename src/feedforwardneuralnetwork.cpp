#include "../include/feedforwardneuralnetwork.h"
#include <cmath>  // For activation functions, if necessary
#include <vector>
#include <unordered_set>

FeedForwardNeuralNetwork::FeedForwardNeuralNetwork(std::vector<int> input_ids, std::vector<int> output_ids, std::vector<Neuron> neurons) : input_ids(std::move(input_ids)), output_ids(std::move(output_ids)), neurons(std::move(neurons)) {}

std::vector<double> FeedForwardNeuralNetwork::activate(const std::vector<double> &inputs) {
    std::unordered_map<int, double> values;
    for (size_t i = 0; i < inputs.size(); ++i) {
        values[input_ids[i]] = inputs[i];
    }
    for (int neuron_id : output_ids) {
        values[neuron_id] = 0.0; // Initialize output neurons
    }
    for (const Neuron &neuron : neurons) {
        double sum = 0.0;
        for (const NeuronInput &input : neuron.inputs) {
            sum += input.weight * values.at(input.input_id);
        }
        sum += neuron.bias;
        sum = neuron.activation.activation_function(sum);
        values[neuron.neuron_id] = sum;
    }
    std::vector<double> outputs;
    for (int neuron_id : output_ids) {
        outputs.push_back(values[neuron_id]);
    }
    return outputs;
}

std::vector<std::vector<int>> FeedForwardNeuralNetwork::feed_forward_layers(const std::vector<int>& inputs, const std::vector<int>& outputs, const std::vector<LinkGene>& links) {
    std::vector<std::vector<int>> layers;
    std::unordered_set<int> processed(inputs.begin(), inputs.end());
    std::vector<int> current_layer = inputs;

    while (!current_layer.empty()) {
        std::vector<int> next_layer;
        for (int neuron : current_layer) {
            for (const LinkGene& link : links) {
                if (link.link_id.input_id == neuron && processed.find(link.link_id.output_id) == processed.end() && std::find(outputs.begin(), outputs.end(), link.link_id.output_id) == outputs.end()) {
                    next_layer.push_back(link.link_id.output_id);
                    processed.insert(link.link_id.output_id);
                }
            }
        }
        if (!next_layer.empty()) {
            layers.push_back(next_layer);
        }
        current_layer = next_layer;
    }

    if (!outputs.empty()) {
        layers.push_back(outputs);
    }

    return layers;
}


FeedForwardNeuralNetwork FeedForwardNeuralNetwork::create_from_genome(const Genome &genome) {
    std::vector<int> inputs = genome.make_inputs_ids();
    std::vector<int> outputs = genome.make_outputs_ids();
    std::vector<std::vector<int>> layers = feed_forward_layers(inputs, outputs, genome.get_links());

    std::vector<Neuron> neurons;
    for (const auto &layer : layers) {
        for (int neuron_id : layer) {
            std::vector<NeuronInput> neuron_inputs;
            for (const auto &link : genome.get_links()) {
                if (neuron_id == link.link_id.output_id) {
                    neuron_inputs.emplace_back(NeuronInput{link.link_id.input_id, link.weight});
                }
            }
            auto neuron_gene_opt = genome.find_neuron(neuron_id);
            if (neuron_gene_opt.has_value()) {
                Activation activation([](double x) { return sigmoid(x); }); 
                neurons.emplace_back(Neuron(neuron_gene_opt->neuron_id, neuron_gene_opt->bias, activation, std::move(neuron_inputs)));
            }

        }
    }
    return FeedForwardNeuralNetwork{std::move(inputs), std::move(outputs), std::move(neurons)};
}
