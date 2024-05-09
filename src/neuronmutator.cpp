#include "../include/neuronmutator.h"
#include "../include/activation.h"
#include <stdexcept>
#include <cstdlib> // For rand(), RAND_MAX
#include <optional>


NeuronGene NeuronMutator::new_neuron(NeuronType type) {
    Activation activation(choose_random_activation(), std::nullopt);

    if (activation.derivative_function) {
        activation.derivative_function = *activation.derivative_function;
    } else {
        throw std::runtime_error("Derivative not available for chosen activation function");
    }

    double bias = get_random_bias();
    return NeuronGene(0, bias, activation, type); // change neuron ID
}

std::function<double(double)> NeuronMutator::choose_random_activation() {
    std::vector<std::function<double(double)>> choices = {
        sigmoid, 
        relu
    };

    int random_index = rand() % choices.size();
    return choices[random_index];
}

double NeuronMutator::get_random_bias() {
    return (rand() / (double)RAND_MAX) * 2.0 - 1.0; // Random bias between -1 and 1
}
