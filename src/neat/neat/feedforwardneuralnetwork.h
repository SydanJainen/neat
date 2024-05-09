#pragma once

#include <vector>
#include <unordered_map>
#include "neuron.h"
#include "genome.h"

class FeedForwardNeuralNetwork {
public:
    static std::vector<std::vector<int>> feed_forward_layers(const std::vector<int>& inputs, const std::vector<int>& outputs, const std::vector<LinkGene>& links);
    static FeedForwardNeuralNetwork create_from_genome(const Genome &genome);
    std::vector<double> activate(const std::vector<double> &inputs);
    FeedForwardNeuralNetwork(std::vector<int> input_ids, std::vector<int> output_ids, std::vector<Neuron> neurons);
private:
    std::vector<int> input_ids;
    std::vector<int> output_ids;
    std::vector<Neuron> neurons;
};

